#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD (alamat I2C biasanya 0x27 atau 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin tombol
const int startStopBtn = 2;
const int resetBtn = 3;

// Variabel stopwatch
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
bool running = false;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(startStopBtn, INPUT); // Tombol dengan internal pull-up
  pinMode(resetBtn, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Tombol Start/Stop
  if (digitalRead(startStopBtn) == LOW) {
    delay(200); // debounce
    if (running) {
      // Pause stopwatch
      elapsedTime += millis() - startTime;
      running = false;
    } else {
      // Start stopwatch
      startTime = millis();
      running = true;
    }
  }

  // Tombol Reset
  if (digitalRead(resetBtn) == LOW) {
    delay(200); // debounce
    running = false;
    elapsedTime = 0;
  }

  // Hitung waktu
  unsigned long displayTime = elapsedTime;
  if (running) {
    displayTime += millis() - startTime;
  }

  int milliseconds = (displayTime % 1000) / 10; // tampil 2 digit ms
  int seconds = (displayTime / 1000) % 60;
  int minutes = (displayTime / 60000);

  // Tampilkan di LCD
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(minutes < 10 ? "0" : ""); lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds < 10 ? "0" : ""); lcd.print(seconds);
  lcd.print(":");
  lcd.print(milliseconds < 10 ? "0" : ""); lcd.print(milliseconds);

  delay(50);
}
