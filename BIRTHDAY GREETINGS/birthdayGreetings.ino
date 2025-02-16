#include <Wire.h> // Library untuk komunikasi I2C
#include <Adafruit_GFX.h> // Library grafis dasar untuk perangkat OLED
#include <Adafruit_SSD1306.h> // Library khusus untuk perangkat OLED SSD1306

#define SCREEN_WIDTH 128 // Lebar layar OLED
#define SCREEN_HEIGHT 64 // Tinggi layar OLED

// Pin I2C
#define OLED_RESET     -1 // Reset pin # (atau -1 jika tidak digunakan)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Inisialisasi objek display OLED

// Pin buzzer
#define BUZZER_PIN 9

// Definisi frekuensi nada manual
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_C6 1047

// Melodi dan durasi
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, // Selamat
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, // Ulang
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, // Tahun
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, // Selamat
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, // Ulang
  NOTE_C6, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C6, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B4, NOTE_C5 // Tahun
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, // Selamat
  4, 4, 4, 4, 4, 4, // Ulang
  4, 4, 4, 4, 4, 4, 4, // Tahun
  4, 4, 4, 4, 4, 4, // Selamat
  4, 4, 4, 4, 4, 4, 4, // Ulang
  2, 4, 4, 4, 2, 4, 4, 4, 4, 4 // Tahun
};

int thisNote = 0; // Indeks untuk melacak nada yang sedang dimainkan

void setup() {
  // Inisialisasi layar OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Alamat I2C OLED
    Serial.println(F("SSD1306 allocation failed")); // Pesan jika inisialisasi gagal
    for(;;); // Loop tak terbatas jika inisialisasi gagal
  }
  delay(2000); // Tunggu 2 detik sebelum melanjutkan
  display.clearDisplay(); // Bersihkan layar OLED
  display.setTextSize(1); // Set ukuran teks
  display.setTextColor(SSD1306_WHITE); // Set warna teks
  display.setCursor(0, 0); // Set posisi kursor
  display.println("Selamat Ulang Tahun!"); // Tampilkan pesan
  display.display(); // Update layar OLED

  // Inisialisasi buzzer
  pinMode(BUZZER_PIN, OUTPUT); // Set pin buzzer sebagai output
}

void loop() {
  int noteDuration = 1000 / noteDurations[thisNote]; // Hitung durasi nada saat ini
  tone(BUZZER_PIN, melody[thisNote], noteDuration); // Mainkan nada saat ini

  int pauseBetweenNotes = noteDuration * 1.30; // Hitung jeda antara nada
  delay(pauseBetweenNotes); // Tunggu selama jeda

  noTone(BUZZER_PIN); // Berhenti memainkan nada

  thisNote++; // Pindah ke nada berikutnya
  if (thisNote == 30) { // Jika semua nada telah dimainkan
    thisNote = 0; // Reset indeks nada
    delay(5000); // Tunggu 5 detik sebelum memainkan ulang
  }
}
