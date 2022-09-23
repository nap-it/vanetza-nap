

/*

NL80211 and LibNL application adapted from https://github.com/Alamot/code-snippets/blob/master/nl80211_info/nl80211_info.c and IW source code.

It collects and dumps some information about nearby AP's.

libnl3 is required.

TO COMPILE: gcc -Wall RSSI_Discovery.c -o RSSI_Discovery -I/usr/include/libnl3 -lnl-genl-3 -lnl-3 -std=c99 -lpthread

*/

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <netlink/netlink.h>    //lots of netlink functions
#include <netlink/genl/genl.h>  //genl_connect, genlmsg_put
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>  //genl_ctrl_resolve
#include <linux/nl80211.h>      //NL80211 definitions

//
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
//

#define ETH_ALEN 6

typedef struct {
  int id;
  struct nl_sock* socket;
  struct nl_cb* cb1,* cb2;
  int result1, result2;
} Netlink;

typedef struct {
  char ifname[30];
  u_int32_t inac_time;
  int ifindex;
  int signal;
  float txrate;
  char mac_address[20];
  u_int32_t i_throughput;
  u_int32_t d_throughput;


} Neighbour;

struct thread_arg_struct {
    int socket;
    unsigned int port;
};

typedef struct {
  char mac[18];
  char ip[16];
} RSU;

struct sockaddr_in serv_addr;

int stations_num = 0;
char req_buff[1024];
int client = 0;
int reqlen = 0;
Netlink nl;
Neighbour w;

static struct nla_policy stats_policy[NL80211_STA_INFO_MAX + 1] = {
  [NL80211_STA_INFO_INACTIVE_TIME] = { .type = NLA_U32 },
  [NL80211_STA_INFO_RX_BYTES] = { .type = NLA_U32 },
  [NL80211_STA_INFO_TX_BYTES] = { .type = NLA_U32 },
  [NL80211_STA_INFO_RX_PACKETS] = { .type = NLA_U32 },
  [NL80211_STA_INFO_TX_PACKETS] = { .type = NLA_U32 },
  [NL80211_STA_INFO_SIGNAL] = { .type = NLA_U8 },
  [NL80211_STA_INFO_TX_BITRATE] = { .type = NLA_NESTED },
  [NL80211_STA_INFO_LLID] = { .type = NLA_U16 },
  [NL80211_STA_INFO_PLID] = { .type = NLA_U16 },
  [NL80211_STA_INFO_PLINK_STATE] = { .type = NLA_U8 },
};

static struct nla_policy rate_policy[NL80211_RATE_INFO_MAX + 1] = {
  [NL80211_RATE_INFO_BITRATE] = { .type = NLA_U16 },
  [NL80211_RATE_INFO_MCS] = { .type = NLA_U8 },
  [NL80211_RATE_INFO_40_MHZ_WIDTH] = { .type = NLA_FLAG },
  [NL80211_RATE_INFO_SHORT_GI] = { .type = NLA_FLAG },
};


static int initNl80211(Netlink* nl, Neighbour* w);
static int finish_handler1(struct nl_msg *msg, void *arg);
static int finish_handler2(struct nl_msg *msg, void *arg);
static int getInterfaceName(struct nl_msg *msg, void *arg);
static int getNeighbourInfo_callback(struct nl_msg *msg, void *arg);
static int send_message(Netlink* nl, Neighbour* w);

void mac_addr_n2a(char *mac_addr, const unsigned char *arg)
{
	int i, l;

	l = 0;
	for (i = 0; i < ETH_ALEN ; i++) {
		if (i == 0) {
			sprintf(mac_addr+l, "%02x", arg[i]);
			l += 2;
		} else {
			sprintf(mac_addr+l, ":%02x", arg[i]);
			l += 3;
		}
	}
}



