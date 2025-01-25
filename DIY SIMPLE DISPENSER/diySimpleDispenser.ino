// Menggunakan library HCSR04
#include <HCSR04.h>  

// Inisialisasi sensor HC-SR04 dengan pin Trigger dan Echo
// Pin Trigger di pin 9, Echo di pin 10
UltraSonicDistanceSensor distanceSensor(9, 10);

const int relayPin = 7;  // Pin untuk kontrol relay

void setup () {
    // Memulai komunikasi serial
    Serial.begin(9600); 
    // Set pin relay sebagai OUTPUT
    pinMode(relayPin, OUTPUT);
    // Pastikan relay dalam keadaan mati (pompa/motor mati)
    digitalWrite(relayPin, LOW);  
}

void loop () {
    // Mengukur jarak menggunakan sensor dan mencetak jarak dalam cm
    long distance = distanceSensor.measureDistanceCm();
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Jika jarak kurang dari 10 cm, aktifkan relay (pompa/motor hidup)
    if (distance > 0 && distance < 10) {
        digitalWrite(relayPin, HIGH);  // Aktifkan relay
        Serial.println("Pompa/Motor Aktif");
    } else {
        digitalWrite(relayPin, LOW);  // Nonaktifkan relay
        Serial.println("Pompa/Motor Mati");
    }

    delay(500);  // Delay 500ms sebelum pembacaan berikutnya
}
