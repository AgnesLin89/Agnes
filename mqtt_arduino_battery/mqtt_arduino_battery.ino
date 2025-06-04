/*
  ArduinoMqttClient - WiFi Simple Sender

  This example connects to a MQTT broker and publishes a message to
  a topic once a second.

  The circuit:
  - Arduino MKR 1000, MKR 1010 or Uno WiFi Rev2 board

  This example code is in the public domain.
*/
#include <Arduino_LSM6DS3.h>         //這是陀螺儀
#include <ArduinoMqttClient.h>       //這是為了傳資料
#include <WiFiNINA.h>                //這是作用於wifi連線
/*
#if defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_AVR_UNO_WIFI_REV2)
  #include <WiFiNINA.h>
#elif defined(ARDUINO_SAMD_MKR1000)
  #include <WiFi101.h>
#elif defined(ARDUINO_ARCH_ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_NICLA_VISION) || defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_GIGA) || defined(ARDUINO_OPTA)
  #include <WiFi.h>
#elif defined(ARDUINO_PORTENTA_C33)
  #include <WiFiC3.h>
#elif defined(ARDUINO_UNOR4_WIFI)
  #include <WiFiS3.h>
#endif
*/

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "TP-Link_6FE2";    // your network SSID (name)
char pass[] = "60003236";    // your network password (use for WPA, or use as key for WEP)

//char ssid[] = "TP-LINK_5A9FF5";    // your network SSID (name)
//char pass[] = "115A9FF5";    // your network password (use for WPA, or use as key for WEP)

// To connect with SSL/TLS:
// 1) Change WiFiClient to WiFiSSLClient.
// 2) Change port value from 1883 to 8883.
// 3) Change broker value to a server with a known SSL/TLS root certificate 
//    flashed in the WiFi module.

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "test.mosquitto.org";
int        port     = 1883;
//int        port     = 8081;
const char topic[]  = "/IMU";

const long interval = 1000;
unsigned long previousMillis = 0;

int count = 0;
float x, y, z = 0;
float t = 0;

void setup() {
  //Initialize serial and wait for port to open:
  /*
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  */

  pinMode(LED_BUILTIN, OUTPUT);

  if (!IMU.begin()) {
    //Serial.println("Failed to initialize IMU!");
    while (1);
  }

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(5000);
  }

  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  mqttClient.setId("mqtts1");
  // You can provide a username and password for authentication
  // mqttClient.setUsernamePassword("username", "password");

  if (!mqttClient.connect(broker, port)) {
    //Serial.print("MQTT connection failed! Error code = ");
    //Serial.println(mqttClient.connectError());
    while (1);
  } else {
    digitalWrite(13, HIGH);
  }

  Serial.println("You're connected to the MQTT broker!");
  //Serial.println();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alives which
  // avoids being disconnected by the broker
  mqttClient.poll();
  
  mqttClient.beginMessage(topic);
  mqttClient.print(3);
  mqttClient.endMessage();
  //unsigned long currentMillis = millis();

  
  //if (currentMillis - previousMillis >= interval) {
    // save the last time a message was sent
    //previousMillis = currentMillis;
    //float x, y, z;
    //float t;
    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(x, y, z);
    //if (IMU.gyroscopeAvailable()) {
      //IMU.readGyroscope(x, y, z);
      IMU.readTemperature(t);

      if(z>0.5){
        mqttClient.beginMessage(topic);
        mqttClient.print(1);
        mqttClient.endMessage();
        Serial.println(z);

      } else if(z<-0.5){
        mqttClient.beginMessage(topic);
        mqttClient.print(2);
        mqttClient.endMessage();
        Serial.println(z);
      }

      // mqttClient.beginMessage(topic);
      // mqttClient.print(t);
      // mqttClient.print('\t');
      // mqttClient.print(x);
      // mqttClient.print('\t');
      // mqttClient.print(y);
      // mqttClient.print('\t');
      // mqttClient.println(z);
      // mqttClient.endMessage();

      // Serial.print(t);
      // Serial.print('\t');
      // Serial.print(x);
      // Serial.print('\t');
      // Serial.print(y);
      // Serial.print('\t');
      // Serial.println(z);
    
    }
    // if(IMU.temperatureAvailable()) {
    //   IMU.readTemperature(t);
    // }

    // mqttClient.beginMessage(topic);
    // mqttClient.print(t);
    // mqttClient.print('\t');
    // mqttClient.print(x);
    // mqttClient.print('\t');
    // mqttClient.print(y);
    // mqttClient.print('\t');
    // mqttClient.println(z);
    // mqttClient.endMessage();

    delay(50);
  //}
}