static int initNl80211(Netlink* nl, Neighbour* w) {
  nl->socket = nl_socket_alloc();
  if (!nl->socket) {
    fprintf(stderr, "Failed to allocate netlink socket.\n");
    return -ENOMEM;
  }

  nl_socket_set_buffer_size(nl->socket, 8192, 8192);

  if (genl_connect(nl->socket)) {
    fprintf(stderr, "Failed to connect to netlink socket.\n");
    nl_close(nl->socket);
    nl_socket_free(nl->socket);
    return -ENOLINK;
  }

  nl->id = genl_ctrl_resolve(nl->socket, "nl80211");
  if (nl->id< 0) {
    fprintf(stderr, "Nl80211 interface not found.\n");
    nl_close(nl->socket);
    nl_socket_free(nl->socket);
    return -ENOENT;
  }

  nl->cb1 = nl_cb_alloc(NL_CB_DEFAULT);
  nl->cb2 = nl_cb_alloc(NL_CB_DEFAULT);
  if ((!nl->cb1) || (!nl->cb2)) {
     fprintf(stderr, "Failed to allocate netlink callback.\n");
     nl_close(nl->socket);
     nl_socket_free(nl->socket);
     return ENOMEM;
  }

  nl_cb_set(nl->cb1, NL_CB_VALID , NL_CB_CUSTOM, getInterfaceName, w);
  nl_cb_set(nl->cb1, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler1, &(nl->result1));
  nl_cb_set(nl->cb2, NL_CB_VALID , NL_CB_CUSTOM, getNeighbourInfo_callback, w);
  nl_cb_set(nl->cb2, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler2, &(nl->result2));

  return nl->id;
}


static int finish_handler1(struct nl_msg *msg, void *arg) {
  int *ret = arg;
  *ret = 0;
  return NL_SKIP;
}

