// Inisialisasi pin
const int buttonPin = 2;  // pin push button
const int ledPin = 13;    // pin LED

void setup() {
  pinMode(buttonPin, INPUT); // Mengatur pin tombol sebagai input
  pinMode(ledPin, OUTPUT);   // Mengatur pin LED sebagai output
}

void loop() {
  // Membaca keadaan tombol
  int buttonState = digitalRead(buttonPin);

  // Jika tombol ditekan (HIGH), LED akan menyala
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED
  }
}
