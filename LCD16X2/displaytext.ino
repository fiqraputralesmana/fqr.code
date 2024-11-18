#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C (biasanya 0x27 atau 0x3F)
// Sesuaikan alamat jika berbeda
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();

  // Baris pertama (Fqr Code)
  lcd.setCursor((16 - 8) / 2, 0);  // 8 adalah jumlah karakter "Fqr Code"
  lcd.print("Fqr Code");

  // Baris kedua (Hello World!)
  lcd.setCursor((16 - 12) / 2, 1);  // 12 adalah jumlah karakter "Hello World!"
  lcd.print("Hello World!");
}

void loop() {
  // Tidak ada proses dalam loop
}
}