static int finish_handler2(struct nl_msg *msg, void *arg) {
  int *ret = arg;
  *ret = 0;

  if(stations_num == 0) {
    //printf("[sock_callback] No station found\n");
    strcpy(req_buff, "N/A\n");
    if(sendto(client, req_buff, 5, 0,
         (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
      perror("send");
    }
  }
  else {
    //printf("[sock_callback] %s", req_buff);
    if(sendto(client, req_buff, stations_num * 11, 0,
         (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
      perror("send");
    }
  }

  stations_num = 0;
  reqlen = 0;
  memset(req_buff, 0, 1024);
  return NL_SKIP;
}


static int getInterfaceName(struct nl_msg *msg, void *arg) {

  struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));

  struct nlattr *tb_msg[NL80211_ATTR_MAX + 1];

  //nl_msg_dump(msg, stdout);

  nla_parse(tb_msg,
            NL80211_ATTR_MAX,
            genlmsg_attrdata(gnlh, 0),
            genlmsg_attrlen(gnlh, 0),
            NULL);

  if (tb_msg[NL80211_ATTR_IFNAME]) {
    strcpy(((Neighbour*)arg)->ifname, nla_get_string(tb_msg[NL80211_ATTR_IFNAME]));
  }

  if (tb_msg[NL80211_ATTR_IFINDEX]) {
    ((Neighbour*)arg)->ifindex = nla_get_u32(tb_msg[NL80211_ATTR_IFINDEX]);
  }

  return NL_SKIP;
}


static int getNeighbourInfo_callback(struct nl_msg *msg, void *arg) {
  struct nlattr *tb[NL80211_ATTR_MAX + 1];
  struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
  struct nlattr *sinfo[NL80211_STA_INFO_MAX + 1];
  struct nlattr *rinfo[NL80211_RATE_INFO_MAX + 1];
  char mac_addr[20];



  nla_parse(tb,
            NL80211_ATTR_MAX,
            genlmsg_attrdata(gnlh, 0),
            genlmsg_attrlen(gnlh, 0),
            NULL);

  mac_addr_n2a(mac_addr, nla_data(tb[NL80211_ATTR_MAC]));
  strcpy(((Neighbour*)arg)->mac_address, mac_addr);

  if (!tb[NL80211_ATTR_STA_INFO]) {
    fprintf(stderr, "sta stats missing!\n"); return NL_SKIP;
  }

  if (nla_parse_nested(sinfo, NL80211_STA_INFO_MAX,
                       tb[NL80211_ATTR_STA_INFO], stats_policy)) {
    fprintf(stderr, "failed to parse nested attributes!\n"); return NL_SKIP;
  }

  if (sinfo[NL80211_STA_INFO_TX_BITRATE]) {
    if (nla_parse_nested(rinfo, NL80211_RATE_INFO_MAX,
                         sinfo[NL80211_STA_INFO_TX_BITRATE], rate_policy)) {
      fprintf(stderr, "failed to parse nested rate attributes!\n"); }
    else {
      if (rinfo[NL80211_RATE_INFO_BITRATE]) {
        ((Neighbour*)arg)->txrate = nla_get_u16(rinfo[NL80211_RATE_INFO_BITRATE])/10;
      }
    }
  }
	if (sinfo[NL80211_STA_INFO_SIGNAL])
    ((Neighbour*)arg)->signal =	(int8_t)nla_get_u8(sinfo[NL80211_STA_INFO_SIGNAL_AVG]);

  if (sinfo[NL80211_STA_INFO_INACTIVE_TIME])
  {
    ((Neighbour*)arg)->inac_time = nla_get_u32(sinfo[NL80211_STA_INFO_INACTIVE_TIME]);
  }

  if (sinfo[NL80211_STA_INFO_EXPECTED_THROUGHPUT]) {
		uint32_t thr;

		thr = nla_get_u32(sinfo[NL80211_STA_INFO_EXPECTED_THROUGHPUT]);
		/* convert in Mbps but scale by 1000 to save kbps units */
		thr = thr * 1000 / 1024;
    ((Neighbour*)arg)->i_throughput = thr/1000;
    ((Neighbour*)arg)->d_throughput = thr%1000;

	}else{
    ((Neighbour*)arg)->d_throughput = 0;
    ((Neighbour*)arg)->i_throughput = 0;
  }

  /*
  printf("Interface: %s | mac: %s | signal: %d dB | txrate: %.1f MBit/s | Throughput: %u.%u |Inactive Time: %u ms \n",
           ((Neighbour*)arg)->ifname, ((Neighbour*)arg)->mac_address, ((Neighbour*)arg)->signal,
            ((Neighbour*)arg)->txrate,((Neighbour*)arg)->i_throughput,((Neighbour*)arg)->d_throughput,
            ((Neighbour*)arg)->inac_time);
  */


  // ---------------------------------------------------------
  char str[25];
  sprintf(str, "%s|%d\n", &(((Neighbour*)arg)->mac_address)[13], ((Neighbour*)arg)->signal);
  strcpy(req_buff+reqlen, str);
  reqlen = reqlen + strlen(str);
  stations_num++;
  // ---------------------------------------------------------



  return NL_SKIP;

}


static int send_message(Netlink* nl, Neighbour* w) {
  nl->result1 = 1;
  nl->result2 = 1;

  struct nl_msg* msg1 = nlmsg_alloc();
  if (!msg1) {
    fprintf(stderr, "Failed to allocate netlink message.\n");
    return -2;
  }

  genlmsg_put(msg1,
              NL_AUTO_PORT,
              NL_AUTO_SEQ,
              nl->id,
              0,
              NLM_F_DUMP,
              NL80211_CMD_GET_INTERFACE,
              0);

  nl_send_auto(nl->socket, msg1);

  while (nl->result1 > 0) { nl_recvmsgs(nl->socket, nl->cb1); }
  nlmsg_free(msg1);

  if (w->ifindex < 0) { return -1; }

  struct nl_msg* msg2 = nlmsg_alloc();

  if (!msg2) {
    fprintf(stderr, "Failed to allocate netlink message.\n");
    return -2;
  }

  genlmsg_put(msg2,
              NL_AUTO_PORT,
              NL_AUTO_SEQ,
              nl->id,
              0,
              NLM_F_DUMP,
              NL80211_CMD_GET_STATION,
              0);

  nla_put_u32(msg2, NL80211_ATTR_IFINDEX, w->ifindex);
  nl_send_auto(nl->socket, msg2);
  while (nl->result2 > 0) { nl_recvmsgs(nl->socket, nl->cb2); }
  nlmsg_free(msg2);

  return 0;
}

int main(int argc, char **argv) {
  printf("Initializing netlink 802.11\n");
  nl.id = initNl80211(&nl, &w);
  if (nl.id < 0) {
    fprintf(stderr, "Error initializing netlink 802.11\n");
    return -1;
  }

  client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl((in_addr_t) 0x7f000001); // 127.0.0.1 (localhost)
  serv_addr.sin_port = htons(4346);

  while(1){
    if(client != 0){
      send_message(&nl, &w);
    }
    nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
  }

  nl_cb_put(nl.cb1);
  nl_cb_put(nl.cb2);
  nl_close(nl.socket);
  nl_socket_free(nl.socket);
  return 0;
}