// Deklarasi pin untuk LED
const int led1 = 8;
const int led2 = 9;

// Interval delay dalam milidetik
const int delayTime = 500;

void setup() {
  // Set pin sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // Nyalakan LED pertama dan matikan LED kedua
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(delayTime);

  // Matikan LED pertama dan nyalakan LED kedua
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(delayTime);
}
