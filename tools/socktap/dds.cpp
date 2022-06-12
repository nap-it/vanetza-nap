#include "dds.h"
#include <map>

using namespace boost::asio;

map<string, Mqtt_client*> dds_subscribers;
int to_dds_mq;
int from_dds_mq;

typedef struct {
	long mesg_type;
	char mesg_text[15000];
} message_t;

Dds::Dds(int to_dds_key, int from_dds_key) {
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

bool Dds::subscribe(string topic, Mqtt_client* object) {
    dds_subscribers[topic] = object;
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
    if(dds_subscribers[topic] != nullptr) {
        dds_subscribers[topic]->on_message(topic, message);
    }
}