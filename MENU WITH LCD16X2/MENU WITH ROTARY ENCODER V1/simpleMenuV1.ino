#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinA = 2;
const int pinB = 3;
const int selectButton = 4;

const char* menuItems[] = {"Menu 1", "Menu 2", "Menu 3", "Menu 4", "Menu 5"};
const int menuCount = sizeof(menuItems) / sizeof(menuItems[0]);
int currentMenuIndex = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

bool isMenuActive = true;

volatile int encoderPos = 0;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(selectButton, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(pinA), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pinB), updateEncoder, CHANGE);

  lcd.init();
  lcd.backlight();
  displayMenu();
}

void loop() {
  if (digitalRead(selectButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    if (isMenuActive) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Selected:");
      lcd.setCursor(0, 1);
      lcd.print(menuItems[currentMenuIndex]);
      isMenuActive = false;
    } else {
      displayMenu();
      isMenuActive = true;
    }
    lastDebounceTime = millis();
  }
  
  // Update the menu index based on encoder position
  if (isMenuActive) {
    if (encoderPos != 0) {
      currentMenuIndex += encoderPos;
      if (currentMenuIndex < 0) currentMenuIndex = menuCount - 1; 
      if (currentMenuIndex >= menuCount) currentMenuIndex = 0;
      displayMenu();
      encoderPos = 0; // Reset after using the encoder position
    }
  }
}

void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(">"); 
  lcd.print(menuItems[currentMenuIndex]);

  lcd.setCursor(0, 1); 
  int nextMenuIndex = (currentMenuIndex + 1) % menuCount; 
  lcd.print(" "); 
  lcd.print(menuItems[nextMenuIndex]);
}

void updateEncoder() {
  static int lastA = LOW;
  int newA = digitalRead(pinA);
  
  if (newA != lastA) {
    if (digitalRead(pinB) != newA) {
      encoderPos = 1; // Clockwise
    } else {
      encoderPos = -1; // Counterclockwise
    }
  }
  lastA = newA; 
}