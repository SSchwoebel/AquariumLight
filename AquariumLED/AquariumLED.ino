#include "FastLED.h"
#include "pins_arduino.h"

FASTLED_USING_NAMESPACE

#define DATA_PINS_START 2
#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 40
#define BRIGHTNESS 150
#define FRAMES_PER_SECOND  100

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {
  
  delay(3000);

  FastLED.addLeds<WS2812B,DATA_PINS_START+0,GRB>(leds[0],NUM_LEDS_PER_STRIP);//BRG
  FastLED.addLeds<WS2812B,DATA_PINS_START+1,GRB>(leds[1],NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B,DATA_PINS_START+2,GRB>(leds[2],NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B,DATA_PINS_START+3,GRB>(leds[3],NUM_LEDS_PER_STRIP);

  FastLED.setBrightness(BRIGHTNESS);

  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    if((i%3)==0) {
      leds[0][i] = CRGB::Red;
    }
    else {
      leds[0][i] = CRGB::Blue;
    }
  }
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[1][i] = CRGB::White;
  }
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    if((i%3)==0) {
      leds[2][i] = CRGB::Red;
    }
    else {
      leds[2][i] = CRGB::Blue;
    }
  }
  FastLED.show();
}

void loop() {

  //for(int x = 0; x < NUM_STRIPS; x++) {
  //    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
  //      leds[x][i] = CRGB::White;
  //    }
  //   }
  //EVERY_N_MILLISECONDS(1000/FRAMES_PER_SECOND){FastLED.show();} 

}
