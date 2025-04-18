// Pin Joystick
const int VRx = A0;
const int VRy = A1;
const int SW = 2;

// Pin LED
const int ledUp = 3;
const int ledDown = 4;
const int ledRight = 5;
const int ledLeft = 6;

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); // Tombol joystick

  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xVal = analogRead(VRx);
  int yVal = analogRead(VRy);

  // Reset LED
  digitalWrite(ledUp, LOW);
  digitalWrite(ledDown, LOW);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);

  // Kontrol arah
  if (yVal > 800) {
    digitalWrite(ledUp, HIGH);
  } else if (yVal < 200) {
    digitalWrite(ledDown, HIGH);
  }

  if (xVal < 200) {
    digitalWrite(ledLeft, HIGH);
  } else if (xVal > 800) {
    digitalWrite(ledRight, HIGH);
  }

  delay(100);
}
