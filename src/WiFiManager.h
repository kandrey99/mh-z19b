#ifndef WiFiManager_h
#define WiFiManager_h

class WiFiManager {
    public:
        static void connect(const char* ssid, const char *passphrase = NULL);
        static void off();
};

#endif