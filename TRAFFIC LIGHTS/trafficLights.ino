// Definisikan pin untuk lampu lalu lintas
int redPins[4] = {13, 10, 5, 2};
int yellowPins[4] = {12, 9, 6, 3};
int greenPins[4] = {11, 8, 7, 4};

// Waktu untuk setiap lampu (dalam milidetik)
int redTime = 5000;    
int yellowTime = 2000; 
int greenTime = 5000;  

void setup() {
    // Atur pin sebagai OUTPUT
    for (int i = 0; i < 4; i++) {
        pinMode(redPins[i], OUTPUT);
        pinMode(yellowPins[i], OUTPUT);
        pinMode(greenPins[i], OUTPUT);
    }
}

void loop() {
    for (int lane = 0; lane < 4; lane++) {
        setTrafficLight(lane);
    }
}

// Fungsi untuk mengatur lampu lalu lintas untuk jalur tertentu
void setTrafficLight(int lane) {
    // Matikan semua lampu terlebih dahulu
    for (int i = 0; i < 4; i++) {
        digitalWrite(greenPins[i], LOW);
        digitalWrite(yellowPins[i], LOW);
        digitalWrite(redPins[i], HIGH);
    }

    // Hidupkan lampu hijau untuk jalur yang aktif
    digitalWrite(greenPins[lane], HIGH);
    digitalWrite(redPins[lane], LOW);
    
    // Menyalakan lampu hijau selama waktu yang ditentukan
    delay(greenTime);
    
    // Matikan lampu hijau
    digitalWrite(greenPins[lane], LOW);
    
    // Menyalakan lampu kuning untuk jalur yang aktif
    digitalWrite(yellowPins[lane], HIGH);
    delay(yellowTime);
    
    // Matikan lampu kuning
    digitalWrite(yellowPins[lane], LOW);
}