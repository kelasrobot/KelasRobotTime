#ifndef KELASROBOTTIME_H
#define KELASROBOTTIME_H

#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

class KelasRobotTime {
  private:
    WiFiUDP ntpUDP;
    NTPClient timeClient;

  public:
    int hours, minutes, seconds, day, month, year, weekDay;

    KelasRobotTime();

    void connectWiFi(const char* ssid, const char* password);
    void begin(long utcOffsetInSeconds);
    void update();
};

#endif // KELASROBOTTIME_H
