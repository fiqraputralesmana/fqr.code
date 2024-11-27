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
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), 
rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

/* Relay setup */
// Pin relay
const int RELAY_PIN = 6; 
// Relay aktif pada level logika rendah
const bool RELAY_ACTIVE_STATE = LOW; 
// Relay tidak aktif pada level logika tinggi
const bool RELAY_INACTIVE_STATE = HIGH; 

/* PIN setup */
const String correctPIN = "1234"; // PIN yang benar
String enteredPIN = ""; // PIN yang dimasukkan pengguna

void setup() {
  // Inisialisasi LCD dan Relay
  lcd.begin(16, 2);
  pinMode(RELAY_PIN, OUTPUT);
  lockDoor(); // Mulai dengan pintu terkunci
  
  // Tampilkan pesan awal
  lcd.print("Door Lock System");
  delay(2000);
  lcd.clear();
  lcd.print("Enter PIN:");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    processInput(key);
  }
}

void processInput(char key) {
  if (key == '*') { // Reset input PIN
    enteredPIN = "";
    lcd.clear();
    lcd.print("Enter PIN:");
    return;
  }

  if (key == '#') { // Periksa PIN
    checkPIN();
    return;
  }

  // Tambahkan input ke PIN yang sedang dimasukkan
  if (enteredPIN.length() < 4) {
    enteredPIN += key;
    lcd.setCursor(enteredPIN.length() - 1, 1);
    lcd.print('*'); // Tampilkan bintang untuk keamanan
  }
}

void checkPIN() {
  lcd.clear();
  if (enteredPIN == correctPIN) {
    unlockDoor(); // Akses berhasil
  } else {
    lcd.print("Access Denied");
    delay(2000);
    lcd.clear();
    lcd.print("Enter PIN:");
  }
  enteredPIN = ""; // Reset PIN setelah dicek
}

// Matikan relay (pintu terkunci)
void lockDoor() {
  digitalWrite(RELAY_PIN, RELAY_INACTIVE_STATE); 
  lcd.clear();
  lcd.print("Door Locked");
  delay(2000);
  lcd.clear();
  lcd.print("Enter PIN:");
}

// Aktifkan relay (pintu terbuka)
void unlockDoor() {
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_STATE); 
  lcd.clear();
  lcd.print("Access Granted");
  delay(3000); // Relay tetap aktif selama 3 detik
  lockDoor(); // Setelah 3 detik, kunci pintu kembali
}