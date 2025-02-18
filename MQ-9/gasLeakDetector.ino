// Deklarasi pin yang digunakan
const int sensorPin = A0; // Pin analog yang terhubung ke AO sensor MQ-9
const int buzzerPin = 8;  // Pin digital yang terhubung ke buzzer
const int threshold = 100; // Ambang batas konsentrasi gas

void setup() {
  // Mengatur mode pin sensor dan buzzer
  pinMode(sensorPin, INPUT); // Mengatur pin sensor sebagai input
  pinMode(buzzerPin, OUTPUT); // Mengatur pin buzzer sebagai output
  
  // Menginisialisasi komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Membaca nilai dari sensor MQ-9
  int sensorValue = analogRead(sensorPin);
  
  // Menampilkan nilai sensor ke Serial Monitor untuk debugging
  Serial.println(sensorValue);
  
  // Memeriksa apakah nilai sensor melebihi ambang batas
  if (sensorValue > threshold) {
    // Jika nilai sensor melebihi ambang batas, mengaktifkan buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Jika nilai sensor tidak melebihi ambang batas, mematikan buzzer
    digitalWrite(buzzerPin, LOW);
  }
  
  // Menunda selama 100 ms sebelum membaca nilai sensor lagi
  delay(100);
}