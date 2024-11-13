#include <Servo.h>

Servo myServo;           // Membuat objek servo
const int potPin = A0;   // Pin analog untuk potensiometer
int potValue = 0;        // Variabel untuk menyimpan nilai potensiometer
int servoAngle = 0;      // Variabel untuk menyimpan sudut servo

void setup() {
  myServo.attach(9);     // Hubungkan servo ke pin digital 9
}

void loop() {
  // Baca nilai potensiometer (0 hingga 1023)
  potValue = analogRead(potPin);

  // Map nilai potensiometer menjadi nilai sudut servo (0 hingga 180 derajat)
  servoAngle = map(potValue, 0, 1023, 0, 180);

  // Atur sudut servo sesuai nilai yang sudah di-mapping
  myServo.write(servoAngle);

  delay(15); // Delay untuk menghindari pembacaan terlalu cepat
}