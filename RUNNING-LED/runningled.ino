#define NUM_LEDS 12
#define START_PIN 2

void setup() {
  // Inisialisasi setiap pin LED sebagai output
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(START_PIN + i, OUTPUT);
  }
}

void loop() {
  // Efek 1: Running LED dari kiri ke kanan dan kanan ke kiri
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(START_PIN + i, HIGH);
    delay(100);
    digitalWrite(START_PIN + i, LOW);
  }
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(START_PIN + i, HIGH);
    delay(100);
    digitalWrite(START_PIN + i, LOW);
  }

  // Efek 2: LED Menyala Berpasangan dari Tengah ke Ujung
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(START_PIN + i, HIGH);
    digitalWrite(START_PIN + NUM_LEDS - 1 - i, HIGH);
    delay(100);
    digitalWrite(START_PIN + i, LOW);
    digitalWrite(START_PIN + NUM_LEDS - 1 - i, LOW);
  }

  // Efek 3: LED Menyala dari Ujung ke Tengah
  for (int i = NUM_LEDS / 2 - 1; i >= 0; i--) {
    digitalWrite(START_PIN + i, HIGH);
    digitalWrite(START_PIN + NUM_LEDS - 1 - i, HIGH);
    delay(100);
    digitalWrite(START_PIN + i, LOW);
    digitalWrite(START_PIN + NUM_LEDS - 1 - i, LOW);
  }

  // Efek 4: Knight Rider (LED Berjalan Bolak-Balik)
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i > 0) digitalWrite(START_PIN + i - 1, LOW); // Matikan LED sebelumnya
    digitalWrite(START_PIN + i, HIGH);               // Nyalakan LED saat ini
    delay(100);
  }
  for (int i = NUM_LEDS - 2; i >= 0; i--) {
    digitalWrite(START_PIN + i + 1, LOW);
    digitalWrite(START_PIN + i, HIGH);
    delay(100);
  }

  // Efek 5: Semua LED Berkedip Bersamaan
  for (int j = 0; j < 5; j++) { // Ulangi 5 kali
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(START_PIN + i, HIGH);
    }
    delay(200);
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(START_PIN + i, LOW);
    }
    delay(200);
  }

  // Efek 6: LED Menyala dari Tengah Keluar dan Kembali ke Tengah
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(START_PIN + NUM_LEDS / 2 - 1 - i, HIGH);
    digitalWrite(START_PIN + NUM_LEDS / 2 + i, HIGH);
    delay(100);
  }
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(START_PIN + NUM_LEDS / 2 - 1 - i, LOW);
    digitalWrite(START_PIN + NUM_LEDS / 2 + i, LOW);
    delay(100);
  }
}
