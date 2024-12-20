#include "KelasRobotTime.h"

KelasRobotTime::KelasRobotTime() : timeClient(ntpUDP, "pool.ntp.org") {}

void KelasRobotTime::connectWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void KelasRobotTime::begin(long utcOffsetInSeconds) {
  timeClient.begin();
  timeClient.setTimeOffset(utcOffsetInSeconds);
}

void KelasRobotTime::update() {
  timeClient.update();

  time_t epochTime = timeClient.getEpochTime();
  struct tm* ptm = gmtime((time_t*)&epochTime);

  weekDay = timeClient.getDay();
  day = ptm->tm_mday;
  month = ptm->tm_mon + 1;
  year = ptm->tm_year + 1900;

  hours = timeClient.getHours();
  minutes = timeClient.getMinutes();
  seconds = timeClient.getSeconds();
}
