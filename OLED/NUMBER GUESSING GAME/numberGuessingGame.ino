#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED display dimensions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Button pins
const int incrementButtonPin = 2;
const int decrementButtonPin = 3;
const int submitButtonPin = 4;

// Variables
int guess = 1;
int randomNumber;
bool newGame = true;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Initialize button pins as inputs
  pinMode(incrementButtonPin, INPUT_PULLUP);
  pinMode(decrementButtonPin, INPUT_PULLUP);
  pinMode(submitButtonPin, INPUT_PULLUP);

  // Generate a random number
  randomSeed(analogRead(0));
  randomNumber = random(1, 11); // Random number between 1 and 10
}

void loop() {
  // Check if it's a new game
  if (newGame) {
    displayNewGame();
    newGame = false;
  }

  // Read button states
  int incrementState = digitalRead(incrementButtonPin);
  int decrementState = digitalRead(decrementButtonPin);
  int submitState = digitalRead(submitButtonPin);

  // Increment guess
  if (incrementState == LOW) {
    guess++;
    if (guess > 10) guess = 10;
    delay(200); // Debounce delay
  }

  // Decrement guess
  if (decrementState == LOW) {
    guess--;
    if (guess < 1) guess = 1;
    delay(200); // Debounce delay
  }

  // Submit guess
  if (submitState == LOW) {
    checkGuess();
    delay(200); // Debounce delay
  }

  // Display the current guess
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Guess a number:");
  display.setTextSize(2);
  display.setCursor(40, 20);
  display.print(guess);
  display.display();
}

void displayNewGame() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("New Game!");
  display.println("Guess a number:");
  display.println("between 1 and 10.");
  display.display();
  delay(2000); // Show message for 2 seconds
}

void checkGuess() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Your guess: ");
  display.print(guess);
  display.setCursor(0, 10);
  if (guess < randomNumber) {
    display.println("Too low!");
  } else if (guess > randomNumber) {
    display.println("Too high!");
  } else {
    display.println("Correct!");
    display.setCursor(0, 20);
    display.println("You win!");
    newGame = true;
    randomNumber = random(1, 11); // Generate a new random number
  }
  display.display();
  delay(2000); // Show message for 2 seconds
}
