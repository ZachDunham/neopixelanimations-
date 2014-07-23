//grouping lights via serial commands//
#include <Adafruit_NeoPixel.h>
 
#define PIN 9
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
 
int pixel = 0;            // pixel number that you're changing
int red = 255;              // red value 
int green;           // green value
int blue;            // blue value
int state; 
int array1[10] = {1,2,3,4}; //space for group1
int array2[10] = {5,6,7,8}; //space for group2
int array3[10] = {9,10,11,12}; //space for group3


void setup() {
  Serial.begin(57600);     // initialize serial communication
  Serial.setTimeout(10);  // set serial timeout
  strip.begin();          // initialize pixel strip
  strip.show();           // Initialize all pixels to 'off'
}
 
void loop() {
 if (Serial.available()) 
  {
  int group = Serial.parseInt();
   switch(group){
    case 1: 
    group1();
    break;
    case 2:
    group2();
    break;
    case 3:
    group3();
    break;
    case 4:
    turnoffleds();
    }  
  }
}


//parses serial data to fill array 

void group1(){
  //declare leds in array
    for (int i=0; i<10; i++){
    array1[i] = Serial.parseInt();
    delay(1);
    }
    
    //set aray color 
    for (int i = 0; i < 5; i = i + 1) {
    strip.setPixelColor(array1[i], array1[5], array1[6], array1[7]);// set the color for this pixel
    strip.show();  // refresh the strip
    }
    
    
    //clear array
    for (int i = 0; i > 10; i = --i) {
    array1[i] = 0;
    }
}
void group2(){
  //declare leds in array
    for (int i=0; i<10; i++){
    array2[i] = Serial.parseInt();
    delay(1);
    }
    
    //set aray color 
    for (int i = 0; i < 5; i = i + 1) {
    strip.setPixelColor(array2[i], array2[5], array2[6], array2[7]);// set the color for this pixel
    strip.show();  // refresh the strip
    }
    
    
    //clear array
    for (int i = 0; i > 10; i = --i) {
    array2[i] = 0;
    }
}

void group3(){
  //declare leds in array
    for (int i=0; i<10; i++){
    array3[i] = Serial.parseInt();
    delay(1);
    }
    
    //set aray color 
    for (int i = 0; i < 5; i = i + 1) {
    strip.setPixelColor(array3[i], array3[5], array3[6], array3[7]);// set the color for this pixel
    strip.show();  // refresh the strip
    }
    
    
    //clear array
    for (int i = 0; i > 10; i = --i) {
    array3[i] = 0;
    }
}

void colorfade(int array){
    for (i = 0 i < 255; i++){
     red 

void turnoffleds() {
 for ( int i = 0; i <= 59; i++ ) {
  strip.setPixelColor(i, 0, 0, 0);// set the color for this pixel
  strip.show();  // refresh the strip
 }
}

