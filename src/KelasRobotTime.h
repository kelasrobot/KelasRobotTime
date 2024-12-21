#ifndef KELASROBOTTIME_H
#define KELASROBOTTIME_H

#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

class KelasRobotTime {
  private:
    WiFiUDP ntpUDP;
    NTPClient timeClient;
    unsigned long lastSyncTime;  // Waktu sinkronisasi terakhir (epoch)
    unsigned long localStartMillis;  // Waktu saat terakhir disinkronisasi
    bool isOffline;  // Status koneksi

  public:
    int hours, minutes, seconds, day, month, year, weekDay;

    KelasRobotTime();

    void connectWiFi(const char* ssid, const char* password);
    void begin(long utcOffsetInSeconds);
    void update();
    void syncTime();  // Sinkronisasi dengan server NTP
};

#endif // KELASROBOTTIME_H