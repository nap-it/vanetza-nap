#include "rssi_reader.hpp"

#define _XOPEN_SOURCE 700
#define ETH_ALEN 6

std::map<std::string, int> rssi;
std::map<std::string, int> mcs;
std::map<std::string, double> timeout;

std::string devname;

Netlink nl;
Neighbour w;
Survey survey;

struct stats_parse_policy {
        ::nla_policy pol[NL80211_STA_INFO_MAX + 1];
} stats_policy;

struct rate_parse_policy {
        ::nla_policy pol[NL80211_RATE_INFO_MAX + 1];
} rate_policy;

struct survey_parse_policy {
        ::nla_policy pol[NL80211_SURVEY_INFO_MAX + 1];
} survey_policy;

void mac_addr_n2a(char *mac_addr, const unsigned char *arg) {
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

static int initNl80211(Netlink* nl, Neighbour* w, Survey* s) {
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

  nl->cbInterface = nl_cb_alloc(NL_CB_DEFAULT);
  nl->cbStation = nl_cb_alloc(NL_CB_DEFAULT);
  nl->cbSurvey = nl_cb_alloc(NL_CB_DEFAULT);
  if ((!nl->cbInterface) || (!nl->cbStation) || (!nl->cbSurvey)) {
     fprintf(stderr, "Failed to allocate netlink callback.\n");
     nl_close(nl->socket);
     nl_socket_free(nl->socket);
     return ENOMEM;
  }

  nl_cb_set(nl->cbInterface, NL_CB_VALID , NL_CB_CUSTOM, getInterfaceName_callback, w);
  nl_cb_set(nl->cbInterface, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler, &(nl->resultInterface));
  nl_cb_set(nl->cbStation, NL_CB_VALID , NL_CB_CUSTOM, getNeighbourInfo_callback, w);
  nl_cb_set(nl->cbStation, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler, &(nl->resultStation));
  nl_cb_set(nl->cbSurvey, NL_CB_VALID , NL_CB_CUSTOM, getWirelessSurvey_callback, s);
  nl_cb_set(nl->cbSurvey, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler, &(nl->resultSurvey));

  return nl->id;
}

static int finish_handler(struct nl_msg *msg, void *arg) {
  int *ret = (int *) arg;
  *ret = 0;
  return NL_SKIP;
}

static int getInterfaceName_callback(struct nl_msg *msg, void *arg) {
  struct genlmsghdr *gnlh = (genlmsghdr*) nlmsg_data(nlmsg_hdr(msg));
  struct nlattr *tb_msg[NL80211_ATTR_MAX + 1];
  //nl_msg_dump(msg, stdout);

  nla_parse(tb_msg,
            NL80211_ATTR_MAX,
            genlmsg_attrdata(gnlh, 0),
            genlmsg_attrlen(gnlh, 0),
            NULL);

  if (tb_msg[NL80211_ATTR_IFNAME] && nla_get_string(tb_msg[NL80211_ATTR_IFNAME]) == devname) {
    strcpy(((Neighbour*)arg)->ifname, nla_get_string(tb_msg[NL80211_ATTR_IFNAME]));

    if (tb_msg[NL80211_ATTR_IFINDEX]) {
      ((Neighbour*)arg)->ifindex = nla_get_u32(tb_msg[NL80211_ATTR_IFINDEX]);
    }
  }

  return NL_SKIP;
}

static int getNeighbourInfo_callback(struct nl_msg *msg, void *arg) {
  struct nlattr *tb[NL80211_ATTR_MAX + 1];
  struct genlmsghdr *gnlh = (genlmsghdr*) nlmsg_data(nlmsg_hdr(msg));
  struct nlattr *sinfo[NL80211_STA_INFO_MAX + 1];
  struct nlattr *rinfo[NL80211_RATE_INFO_MAX + 1];
  char mac_addr[20];

  nla_parse(tb,
            NL80211_ATTR_MAX,
            genlmsg_attrdata(gnlh, 0),
            genlmsg_attrlen(gnlh, 0),
            NULL);

  mac_addr_n2a(mac_addr, (const unsigned char*) nla_data(tb[NL80211_ATTR_MAC]));
  strcpy(((Neighbour*)arg)->mac_address, mac_addr);

  if (!tb[NL80211_ATTR_STA_INFO]) {
    fprintf(stderr, "sta stats missing!\n"); return NL_SKIP;
  }

  if (nla_parse_nested(sinfo, NL80211_STA_INFO_MAX,
                       tb[NL80211_ATTR_STA_INFO], stats_policy.pol)) {
    fprintf(stderr, "failed to parse nested attributes!\n"); return NL_SKIP;
  }

  if (sinfo[NL80211_STA_INFO_TX_BITRATE]) {
    if (nla_parse_nested(rinfo, NL80211_RATE_INFO_MAX,
                         sinfo[NL80211_STA_INFO_TX_BITRATE], rate_policy.pol)) {
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

  std::string mac(((Neighbour*)arg)->mac_address);
  rssi[mac] = ((Neighbour*)arg)->signal;

  double station_mcs = ((Neighbour*)arg)->txrate;
  if (station_mcs <= 3.0) mcs[mac] = 1;
  else if (station_mcs <= 4.5) mcs[mac] = 2;
  else if (station_mcs <= 6.0) mcs[mac] = 3;
  else if (station_mcs <= 9.0) mcs[mac] = 4;
  else if (station_mcs <= 12.0) mcs[mac] = 5;
  else if (station_mcs <= 18.0) mcs[mac] = 6;
  else if (station_mcs <= 24.0) mcs[mac] = 7;
  else if (station_mcs <= 27.0) mcs[mac] = 8;
  else mcs[mac] = -1;

  timeout[mac] = (double) std::chrono::duration_cast< std::chrono::microseconds >(std::chrono::system_clock::now().time_since_epoch()).count() / 1000000.0;

  return NL_SKIP;
}

static int getWirelessSurvey_callback(struct nl_msg *msg, void *arg) {
	struct nlattr *tb[NL80211_ATTR_MAX + 1];
  struct genlmsghdr *gnlh = (genlmsghdr*) nlmsg_data(nlmsg_hdr(msg));
	struct nlattr *sinfo[NL80211_SURVEY_INFO_MAX + 1];

	nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
		  genlmsg_attrlen(gnlh, 0), NULL);
	
	if (!tb[NL80211_ATTR_SURVEY_INFO]) {
		fprintf(stderr, "survey data missing!\n");
		return NL_SKIP;
	}
	if (nla_parse_nested(sinfo, NL80211_SURVEY_INFO_MAX,
			     tb[NL80211_ATTR_SURVEY_INFO],
			     survey_policy.pol)) {
		fprintf(stderr, "failed to parse nested attributes!\n");
		return NL_SKIP;
	}

  if(sinfo[NL80211_SURVEY_INFO_IN_USE]) {
    ((Survey*)arg)->frequency = nla_get_u32(sinfo[NL80211_SURVEY_INFO_FREQUENCY]);
    if (sinfo[NL80211_SURVEY_INFO_NOISE]) ((Survey*)arg)->noise = (int8_t)nla_get_u8(sinfo[NL80211_SURVEY_INFO_NOISE]);
    else ((Survey*)arg)->noise = -1;
    if (sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_BUSY]) ((Survey*)arg)->chan_busy_time = round((double) nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_BUSY]) / nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME]) * 1000000) / 1000000;
    if (sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_RX]) ((Survey*)arg)->chan_rx_time = round((double) nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_RX]) / nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME]) * 1000000) / 1000000;
    if (sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_TX]) ((Survey*)arg)->chan_tx_time = round((double) nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME_TX]) / nla_get_u64(sinfo[NL80211_SURVEY_INFO_CHANNEL_TIME]) * 1000000) / 1000000;
  }
 
	return NL_SKIP;
}

