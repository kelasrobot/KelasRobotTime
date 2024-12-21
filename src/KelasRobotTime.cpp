#include "KelasRobotTime.h"

KelasRobotTime::KelasRobotTime() 
  : timeClient(ntpUDP, "pool.ntp.org"), isOffline(false), lastSyncTime(0), localStartMillis(0) {}

void KelasRobotTime::connectWiFi(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
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
  syncTime();  // Sinkronisasi awal
}

void KelasRobotTime::syncTime() {
  if (WiFi.status() == WL_CONNECTED) {
    timeClient.update();
    lastSyncTime = timeClient.getEpochTime();
    localStartMillis = millis();
    isOffline = false;
  } else {
    Serial.println("Offline: Using local time.");
    isOffline = true;
  }
}

void KelasRobotTime::update() {
  unsigned long currentMillis = millis();
  unsigned long currentTime = lastSyncTime + (currentMillis - localStartMillis) / 1000;

  time_t epochTime = currentTime;
  struct tm* ptm = gmtime((time_t*)&epochTime);

  weekDay = ptm->tm_wday;
  day = ptm->tm_mday;
  month = ptm->tm_mon + 1;
  year = ptm->tm_year + 1900;

  hours = ptm->tm_hour;
  minutes = ptm->tm_min;
  seconds = ptm->tm_sec;
}