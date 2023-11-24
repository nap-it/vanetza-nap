#include "dds.h"
#include "pubsub.hpp"
#include <map>

using namespace boost::asio;

int to_dds_mq;
int from_dds_mq;

typedef struct {
	long mesg_type;
	char mesg_text[15000];
} message_t;

Dds::Dds(int to_dds_key, int from_dds_key, PubSub* pubsub_) {
    this->pubsub = pubsub_;

    to_dds_mq = msgget(to_dds_key, 0666 | IPC_CREAT);
    from_dds_mq = msgget(from_dds_key, 0666 | IPC_CREAT);
    std::thread dds_th(&Dds::from_dds_thread, this);
    dds_th.detach();
}

Dds::~Dds() {

}

bool Dds::publish(string topic, string message) {
    string buf = topic + ";" + message;
    message_t m = {};
    m.mesg_type = 1;
    strcpy(m.mesg_text, buf.c_str());
    int a = msgsnd(to_dds_mq, &m, sizeof(m), 0);
    return true;
}

bool Dds::subscribe(string topic) {
    return true;
}

void Dds::from_dds_thread() {
    while(1) {
        message_t *m = new message_t;
        msgrcv(from_dds_mq, m, sizeof(*m), 1, 0);
        string data(m->mesg_text);
        std::string::size_type pos = data.find(';');
        if (pos != std::string::npos)
        {
            on_message(data.substr(0,pos), data.substr(pos+1, data.length()));
        }
        delete m;
    }
}


void Dds::on_message(string topic, string message) {
    this->pubsub->on_message(topic, message, 0);
}