static int send_message(Netlink* nl, Neighbour* w, Survey* s) {
  nl->resultInterface = 1;
  nl->resultStation = 1;
  nl->resultSurvey = 1;

  // Message 1 - NL80211_CMD_GET_INTERFACE
  struct nl_msg* msgInterface = nlmsg_alloc();
  if (!msgInterface) {
    fprintf(stderr, "Failed to allocate netlink interface message.\n");
    return -2;
  }

  genlmsg_put(msgInterface,
              NL_AUTO_PORT,
              NL_AUTO_SEQ,
              nl->id,
              0,
              NLM_F_DUMP,
              NL80211_CMD_GET_INTERFACE,
              0);

  nl_send_auto(nl->socket, msgInterface);

  while (nl->resultInterface > 0) { nl_recvmsgs(nl->socket, nl->cbInterface); }
  nlmsg_free(msgInterface);
  if (w->ifindex < 0) { return -1; }

  // Message 2 - NL80211_CMD_GET_STATION
  struct nl_msg* msgStation = nlmsg_alloc();
  if (!msgStation) {
    fprintf(stderr, "Failed to allocate netlink station message.\n");
    return -2;
  }

  genlmsg_put(msgStation,
              NL_AUTO_PORT,
              NL_AUTO_SEQ,
              nl->id,
              0,
              NLM_F_DUMP,
              NL80211_CMD_GET_STATION,
              0);

  nla_put_u32(msgStation, NL80211_ATTR_IFINDEX, w->ifindex);
  nl_send_auto(nl->socket, msgStation);
  while (nl->resultStation > 0) { nl_recvmsgs(nl->socket, nl->cbStation); }
  nlmsg_free(msgStation);

  // Message 3 - NL80211_CMD_GET_SURVEY
  struct nl_msg* msgSurvey = nlmsg_alloc();
  if (!msgSurvey) {
    fprintf(stderr, "Failed to allocate netlink survey message.\n");
    return -2;
  }

  genlmsg_put(msgSurvey,
              NL_AUTO_PORT,
              NL_AUTO_SEQ,
              nl->id,
              0,
              NLM_F_DUMP,
              NL80211_CMD_GET_SURVEY,
              0);

  nla_put_u32(msgSurvey, NL80211_ATTR_IFINDEX, w->ifindex);
  nl_send_auto(nl->socket, msgSurvey);
  while (nl->resultSurvey > 0) { nl_recvmsgs(nl->socket, nl->cbSurvey); }
  nlmsg_free(msgSurvey);

  return 0;
}

