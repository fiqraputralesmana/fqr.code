#include <HCSR04.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inisialisasi LCD dengan alamat I2C (sesuaikan alamat jika berbeda)
UltraSonicDistanceSensor distanceSensor(9, 10); // Sensor ultrasonik di pin digital 9 dan 10

void setup() {
    lcd.init();      // Inisialisasi LCD dengan ukuran 16x2
    lcd.backlight();       // Aktifkan backlight LCD
    lcd.setCursor(4, 0);
    lcd.print("Penggaris");
    lcd.setCursor(5, 1);
    lcd.print("Digital");
    delay(2000);           // Tampilkan pesan awal selama 2 detik
    lcd.clear();
}

void loop() {
    // Baca jarak dalam cm menggunakan library HCSR04
    float distanceCm = distanceSensor.measureDistanceCm();

    // Jika nilai sensor -1 (tidak terdeteksi), set distanceCm menjadi 0
    if (distanceCm == -1) {
        distanceCm = 0;
    }

    // Mengonversi jarak ke satuan meter dan inchi
    float distanceM = distanceCm / 100;             // Konversi ke meter
    float distanceIn = distanceCm * 0.393701;       // Konversi ke inchi

    // Tampilkan jarak dalam cm di baris pertama
    lcd.setCursor(0, 0);
    lcd.print("Jarak: ");
    lcd.print(distanceCm);
    lcd.print(" cm   ");

    // Tampilkan jarak dalam meter dan inchi di baris kedua
    lcd.setCursor(0, 1);
    lcd.print(distanceM);
    lcd.print(" m ");
    lcd.print(distanceIn);
    lcd.print(" in    ");

    delay(500);  // Tunggu 500ms sebelum pembacaan berikutnya
}
