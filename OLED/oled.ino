#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definisikan ukuran layar OLED dan pin I2C
#define SCREEN_WIDTH 128 // Lebar layar OLED
#define SCREEN_HEIGHT 64 // Tinggi layar OLED

// Buat objek OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Inisialisasi layar OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Tunggu 2 detik

  // Bersihkan layar OLED
  display.clearDisplay();

  // Tampilkan teks "Hello, world!"
  display.setTextSize(1);      // Ukuran teks
  display.setTextColor(SSD1306_WHITE); // Warna teks
  display.setCursor(0,0);     // Posisi teks
  display.println(F("Hello, world!"));
  display.display();          // Tampilkan ke layar OLED
}

void loop() {
  // Kode di sini akan dijalankan secara berulang
}