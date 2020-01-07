#include <ESP8266WiFi.h>

#include "WiFiManager.h"

void WiFiManager::connect(const char* ssid, const char *passphrase)
{
    delay(100);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passphrase);
    Serial.print("Connecting to SSID "); Serial.println(ssid);
    for (int i = 0; i < 10; i++)
    {        
        if (WiFi.status() == WL_CONNECTED)
        {            
            Serial.println("WiFi connected");
            Serial.print("Local IP address: "); Serial.println(WiFi.localIP());
            break;
        }
        delay(1000);
        Serial.print(".");        
    }
    Serial.println();
}

void WiFiManager::off()
{
    delay(100);
    WiFi.mode(WIFI_OFF);
    Serial.print("WiFi status: "); Serial.println(WiFi.status());
}