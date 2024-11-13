const int buzzerPin = 9; // Pin untuk buzzer/speaker

// Array untuk pin tombol dan frekuensi nada
const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8};
const int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Nada: do, re, mi, fa, sol, la, si

void setup() {
  pinMode(buzzerPin, OUTPUT);
  
  // Atur setiap pin tombol sebagai input
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  bool notePlayed = false;

  // Cek apakah ada tombol yang ditekan
  for (int i = 0; i < 7; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) {
      tone(buzzerPin, notes[i]); // Mainkan nada sesuai tombol
      notePlayed = true;
      break; // Keluar dari loop setelah memainkan satu nada
    }
  }
  
  // Matikan nada jika tidak ada tombol yang ditekan
  if (!notePlayed) {
    noTone(buzzerPin);
  }
}
