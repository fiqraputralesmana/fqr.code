#include <HCSR04.h>  // Include the library for HC-SR04
#include <Servo.h>   // Include the library for Servo

// Initialize the sensor HC-SR04 with Trigger and Echo pins
UltraSonicDistanceSensor distanceSensor(9, 10);  
Servo myServo;  // Create servo object

void setup() {
    Serial.begin(9600);    // Start serial communication
    myServo.attach(11);    // Attach the servo to pin 11
    myServo.write(0);      // Close the trash bin initially
}

void loop() {
    // Get the distance from the ultrasonic sensor
    float distance = distanceSensor.measureDistanceCm();

    Serial.print("Distance: ");
    Serial.println(distance); // Print distance for debugging

    if (distance < 15) { // If an object is detected within 15 cm
        myServo.write(90); // Open the trash bin
        delay(3000);       // Keep it open for 3 seconds
        myServo.write(0);  // Close the trash bin
        delay(2000);       // Wait for 2 seconds before next measurement
    }

    delay(500); // Delay for stabilization
}