int rssi_main() {
  stats_policy.pol[NL80211_STA_INFO_INACTIVE_TIME].type = NLA_U32;
  stats_policy.pol[NL80211_STA_INFO_RX_BYTES].type = NLA_U32;
  stats_policy.pol[NL80211_STA_INFO_TX_BYTES].type = NLA_U32;
  stats_policy.pol[NL80211_STA_INFO_RX_PACKETS].type = NLA_U32;
  stats_policy.pol[NL80211_STA_INFO_TX_PACKETS].type = NLA_U32;
  stats_policy.pol[NL80211_STA_INFO_SIGNAL].type = NLA_U8;
  stats_policy.pol[NL80211_STA_INFO_TX_BITRATE].type = NLA_NESTED;
  stats_policy.pol[NL80211_STA_INFO_LLID].type = NLA_U16;
  stats_policy.pol[NL80211_STA_INFO_PLID].type = NLA_U16;
  stats_policy.pol[NL80211_STA_INFO_PLINK_STATE].type = NLA_U8;

  rate_policy.pol[NL80211_RATE_INFO_BITRATE].type = NLA_U16;
  rate_policy.pol[NL80211_RATE_INFO_MCS].type = NLA_U8;
  rate_policy.pol[NL80211_RATE_INFO_40_MHZ_WIDTH].type = NLA_FLAG;
  rate_policy.pol[NL80211_RATE_INFO_SHORT_GI].type = NLA_FLAG;

  survey_policy.pol[NL80211_SURVEY_INFO_FREQUENCY].type = NLA_U32;
  survey_policy.pol[NL80211_SURVEY_INFO_NOISE].type = NLA_U8;

  survey.frequency = -1;

  printf("Initializing netlink 802.11\n");
  nl.id = initNl80211(&nl, &w, &survey);
  if (nl.id < 0) {
    fprintf(stderr, "Error initializing netlink 802.11\n");
    return -1;
  }

  int i = 0;
  while(1){
    send_message(&nl, &w, &survey);
    nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
    i++;
    if(i == 100) {
      i = 0;
      const double time_now = (double) std::chrono::duration_cast< std::chrono::microseconds >(std::chrono::system_clock::now().time_since_epoch()).count() / 1000000.0;
      auto it = timeout.begin();
      while (it != timeout.end()) {
          if (time_now - it->second >= 1) {
              rssi.erase(it->first);
              mcs.erase(it->first);
              it = timeout.erase(it);
          } else {
              ++it;
          }
      }
    }
  }

  nl_cb_put(nl.cbInterface);
  nl_cb_put(nl.cbStation);
  nl_close(nl.socket);
  nl_socket_free(nl.socket);
  return 0;
}

void start_rssi_reader(const std::string& device_name) {
  devname = device_name;
  std::thread t1(rssi_main);
  t1.detach();
}

int get_rssi(std::string mac) {
  if(rssi.count(mac)) {
      return rssi[mac];
  }
  return 1;
}

std::map<std::string, int> get_mcs() {
  return mcs;
}

Survey get_survey() {
  return survey;
}