#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD: alamat I2C, jumlah kolom, jumlah baris
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti 0x27 sesuai dengan alamat I2C LCD Anda

// Text yang akan ditampilkan
String text = "Hello, this is a running text example!";
int textLength;
int displayWidth = 16; // Panjang layar (16 karakter)
int position = 0;

void setup() {
  lcd.init();         // Inisialisasi LCD
  lcd.backlight();    // Menyalakan backlight
  textLength = text.length();
}

void loop() {
  // Bersihkan layar
  lcd.clear();

  // Tampilkan bagian teks sesuai posisi saat ini
  if (position <= textLength - displayWidth) {
    lcd.setCursor(0, 0); // Set ke baris pertama
    lcd.print(text.substring(position, position + displayWidth));
  } else {
    // Tampilkan karakter terakhir dan kembali ke awal
    lcd.setCursor(0, 0);
    lcd.print(text.substring(position, textLength) + text.substring(0, displayWidth - (textLength - position)));
  }

  // Delay untuk kecepatan scrolling
  delay(200);

  // Perbarui posisi
  position = (position + 1) % textLength;
}
