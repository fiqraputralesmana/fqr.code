// Pustaka yang diperlukan
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

// Inisialisasi LCD 16x2 I2C
// Alamat I2C LCD mungkin berbeda, coba 0x3F jika tidak bekerja
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Inisialisasi RTC DS1307
RTC_DS1307 rtc;

void setup() {
  // Inisialisasi komunikasi serial untuk debugging
  Serial.begin(9600);

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();

  // Inisialisasi RTC
  if (!rtc.begin()) {
    lcd.setCursor(0, 1);
    lcd.print("RTC Gagal");
    Serial.println("RTC tidak ditemukan!");
    while (1); // Hentikan program jika RTC tidak ditemukan
  }

  // Periksa apakah RTC berjalan
  if (!rtc.isrunning()) {
    Serial.println("RTC tidak berjalan!");
    // Set waktu RTC jika tidak berjalan (misalnya, set ke 1 Januari 2023, 00:00:00)
    // rtc.adjust(DateTime(2023, 1, 1, 0, 0, 0));
  }
}

void loop() {
  // Baca waktu dari RTC
  DateTime now = rtc.now();

  // Tampilkan hari dan tanggal pada baris pertama LCD
  lcd.setCursor(5, 0);
  // Tampilkan tanggal dengan nol di depan jika perlu
  if (now.day() < 10) {
    lcd.print("0"); // Tambahkan nol di depan untuk tanggal
  }
  lcd.print(now.day(), DEC);
  lcd.print("/");

  // Tampilkan bulan dengan nol di depan jika perlu
  if (now.month() < 10) {
    lcd.print("0"); // Tambahkan nol di depan untuk bulan
  }
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  
  // Tampilkan hari dalam format teks
  lcd.setCursor(1, 0); 
  switch (now.dayOfTheWeek()) {
    case 0: lcd.print("Min,"); break;
    case 1: lcd.print("Sen,"); break;
    case 2: lcd.print("Sel,"); break;
    case 3: lcd.print("Rab,"); break;
    case 4: lcd.print("Kam,"); break;
    case 5: lcd.print("Jum,"); break;
    case 6: lcd.print("Sab,"); break;
  }

  // Tampilkan waktu pada baris kedua LCD
  lcd.setCursor(4, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  // Tambahkan nol di depan jika menit < 10
  if (now.minute() < 10) lcd.print("0"); 
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  // Tambahkan nol di depan jika detik < 10
  if (now.second() < 10) lcd.print("0"); 
  lcd.print(now.second(), DEC);

  // Tunggu 1 detik sebelum memperbarui waktu
  delay(1000);
}
