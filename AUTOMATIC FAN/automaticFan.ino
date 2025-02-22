#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Konfigurasi DHT22
#define DHTPIN 2      // Pin data DHT22 terhubung ke D2
#define DHTTYPE DHT22 // Tipe sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi LCD 16x2 dengan I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C biasanya 0x27 atau 0x3F

// Konfigurasi Fan
#define FANPIN 3      // Pin kontrol fan terhubung ke D3
#define FAN_ON_TEMP 28 // Temperatur untuk menyalakan fan (°C)
#define FAN_OFF_TEMP 25 // Temperatur untuk mematikan fan (°C)

void setup() {
  // Inisialisasi LCD
  lcd.begin(16, 2); // Tambahkan parameter kolom dan baris
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initialization..");
  
  // Inisialisasi DHT22
  dht.begin();
  
  // Inisialisasi Pin Fan
  pinMode(FANPIN, OUTPUT);
  digitalWrite(FANPIN, LOW); // Pastikan fan dimatikan saat mulai
  
  // Pesan siap
  delay(2000);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Automatic Fan");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Baca suhu dan kelembapan
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  // Periksa apakah pembacaan berhasil
  if (isnan(suhu) || isnan(kelembapan)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error membaca");
    lcd.setCursor(0, 1);
    lcd.print("sensor!");
    delay(2000);
    return;
  }

  // Tampilkan suhu dan kelembapan di LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(suhu);
  lcd.write(223);
  lcd.print("C ");

  lcd.write(124);
  
  lcd.setCursor(10, 0);
  lcd.print(kelembapan);
  lcd.print("%");

  // Kontrol Fan berdasarkan suhu
  if (suhu > FAN_ON_TEMP) {
    digitalWrite(FANPIN, HIGH); // Nyalakan fan
    lcd.setCursor(4, 1);
    lcd.print("Fan: ON");
  } else if (suhu < FAN_OFF_TEMP) {
    digitalWrite(FANPIN, LOW); // Matikan fan
    lcd.setCursor(4, 1);
    lcd.print("Fan: OFF");
  }

  // Delay sebelum pembaruan berikutnya
  delay(2000);
}
