#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define CLK_PIN    13
#define Data_PIN   11
#define CS_PIN     10

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.displayClear();
  myDisplay.displayText(
    "SELAMAT DATANG DI CHANNEL YOUTUBE FQR.CODE",
    PA_CENTER,
    100,
    0,
    PA_SCROLL_LEFT,
    PA_SCROLL_LEFT
  );
}

void loop() {
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
