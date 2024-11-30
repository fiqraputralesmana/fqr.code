#include <LiquidCrystal.h>
#include <Keypad.h>

/* Display */
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

/* Keypad setup */
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

/* Variables for calculation */
String input = ""; // Input string to collect numbers and operators
float num1 = 0, num2 = 0; // Numbers for calculation
char operation = 0; // Current operation ('+', '-', '*', '/')
bool isSecondNum = false; // Flag to indicate second number entry

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setCursor((16 - 10) / 2, 0);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
  lcd.print("Enter number:");
}

void loop() {
  char key = keypad.getKey(); // Get key input from keypad

  if (key) {
    // Handle 'C' (Clear)
    if (key == 'C') {
      clearInput();
      return;
    }

    // Handle '=' (Compute)
    if (key == '=') {
      computeResult();
      return;
    }

    // Handle operators
    if (key == '+' || key == '-' || key == '*' || key == '/') {
      if (!isSecondNum) {
        operation = key;
        num1 = input.toFloat(); // Convert input to first number
        input = ""; // Reset input for the second number
        isSecondNum = true; // Switch to entering the second number
        lcd.clear(); // Clear LCD before displaying operator
        lcd.print("Operation: ");
        lcd.print(operation);
        return;
      }
    }

    // Handle numbers
    if (key >= '0' && key <= '9') {
      input += key; // Add key to input
      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}

void computeResult() {
  if (isSecondNum && operation) {
    num2 = input.toFloat(); // Convert input to second number
    float result = 0;

    // Perform the operation
    switch (operation) {
      case '+': result = num1 + num2; break;
      case '-': result = num1 - num2; break;
      case '*': result = num1 * num2; break;
      case '/': 
        if (num2 != 0) {
          result = num1 / num2;
        } else {
          lcd.clear();
          lcd.print("Error: Div by 0");
          delay(2000);
          clearInput();
          return;
        }
        break;
    }

    // Display the result
    lcd.clear();
    lcd.print("Result:");
    lcd.setCursor(0, 1);
    lcd.print(result);
    delay(3000); // Show result for 3 seconds

    // Reset for next calculation
    clearInput();
  }
}

void clearInput() {
  input = "";
  num1 = 0;
  num2 = 0;
  operation = 0;
  isSecondNum = false;
  lcd.clear();
  lcd.print("Enter number:");
}
