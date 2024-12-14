// Konfigurasi pin untuk 7-segment display
const int segmentPins[] = {9, 10, 11, 12, 13, 8, 7}; // A, B, C, D, E, F, G

// Representasi biner dari setiap angka (0-9) pada 7-segment display
// Setiap bit mewakili sebuah segmen (A-G), dengan 1 = ON dan 0 = OFF
const byte numbers[10] = {
  0b1111110, // 0
  0b0110000, // 1
  0b1101101, // 2
  0b1111001, // 3
  0b0110011, // 4
  0b1011011, // 5
  0b1011111, // 6
  0b1110000, // 7
  0b1111111, // 8
  0b1111011  // 9
};

void setup() {
  // Atur semua pin segmen sebagai OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int num = 0; num <= 9; num++) {
    displayNumber(num); // Tampilkan angka saat ini
    delay(1000);        // Tunggu selama 1 detik
  }
}

// Fungsi untuk menampilkan angka pada 7-segment display
void displayNumber(int num) {
  byte segments = numbers[num]; // Dapatkan representasi biner dari angka

  for (int i = 0; i < 7; i++) {
    // Tulis HIGH atau LOW ke setiap pin segmen berdasarkan nilai bit
    digitalWrite(segmentPins[i], (segments & (1 << (6 - i))) ? HIGH : LOW);
  }
}
