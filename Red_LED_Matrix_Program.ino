/*
 * RED LED Light Control Program 
 * 
 * This program controls two strips of red LED lights connected to an Arduino.
 * The lights turn on red and stay on continuously while the Arduino has power.
 * 
 * Physical Setup:
 * - Arduino microcontroller
 * - Two strips of lights, each with 512 individual LED diodes
 * - Wire from Light Strip 1 connects to pin 6 on Arduino
 * - Wire from Light Strip 2 connects to pin 9 on Arduino
 */


// This line tells the Arduino how to talk to the LED light strips
#include <Adafruit_NeoPixel.h>


// SETTINGS SECTION
// These lines set up the basic information the Arduino needs to know


// Settings for Light Strip #1:
// Light Strip #1 plugs into pin 6 on the Arduino
// Light Strip #1 has 512 individual LED diodes
#define PIN1         6 
#define NUM_LEDS1    256    

// Settings for Light Strip #2:
// Light Strip #2 plugs into pin 9 on the Arduino
// Light Strip #2 has 512 individual LED diodes
#define PIN2         9
#define NUM_LEDS2    256

// Set Brightness here
// Brightness level: 0 = completely dark, 255 = maximum brightness
#define BRIGHTNESS   160


// CREATING THE LIGHT CONTROLLERS
// These lines create two "controllers" - one for each light strip
// Think of these as remote controls that can command each light strip
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS2, PIN2, NEO_GRB + NEO_KHZ800);
// The technical details (NEO_GRB + NEO_KHZ800) tell Arduino what type of lights these are


// STARTUP INSTRUCTIONS
// This section runs one time when you first turn on the Arduino


void setup() {
  
  
  
  strip1.begin();                        // Gets Light Strip #1 ready to receive commands  
  strip1.setBrightness(BRIGHTNESS);      // Sets Strip #1 to the brightness level we chose above
  strip1.show();                         // Makes sure all bulbs start in the "off" state

   
  strip2.begin();                        // Gets Light Strip #2 ready to receive commands 
  strip2.setBrightness(BRIGHTNESS);      // Sets Strip #2 to the brightness level we chose above
  strip2.show();                         // Makes sure all bulbs start in the "off" state
}

void loop() {
  // Sets all pixels to red on the first strip
  setAll(strip1, 255, 0, 0);
  delay(500);

  // Sets all pixels to red on the second strip
  setAll(strip2, 255, 0, 0);
  delay(500);
}

  // Sets every pixel in a strip to the same color
void setAll(Adafruit_NeoPixel &strip, byte red, byte green, byte blue) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, red, green, blue);
  }
  strip.show();
}
