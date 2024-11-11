// Program LED Blink
// Pin yang terhubung dengan LED, biasanya pin 13 pada Arduino UNO
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT); // Atur pin sebagai OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH); // Nyalakan LED
  delay(1000); // Tunggu selama 1 detik

  digitalWrite(ledPin, LOW); // Matikan LED
  delay(1000); // Tunggu selama 1 detik
}