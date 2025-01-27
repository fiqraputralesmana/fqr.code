#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>

// Pin untuk TM1637
#define CLK 2 // Pin Clock TM1637
#define DIO 3 // Pin Data TM1637

// Inisialisasi RTC dan display
RTC_DS1307 rtc;
TM1637Display display(CLK, DIO);

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Inisialisasi RTC
  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan!");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC tidak berjalan, mengatur waktu default...");
    // Mengatur waktu default: 27 Januari 2025 12:00:00
    rtc.adjust(DateTime(2025, 1, 27, 12, 0, 0));
  }

  // Inisialisasi display
  display.setBrightness(7); // Set tingkat kecerahan (0-7)
}

void loop() {
  // Membaca waktu dari RTC
  DateTime now = rtc.now();

  // Mengonversi jam dan menit ke format TM1637
  int displayTime = (now.hour() * 100) + now.minute();

  // Menampilkan waktu di TM1637
  display.showNumberDecEx(displayTime, 0b01000000, true);

  // Menunggu 1 detik sebelum update berikutnya
  delay(1000);
}
