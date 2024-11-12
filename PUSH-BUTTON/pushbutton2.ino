// Inisialisasi pin
const int buttonPin = 2;   // pin push button
const int ledPin = 13;     // pin LED

// Variabel untuk melacak status LED dan tombol
int ledState = LOW;        // Status awal LED
int buttonState;           // Status tombol saat ini
int lastButtonState = LOW; // Status tombol sebelumnya

void setup() {
  pinMode(buttonPin, INPUT);    // Mengatur pin tombol sebagai input
  pinMode(ledPin, OUTPUT);      // Mengatur pin LED sebagai output
}

void loop() {
  // Membaca status tombol
  buttonState = digitalRead(buttonPin);

  // Periksa jika tombol ditekan
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(50); // Debounce
    ledState = !ledState;           // Membalikkan status LED (toggle)
    digitalWrite(ledPin, ledState); // Mengatur LED sesuai status baru
  }

  // Simpan status tombol saat ini untuk pembacaan berikutnya
  lastButtonState = buttonState;
}
