#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "time.h"

// Atur alamat I2C LCD (0x27 atau 0x3F biasanya)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// WiFi Wokwi
const char* ssid = "GANTI SSID WIFI DISINI";
const char* password = "GANTI PASSWORD WIFI DISINI";

// NTP Server
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7 * 3600; // GMT+7 (WIB)
const int daylightOffset_sec = 0;

void setup() {
  Serial.begin(115200);

  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  // Connect WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected!");
  delay(1500);

  // Init NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to get time");
    lcd.setCursor(0, 1);
    lcd.print("Time Error     ");
    delay(2000);
    return;
  }

  // Format waktu & tanggal
  char timeStr[9];   // "HH:MM:SS"
  char dateStr[16];  // "DD-MM-YYYY"
  strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
  strftime(dateStr, sizeof(dateStr), "%d-%m-%Y", &timeinfo);

  // Hapus baris lama (overwrite dengan spasi)
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  // Tulis jam di baris 1
  lcd.setCursor(4, 0);
  lcd.print(timeStr);

  // Tulis tanggal di baris 2
  lcd.setCursor(3, 1);
  lcd.print(dateStr);

  // Debug ke Serial Monitor
  Serial.print("Time: ");
  Serial.println(timeStr);
  Serial.print("Date: ");
  Serial.println(dateStr);

  delay(1000); // update tiap 1 detik
}
