// Variabel untuk menyimpan nilai kelembapan
int moisture = 0; 
// Pin analog untuk sensor kelembapan
const int sensorPin = A1; 
// Array pin digital untuk LED
const int ledPins[] = {8, 9, 10, 11, 12}; 

void setup() {
  // Mengatur pin sensor sebagai input
  pinMode(sensorPin, INPUT); 
  // Memulai komunikasi serial
  Serial.begin(9600); 
  // Mengatur pin LED sebagai output
  for (int pin : ledPins) pinMode(pin, OUTPUT); 
}

void loop() {
  // Menunggu untuk stabil
  delay(10); 
  // Membaca nilai kelembapan
  moisture = analogRead(sensorPin); 
  // Mengirim nilai kelembapan ke monitor serial
  Serial.println(moisture); 

  // Mematikan semua LED
  for (int pin : ledPins) digitalWrite(pin, LOW);

  // Menentukan LED yang akan menyala berdasarkan nilai kelembapan
  if (moisture >= 800) digitalWrite(ledPins[0], HIGH); // LED 8
  else if (moisture >= 600) digitalWrite(ledPins[1], HIGH); // LED 9
  else if (moisture >= 400) digitalWrite(ledPins[2], HIGH); // LED 10
  else if (moisture >= 200) digitalWrite(ledPins[3], HIGH); // LED 11
  else digitalWrite(ledPins[4], HIGH); // LED 12

  // Menunggu sebelum mengulangi loop
  delay(100); 
}