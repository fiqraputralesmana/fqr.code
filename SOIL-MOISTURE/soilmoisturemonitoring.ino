#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD 16x2 dengan alamat I2C 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin sensor kelembapan tanah
const int sensorPin = A0;

void setup() {
  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight();

  // Inisialisasi komunikasi serial untuk debugging
  Serial.begin(9600);

  // Menampilkan pesan awal
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");
  delay(2000); // Tunggu 2 detik
  lcd.clear();
}

void loop() {
  // Baca data analog dari sensor kelembapan tanah
  int sensorValue = analogRead(sensorPin);

  // Konversi nilai sensor ke persentase (0-100%)
  int moisturePercent = map(sensorValue, 1023, 0, 0, 100);

  // Tentukan status kelembapan
  String status;
  if (moisturePercent >= 80) {
    status = "Very Wet";
  } else if (moisturePercent >= 60) {
    status = "Wet";
  } else if (moisturePercent >= 40) {
    status = "Moist";
  } else if (moisturePercent >= 20) {
    status = "Dry";
  } else {
    status = "Very Dry";
  }

  // Tampilkan nilai kelembapan di Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("% - ");
  Serial.println(status);

  // Tampilkan nilai kelembapan dan status di LCD
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  // Tambahkan spasi untuk menghapus karakter sisa
  lcd.print("%   "); 
  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);
  // Tambahkan spasi untuk menghapus karakter sisa
  lcd.print("    "); 

  // Tunggu 1 detik sebelum pembacaan berikutnya
  delay(1000);
}
