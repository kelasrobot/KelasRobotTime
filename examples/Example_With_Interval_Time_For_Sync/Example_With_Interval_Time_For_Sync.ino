#include "KelasRobotTime.h"
const char* ssid = "Kelas Robot";
const char* pass = "kumaha aa we";
KelasRobotTime ntp;

unsigned const long interval = 1000;
unsigned long zero, timer = 0;

void setup() {
  Serial.begin(115200);
  ntp.connectWiFi(ssid, pass);
  ntp.begin(25200);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  if (millis() - zero >= interval) {
    zero = millis();
    ntp.update();
    timer++;
    Serial.print(ntp.hours);
    Serial.print(":");
    Serial.print(ntp.minutes);
    Serial.print(":");
    Serial.println(ntp.seconds);
    Serial.println("Timer: " + String(timer));
    if (timer >= 3600) {
      timer = 0;
      ntp.connectWiFi(ssid, pass);
      ntp.syncTime();
      WiFi.mode(WIFI_OFF);
    }
  }
}
