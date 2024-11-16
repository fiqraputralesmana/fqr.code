#include <Servo.h> // Library Servo untuk mengontrol servo

Servo myServo; // Membuat objek Servo
int pos = 0;   // Posisi awal servo

void setup() {
  myServo.attach(9); // Menentukan pin digital tempat servo terhubung (contoh: pin 9)
}

void loop() {
  // Gerakkan servo dari 0° ke 180°
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);  // Mengatur posisi servo
    delay(15);           // Tunggu 15ms untuk gerakan yang halus
  }

  // Gerakkan servo dari 180° kembali ke 0°
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);  // Mengatur posisi servo
    delay(15);           // Tunggu 15ms untuk gerakan yang halus
  }
}
