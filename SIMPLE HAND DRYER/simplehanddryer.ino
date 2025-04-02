#include <HCSR04.h>  // Using the HCSR04 library

// Initialize the HC-SR04 sensor with Trigger and Echo pins
UltraSonicDistanceSensor distanceSensor(9, 10);  // Trigger pin on pin 9, Echo on pin 10

const int relayPin = 7;  // Pin for relay control

void setup () {
    Serial.begin(9600);  // Start serial communication
    pinMode(relayPin, OUTPUT);  // Set relay pin as OUTPUT
    digitalWrite(relayPin, LOW);  // Ensure relay is off (pump/motor off)
}

void loop () {
    // Measure distance using the sensor and print the distance in cm
    long distance = distanceSensor.measureDistanceCm();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If the distance is less than 10 cm, activate the relay (motor on)
    if (distance > 0 && distance < 10) {
        digitalWrite(relayPin, HIGH);  // Activate relay
        Serial.println("Motor Active");
    } else {
        digitalWrite(relayPin, LOW);  // Deactivate relay
        Serial.println("Motor Off");
    }

    delay(500);  // Delay 500ms before the next reading
}