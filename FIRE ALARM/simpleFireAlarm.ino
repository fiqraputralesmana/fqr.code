#define FLAME_SENSOR_PIN 2  // Pin digital untuk sensor api
#define BUZZER_PIN 9        // Pin untuk buzzer

void setup() {
    pinMode(FLAME_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int flame_detected = digitalRead(FLAME_SENSOR_PIN);

    if (flame_detected == LOW) { // LOW berarti ada api
        Serial.println("Api terdeteksi! Alarm menyala!");
        digitalWrite(BUZZER_PIN, HIGH); // Nyalakan buzzer
        delay(500); // Buzzer berbunyi 0.5 detik
        digitalWrite(BUZZER_PIN, LOW);
        delay(500); // Jeda 0.5 detik
    } else {
        Serial.println("Tidak ada api.");
        digitalWrite(BUZZER_PIN, LOW); // Matikan buzzer
    }

    delay(100);
}
