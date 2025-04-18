#include <Adafruit_NeoPixel.h> // Include the NeoPixel library

#define PIN 6           // Data pin connected to the WS2812B LED strip
#define NUMPIXELS 16    // Total number of LEDs in the strip

// Create an instance of the NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();    // Initialize the LED strip
  strip.show();     // Turn off all LEDs at startup
}

void loop() {
  rainbowCycle(10); // Run the rainbow cycle animation with a delay of 10ms
}

// Function to create a continuous rainbow animation across all LEDs
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  // Loop through 256 color values (0-255), creating a full rainbow cycle
  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      // Set each pixel to a color calculated by the Wheel function
      // The color is shifted by j to create movement
      strip.setPixelColor(i, Wheel((i * 256 / strip.numPixels() + j) & 255));
    }
    strip.show();      // Update the LED strip with new colors
    delay(wait);       // Short delay to control animation speed
  }
}

// Function to generate a color from a position in the color wheel (0–255)
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    // From red to blue
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    // From blue to green
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  // From green to red
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
