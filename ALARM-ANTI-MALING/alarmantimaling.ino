// Pin sensor PIR dan buzzer
const int pirPin = 2;    // Pin digital untuk sensor PIR
const int buzzerPin = 8; // Pin digital untuk buzzer

void setup() {
  // Inisialisasi pin
  pinMode(pirPin, INPUT);    // Sensor PIR sebagai input
  pinMode(buzzerPin, OUTPUT); // Buzzer sebagai output

  // Inisialisasi komunikasi serial untuk debugging
  Serial.begin(9600);
  
  // Menampilkan status awal
  Serial.println("Alarm Anti-Maling Aktif");
  Serial.println("Menunggu deteksi gerakan...");
}

void loop() {
  // Membaca data dari sensor PIR
  int motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH) { // Jika gerakan terdeteksi
    Serial.println("Gerakan terdeteksi! Alarm berbunyi!");
    digitalWrite(buzzerPin, HIGH); // Nyalakan buzzer
    delay(1000);                   // Buzzer berbunyi selama 1 detik
    digitalWrite(buzzerPin, LOW);  // Matikan buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Pastikan buzzer mati saat tidak ada gerakan
  }

  delay(500); // Tunggu sebelum pembacaan berikutnya
}
