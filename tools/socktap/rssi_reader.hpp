#include <stdio.h>
#include <signal.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <netlink/netlink.h>    //lots of netlink functions
#include <netlink/genl/genl.h>  //genl_connect, genlmsg_put
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>  //genl_ctrl_resolve
#include <linux/nl80211.h>      //NL80211 definitions
#include <thread>
#include <map>
#include <iostream>
#include <chrono>
#include <math.h>

//
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct {
  int id;
  struct nl_sock* socket;
  struct nl_cb* cbInterface,* cbStation, * cbSurvey;
  int resultInterface, resultStation, resultSurvey;
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

typedef struct {
  int frequency;
  int noise;
  double chan_busy_time;
  double chan_rx_time;
  double chan_tx_time;
} Survey;

static int initNl80211(Netlink* nl, Neighbour* w, Survey* s);
static int finish_handler(struct nl_msg *msg, void *arg);
static int getInterfaceName_callback(struct nl_msg *msg, void *arg);
static int getNeighbourInfo_callback(struct nl_msg *msg, void *arg);
static int getWirelessSurvey_callback(struct nl_msg *msg, void *arg);
static int send_message(Netlink* nl, Neighbour* w, Survey* s);
int rssi_main();
void start_rssi_reader(const std::string& device_name);
int get_rssi(std::string mac);
std::map<std::string, int> get_mcs();
Survey get_survey();