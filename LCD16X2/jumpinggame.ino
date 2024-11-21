#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD (ubah alamat 0x27 jika berbeda)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin tombol
const int buttonJump = 2;
const int buttonReset = 3;

// Variabel posisi karakter
int charRow = 1;       // Baris karakter (1 = bawah)
int charCol = 2;       // Kolom karakter
bool jumping = false;  // Status lompat
unsigned long jumpTime = 0; // Waktu lompat

// Variabel rintangan
int obstacleCol = 15;  // Posisi kolom rintangan
unsigned long lastMoveTime = 0; // Waktu terakhir rintangan bergerak
int moveSpeed = 300;   // Kecepatan gerak rintangan (ms)

// Status permainan
bool gameOver = false;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(buttonJump, INPUT);
  pinMode(buttonReset, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Game Dino Jump!");
  lcd.setCursor(0, 1);
  lcd.print("Press Jump!");
  delay(2000); // Tampilkan pesan awal
  lcd.clear();

  // Tampilkan elemen awal
  updateGame();
}

void loop() {
  if (gameOver) {
    // Tombol reset untuk memulai ulang
    if (digitalRead(buttonReset) == HIGH) {
      delay(200); // Debounce
      resetGame();
    }
    return;
  }

  // Tombol untuk lompat
  if (digitalRead(buttonJump) == HIGH && !jumping) {
    delay(200); // Debounce
    jumping = true;
    jumpTime = millis();
    charRow = 0; // Lompat ke baris atas
    updateGame();
  }

  // Karakter turun setelah lompat
  if (jumping && millis() - jumpTime >= 500) { // 500 ms untuk waktu di udara
    jumping = false;
    charRow = 1; // Kembali ke baris bawah
    updateGame();
  }

  // Gerakkan rintangan setiap 300 ms
  if (millis() - lastMoveTime >= moveSpeed) {
    lastMoveTime = millis();
    obstacleCol--; // Rintangan bergerak ke kiri

    // Periksa tabrakan
    if (obstacleCol == charCol && charRow == 1) { // Rintangan dan karakter bertemu di baris bawah
      gameOver = true;
      lcd.setCursor(0, 0);
      lcd.print("Game Over!       ");
      lcd.setCursor(0, 1);
      lcd.print("Press Reset      ");
      return;
    }

    // Reset rintangan jika keluar dari layar
    if (obstacleCol < 0) {
      obstacleCol = 15;
    }

    updateGame();
  }
}

// Fungsi untuk memperbarui tampilan game
void updateGame() {
  lcd.clear();

  // Tampilkan karakter
  lcd.setCursor(charCol, charRow);
  lcd.print("X");

  // Tampilkan rintangan
  lcd.setCursor(obstacleCol, 1);
  lcd.print("#");
}

// Fungsi untuk reset permainan
void resetGame() {
  charRow = 1;
  charCol = 2;
  obstacleCol = 15;
  gameOver = false;
  jumping = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Dino Jump!");
  delay(1000);
  updateGame();
}
