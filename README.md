# KelasRobotTime Library

`KelasRobotTime` adalah library yang memudahkan sinkronisasi waktu berbasis NTP (Network Time Protocol) untuk board ESP32 dan ESP8266. Dengan library ini, Anda dapat dengan mudah menghubungkan board Anda ke WiFi, mengambil waktu saat ini menggunakan NTP, dan mengelola variabel waktu (jam, menit, detik) dengan sederhana.

## Fitur

- **Menghubungkan ke WiFi**: Dengan hanya satu baris kode, Anda dapat menghubungkan board ESP32 atau ESP8266 ke jaringan WiFi.
- **Mengambil waktu dari server NTP**: Library ini memungkinkan Anda untuk mengambil waktu dari server NTP secara otomatis.
- **Mendukung ESP32 dan ESP8266**: Kompatibel dengan kedua board ini.
- **Mengelola waktu**: Waktu dikelola dalam tiga variabel utama: `jam`, `menit`, dan `detik`.
- **Pengaturan zona waktu yang mudah**: Anda dapat mengatur offset waktu sesuai zona waktu yang diinginkan.

## Instalasi

1. **Install Library Melalui Arduino IDE**:
   - Unduh file ZIP dari repositori ini.
   - Buka **Arduino IDE**, pilih **Sketch > Include Library > Add .ZIP Library...** dan pilih file ZIP yang telah diunduh.
   - Setelah terinstal, library `KelasRobotTime` dapat digunakan dalam proyek Anda.

2. **Install Melalui Library Manager**:
   - Pilih **Sketch > Include Library > Manage Libraries**.
   - Cari **KelasRobotTime** di Library Manager dan klik **Install**.

## Penggunaan

Berikut adalah contoh penggunaan library `KelasRobotTime` dalam proyek Arduino:

### Contoh Kode

```cpp
#include "KelasRobotTime.h"

// Ganti dengan SSID dan password WiFi Anda
const char* ssid = "wifi name";
const char* pass = "wifi password";

// Membuat objek ntp dari kelas KelasRobotTime
KelasRobotTime ntp;

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke WiFi
  ntp.connectWiFi(ssid, pass);

  // Memulai NTP dengan UTC offset untuk WIB (UTC +7)
  ntp.begin(25200);  // WIB: UTC +7
}

void loop() {
  // Memperbarui waktu
  ntp.update();

  // Mencetak waktu dalam format HH:MM:SS ke Serial Monitor
  Serial.print(ntp.hours);
  Serial.print(":");
  Serial.print(ntp.minutes);
  Serial.print(":");
  Serial.println(ntp.seconds);

  // Menunggu 1 detik sebelum memperbarui waktu lagi
  delay(1000);
}
```

### Penjelasan Kode:
1. **Inisialisasi Kelas `KelasRobotTime`:**
   - `KelasRobotTime ntp;` — Objek `ntp` dibuat dari kelas `KelasRobotTime` untuk mengelola waktu.
   
2. **Menghubungkan ke WiFi:**
   - `ntp.connectWiFi(ssid, pass);` — Menghubungkan board ke WiFi menggunakan SSID dan password yang Anda tentukan.

3. **Menentukan Offset Waktu:**
   - `ntp.begin(25200);` — Inisialisasi waktu dengan offset UTC (misalnya, `25200` detik untuk WIB, UTC+7).

4. **Memperbarui dan Mencetak Waktu:**
   - `ntp.update();` — Memperbarui waktu dengan data dari server NTP.
   - `Serial.print(ntp.hours);`, `Serial.print(ntp.minutes);`, dan `Serial.print(ntp.seconds);` — Mencetak waktu dalam format jam:menit:detik ke Serial Monitor.

5. **Delay:**
   - `delay(1000);` — Memberikan delay selama 1 detik sebelum memperbarui waktu lagi.

## Metode

### `connectWiFi(const char* ssid, const char* password)`
- **Deskripsi**: Menghubungkan board ke jaringan WiFi.
- **Parameter**:
  - **ssid**: Nama jaringan WiFi.
  - **password**: Password WiFi.

### `begin(long offsetInSeconds)`
- **Deskripsi**: Menginisialisasi klien NTP dengan offset waktu UTC.
- **Parameter**:
  - **offsetInSeconds**: Offset waktu dari UTC dalam detik (misalnya `25200` untuk WIB, `28800` untuk WITA, `32400` untuk WIT).

### `update()`
- **Deskripsi**: Memperbarui waktu dari server NTP dan menyinkronkan nilai `hours`, `minutes`, dan `seconds`.

## Dukungan Board
Library ini mendukung board ESP32 dan ESP8266. Untuk menggunakan library ini, pastikan Anda menggunakan salah satu board tersebut di Arduino IDE.

## Lisensi
Library ini dirilis di bawah **MIT License**.

## Penulis
Ajang Rahmat  
Email: [ajangrahmat@gmail.com]

## Repositori
[GitHub Repository](https://github.com/kelasrobot/KelasRobotTime)

---