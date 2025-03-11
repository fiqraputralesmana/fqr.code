#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

char message[] = "Hello World!";
int x, minX;

void rightToLeft(char message[]) {
   display.clearDisplay();
   display.setTextSize(2); // Ukuran teks
   display.setTextColor(SSD1306_WHITE);
   display.setCursor(x, 20); // Pastikan hanya satu baris
   display.print(message);
   display.display();

   x -= 5; // Kecepatan scrolling
   if (x < minX) x = display.width(); // Reset posisi jika keluar layar
}

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);

  x = display.width();
  minX = -12 * strlen(message); // Lebar teks dalam pixel
}

void loop() {
  rightToLeft(message);
  delay(50); // Atur kecepatan scrolling
}
