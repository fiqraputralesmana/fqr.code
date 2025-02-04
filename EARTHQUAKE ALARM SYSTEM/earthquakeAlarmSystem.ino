const int sensorPin = 2;  // Pin sensor getaran (D2)
const int buzzerPin = 9;  // Pin buzzer (D9)

void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorState = digitalRead(sensorPin); // Membaca sensor getaran
    
    if (sensorState == HIGH) {  // Jika ada getaran terdeteksi
        Serial.println("Gempa terdeteksi!");
        digitalWrite(buzzerPin, HIGH); // Aktifkan buzzer
        delay(1000); // Buzzer menyala selama 1 detik
        digitalWrite(buzzerPin, LOW); // Matikan buzzer
    }
}