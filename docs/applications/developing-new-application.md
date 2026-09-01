title: Developing a New Application

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Firstly, if you need to generate code from ASN.1 definitions follow the official Vanetza [documentation](https://www.vanetza.org/recipes/generate-asn1/) 

To add a new V2X message type:

**1. Create the ASN.1 Wrapper:** Add the ASN.1 type definition under `vanetza/asn1/` (e.g., `vanetza/asn1/newmsg.hpp`).

**2. Register the BTP Port:** Add the new BTP port in `vanetza/btp/ports.hpp`.

**3. Create the Application Class:** Create `tools/socktap/applications/newmsg_application.hpp` and `.cpp`:

```cpp
#include "../application.hpp"

class NewmsgApplication : public Application, public PubSub_application
{
public:
    NewmsgApplication(vanetza::PositionProvider& positioning,
                      vanetza::Runtime& rt,
                      PubSub* pubsub_,
                      config_t config_s_,
                      metrics_t metrics_s_,
                      int priority_,
                      std::mutex& prom_mtx_);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void set_interval(vanetza::Clock::duration);
    void on_message(string topic, string mqtt_message,
                    const std::vector<uint8_t>& bytes,
                    bool is_encoded, double time_reception,
                    string test, vanetza::geonet::Router* router);
    int priority;

private:
    void schedule_timer();
    void on_timer(vanetza::Clock::time_point);
    // ... member variables ...
};
```

**4. Add Configuration:** Add a `message_config_t` field to `config_t` in `config.hpp`, and add the corresponding section to `config.ini`:

```ini
[newmsg]
enabled=true
mqtt_enabled=true
dds_enabled=false
zenoh_enabled=false
mqtt_time_enabled=true
mqtt_test_enabled=false
periodicity=0
topic_in=vanetza/in/newmsg
topic_out=vanetza/out/newmsg
topic_time=vanetza/time/newmsg
topic_test=vanetza/test/newmsg
udp_out_addr=127.0.0.1
udp_out_port=0
```

**5. Instantiate in main.cpp:** Add the conditional instantiation block following the existing pattern:

```cpp
if (config_s.newmsg.enabled) {
    std::unique_ptr<NewmsgApplication> newmsg_app {
        new NewmsgApplication(*positioning, runtime, pubsub,
                              config_s, metrics_s, 2, prom_mtx)
    };
    newmsg_app->set_interval(std::chrono::milliseconds(config_s.newmsg.periodicity));
    apps.emplace("newmsg", std::move(newmsg_app));
}
```

**6. Update CMakeLists.txt:** Add the new source files to `tools/socktap/CMakeLists.txt`:

```cmake
applications/newmsg_application.cpp
applications/newmsg_application.hpp
```

