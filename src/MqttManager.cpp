#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MqttManager.h"

void MqttManager::connect(const char * domain, uint16_t port, const char *id, const char *user, const char *pass, PubSubClient &mqtt)
{
    mqtt.setServer(domain, port);
    //client.setCallback(callback);
    Serial.print("Connecting to MQTT server "); Serial.println(domain);
    if (mqtt.connect(id, user, pass))
    {
        Serial.println("MQTT connected");
        Serial.print("Local IP address: "); Serial.println(WiFi.localIP());            
        mqtt.subscribe("bme1/rotation");
        mqtt.subscribe("bme1/brightness");
    }
    else
    {
        Serial.print("MQTT connection failed, rc="); Serial.print(mqtt.state()); Serial.println(", try again later");
    }
}