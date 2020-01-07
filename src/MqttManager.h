#ifndef MqttManager_h
#define MqttManager_h

class MqttManager {
    public:
        static void connect(const char * domain, uint16_t port, const char *id, const char *user, const char *pass, PubSubClient &mqtt);
};

#endif