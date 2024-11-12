const int potPin = A0; // Pin potensiometer
const int ledPin = 13;  // Pin LED yang mendukung PWM

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED sebagai output
  pinMode(potPin, INPUT);  // Mengatur pin potensiometer sebagai input
}

void loop() {
  int potValue = analogRead(potPin); // Baca nilai potensiometer (0-1023)
  
  // Peta nilai potensiometer (0-1023) ke PWM (0-255)
  int ledBrightness = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(ledPin, ledBrightness); // Atur kecerahan LED sesuai dengan nilai yang dipetakan

  delay(10); // Sedikit penundaan untuk mengurangi pembacaan terlalu cepat
}
