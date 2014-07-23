//controlling neopixels through max/msp over serial, via serialparse with the fastled library.  

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 9
 
int pixel;            // pixel number that you're changing
int red ;              // red value 
int green;           // green value
int blue;            // blue value
int state;  // which switch case statement 
int gl;  // low end of group range 
int gh;  // high end of group range 

CRGB leds[NUM_LEDS];
CRGB ledsgroup[NUM_LEDS];
 
void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN, RGB>(leds, NUM_LEDS);
  Serial.begin(115200);     // initialize serial communication
  Serial.setTimeout(10);  // set serial timeou
}
 
void loop() {
  // listen for serial:
  if (Serial.available() > 0) {
    if (Serial.read() == 'C') {    // string should start with C
      state = Serial.parseInt();   // " " switch case 
      pixel = Serial.parseInt();   // then an ASCII number for pixel number
      red = Serial.parseInt();     // then an ASCII number for red
      green = Serial.parseInt();   // then an ASCII number for green
      blue = Serial.parseInt();    // then an ASCII number for blue
      gl = Serial.parseInt();      // " " group low 
      gh = Serial.parseInt();      // " " group high
     
      switch (state){
        case 0:
        turnoffleds(pixel);
       // Serial.print("2");
        break;
     
        case 1:
        turnonleds(pixel, red, green, blue);  
        //Serial.print("1");
        break;
     
        case 2:
        turnonledsgroup(gl, gh, red, green, blue);
        break;
     
        case 3:
        alloff();
        break;
        }
     }
    
}
}

void turnonleds(int pixel, int red, int green, int blue) {
  leds[pixel].g = red;
  leds[pixel].r = green;
  leds[pixel].b = blue;
  FastLED.show();  // refresh the strip
}

void turnoffleds(int pixel) {
 leds[pixel] = CRGB::Black;
  FastLED.show();  // refresh the strip
}

void alloff(){
  for(int i = 0; i < 60; i++){
  leds[i] = CRGB::Black;
   FastLED.show();  // refresh the strip
  }
}  

void turnonledsgroup(int gl, int gh, int red, int green, int blue) {
  for(int i = gl; i < gh; i++){
  leds[i].g = red;
  leds[i].r = green;
  leds[i].b = blue;
  FastLED.show();  // refresh the strip
  }
}


