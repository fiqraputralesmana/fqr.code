#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HCSR04.h>  // Pastikan HCSR04-2.0.0 sudah diinstal

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// HC-SR04 versi 2.0.0
#define TRIG_PIN 9
#define ECHO_PIN 10
// Perhatikan nama class
UltraSonicDistanceSensor sensor(TRIG_PIN, ECHO_PIN); 

void setup() {
  Serial.begin(9600);

  // Inisialisasi OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Penggaris");
  display.display();
  delay(1000);
}

void loop() {
  float distance = sensor.measureDistanceCm();  // fungsi versi 2.0.0
  Serial.println(distance);

  // Tampilkan ke OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Penggaris Digital");
  display.setTextSize(2);
  display.setCursor(0,20);
  display.print(distance,1);
  display.println(" cm");
  display.display();

  delay(200); // Update tiap 200ms
}
