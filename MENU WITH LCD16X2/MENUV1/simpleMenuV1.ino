#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C dengan alamat default 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definisi pin tombol
const int upButton = 2;     // Tombol "Up"
const int downButton = 3;   // Tombol "Down"
const int selectButton = 4; // Tombol "Select"

// Variabel untuk menu
const char* menuItems[] = {"Menu 1", "Menu 2", "Menu 3", "Menu 4", "Menu 5"};
const int menuCount = sizeof(menuItems) / sizeof(menuItems[0]);
int currentMenuIndex = 0;

// Variabel debounce
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200; // 200ms debounce

// Status untuk mode tampilan menu atau pilihan
bool isMenuActive = true;

void setup() {
  // Inisialisasi tombol sebagai input pull-up
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();

  // Tampilkan menu awal
  displayMenu();
}

void loop() {
  // Tombol "Up" hanya aktif saat mode menu
  if (isMenuActive && digitalRead(upButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    currentMenuIndex--;
    if (currentMenuIndex < 0) currentMenuIndex = menuCount - 1; // Kembali ke menu terakhir
    displayMenu();
    lastDebounceTime = millis(); // Reset timer debounce
  }

  // Tombol "Down" hanya aktif saat mode menu
  if (isMenuActive && digitalRead(downButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    currentMenuIndex++;
    if (currentMenuIndex >= menuCount) currentMenuIndex = 0; // Kembali ke menu pertama
    displayMenu();
    lastDebounceTime = millis(); // Reset timer debounce
  }

  // Tombol "Select"
  if (digitalRead(selectButton) == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    if (isMenuActive) {
      // Jika mode menu, tampilkan pilihan menu
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Selected:");
      lcd.setCursor(0, 1);
      lcd.print(menuItems[currentMenuIndex]);
      isMenuActive = false; // Beralih ke mode tampilan pilihan
    } else {
      // Jika mode tampilan pilihan, kembali ke menu
      displayMenu();
      isMenuActive = true; // Kembali ke mode menu
    }
    lastDebounceTime = millis(); // Reset timer debounce
  }
}

// Fungsi untuk menampilkan menu di LCD
void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0); // Baris pertama
  lcd.print(">"); // Tanda kursor
  lcd.print(menuItems[currentMenuIndex]); // Menu aktif

  // Tampilkan menu berikutnya jika ada
  lcd.setCursor(0, 1); // Baris kedua
  int nextMenuIndex = (currentMenuIndex + 1) % menuCount; // Looping menu
  lcd.print(" "); // Tanpa kursor
  lcd.print(menuItems[nextMenuIndex]);
}
