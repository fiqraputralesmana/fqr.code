#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define LED_COUNT   24
#define BUTTON_PIN  2
#define BUZZER_PIN  3

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int targetLED;
int currentLED = 0;
bool spinning = true;

int level = 1;
int baseSpeed = 150; // Delay awal dalam ms (semakin kecil = lebih cepat)

void setup() {
  strip.begin();
  strip.show();
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  Serial.print("=== Level ");
  Serial.print(level);
  Serial.println(" ===");

  // Pilih LED target
  targetLED = random(LED_COUNT);
  Serial.print("Target LED: ");
  Serial.println(targetLED);

  // Tunjukkan LED target
  strip.clear();
  strip.setPixelColor(targetLED, strip.Color(255, 0, 0)); // Merah
  strip.show();
  delay(1500);

  // Mulai putaran
  spinning = true;
  while (spinning) {
    strip.clear();
    strip.setPixelColor(currentLED, strip.Color(0, 255, 0)); // Hijau
    strip.show();
    delay(max(30, baseSpeed - (level * 10))); // Semakin tinggi level, semakin cepat

    // Cek tombol
    if (digitalRead(BUTTON_PIN) == HIGH) {
      spinning = false;
      if (currentLED == targetLED) {
        Serial.println("🎉 Menang!");
        playBuzzer(1000, 200); // Buzzer nada tinggi
        showWinEffect();
        level++; // Naik level
      } else {
        Serial.print("💥 Kalah! Kamu berhenti di LED ");
        Serial.println(currentLED);
        playBuzzer(200, 500); // Buzzer nada rendah
        showLoseEffect();
        level = 1; // Reset level
      }
      delay(2000);
    }

    currentLED = (currentLED + 1) % LED_COUNT;
  }
}

void showWinEffect() {
  for (int i = 0; i < 3; i++) {
    strip.fill(strip.Color(0, 255, 0)); // Hijau
    strip.show();
    delay(150);
    strip.clear();
    strip.show();
    delay(150);
  }
}

void showLoseEffect() {
  for (int i = 0; i < 3; i++) {
    strip.fill(strip.Color(255, 0, 0)); // Merah
    strip.show();
    delay(150);
    strip.clear();
    strip.show();
    delay(150);
  }
}

void playBuzzer(int freq, int duration) {
  tone(BUZZER_PIN, freq, duration);
  delay(duration);
  noTone(BUZZER_PIN);
}
