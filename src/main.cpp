#include <MHZ19.h>
#include <SoftwareSerial.h>
#include <TFT_eSPI.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "WiFiManager.h"
#include "MqttManager.h"
#include "display/Display.h"
#include "MainView.h"
#include "MainPresenter.h"
#include ".config.h"

#define RX_PIN D6
#define TX_PIN D0
#define BAUDRATE 9600
#define INTERVAL 2000

unsigned long getDataTimer = 0;

MHZ19 mhz19;
SoftwareSerial mhz19Serial(RX_PIN, TX_PIN);

WiFiClient wifi;
PubSubClient mqtt(wifi);

Display display;
MainView mainView(display);
MainPresenter mainPresenter(mhz19, mainView, mqtt);

void setup()
{
    Serial.begin(115200);

    mhz19Serial.begin(BAUDRATE);
    mhz19.begin(mhz19Serial);
    mhz19.autoCalibration(false);

    if (wifi_enable)
        WiFiManager::connect(wifi_ssid, wifi_passphrase);
    else
        WiFiManager::off();
}

void loop()
{
    if (millis() - getDataTimer >= INTERVAL)
    {
        if (mqtt_enable && !mqtt.connected())
            MqttManager::connect(mqtt_server, mqtt_port, mqtt_clientId, mqtt_user, mqtt_password, mqtt);
        mainPresenter.update();
        getDataTimer = millis();
    }
}
