#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Konfigurasi DHT22
#define DHTPIN 2      // Pin data DHT22 terhubung ke D2
#define DHTTYPE DHT22 // Tipe sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi LCD 16x2 dengan I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C biasanya 0x27 atau 0x3F

void setup() {
  // Inisialisasi LCD
  lcd.begin(16, 2); // Tambahkan parameter kolom dan baris
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initialization..");
  
  // Inisialisasi DHT22
  dht.begin();
  
  // Pesan siap
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");
  lcd.setCursor(3, 1);
  lcd.print("Monitoring");
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
  lcd.print("Temp: ");
  lcd.print(suhu);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(kelembapan);
  lcd.print(" %");

  // Delay sebelum pembaruan berikutnya
  delay(2000);
}
