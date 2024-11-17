// Pin definisi
const int ldrPin = A0; // Pin LDR
const int ledPin = 13; // Pin LED

// Threshold cahaya (atur sesuai kebutuhan)
const int lightThreshold = 500; // Nilai analog dari LDR

void setup() {
  pinMode(ledPin, OUTPUT);   // Set pin LED sebagai output
  pinMode(ldrPin, INPUT);    // Set pin LDR sebagai input
  Serial.begin(9600);        // Inisialisasi komunikasi serial
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Membaca nilai analog dari LDR

  // Debug: Cetak nilai LDR ke Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Logika kontrol LED
  if (ldrValue > lightThreshold) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED
  }

  delay(100); // Tunggu 100ms sebelum pembacaan berikutnya
}
