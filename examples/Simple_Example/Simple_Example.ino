#include "KelasRobotTime.h"
const char* ssid = "wifi name";
const char* pass = "wifi password";
KelasRobotTime ntp;

void setup() {
  Serial.begin(115200);
  ntp.connectWiFi(ssid, pass);
  ntp.begin(25200);
}

void loop() {
  ntp.update();
  Serial.print(ntp.hours);
  Serial.print(":");
  Serial.print(ntp.minutes);
  Serial.print(":");
  Serial.println(ntp.seconds);
  delay(1000);
}