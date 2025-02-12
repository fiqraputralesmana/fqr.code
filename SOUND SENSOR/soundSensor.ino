// Define the pins used
const int sensorPin = A0; // Analog pin for the sound sensor
const int ledPin = 13;    // Digital pin for the LED

// Define the sound threshold
const int ambangSuara = 500; // You can adjust this value as needed

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Start serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the value from the sound sensor
  int suara = analogRead(sensorPin);
  
  // Print the sound value to the serial monitor
  Serial.println(suara);
  
  // Check if the sound exceeds the threshold
  if (suara > ambangSuara) {
    // If the sound exceeds the threshold, turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // If the sound is below the threshold, turn off the LED
    digitalWrite(ledPin, LOW);
  }
  
  // Wait a moment before reading again
  delay(100);
}
