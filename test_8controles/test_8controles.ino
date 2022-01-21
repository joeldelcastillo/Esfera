/*
En este ejemplo dividimos un solo arreglo en 5 puntos de control, 

*/



#include <FastLED.h>

#define NUM_STRIPS 8
#define LED_PIN_A 2
#define LED_PIN_B 4
#define LED_PIN_C 18
#define LED_PIN_D 19
#define LED_PIN_E 21
#define LED_PIN_F 22
#define LED_PIN_G 23
#define LED_PIN_H 25
#define NUM_LEDS_A 315
#define NUM_LEDS_B 382
#define NUM_LEDS_C 478
#define NUM_LEDS_D 555
#define NUM_LEDS_E 568
#define NUM_LEDS_F 535
#define NUM_LEDS_G 599
#define NUM_LEDS_H 340

//6 Controles
#define NUM_LEDS (NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F)
//7 Controles
//#define NUM_LEDS (NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F + NUM_LEDS_G)
//8 Controles
//#define NUM_LEDS (NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F + NUM_LEDS_G + NUM_LEDS_H)


#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  64

CRGB leds[NUM_LEDS];


/*********************************************************************/
void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN_A, COLOR_ORDER>(leds, 0, NUM_LEDS_A);
  FastLED.addLeds<LED_TYPE, LED_PIN_B, COLOR_ORDER>(leds, NUM_LEDS_A, NUM_LEDS_B);
  FastLED.addLeds<LED_TYPE, LED_PIN_C, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B, NUM_LEDS_C);
  FastLED.addLeds<LED_TYPE, LED_PIN_D, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C, NUM_LEDS_D);
  FastLED.addLeds<LED_TYPE, LED_PIN_E, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D, NUM_LEDS_E);
  //6 Controles
  FastLED.addLeds<LED_TYPE, LED_PIN_F, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E, NUM_LEDS_F);
  //7 Controles
//  FastLED.addLeds<LED_TYPE, LED_PIN_F, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F, NUM_LEDS_G);
  //8 Controles
//  FastLED.addLeds<LED_TYPE, LED_PIN_F, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F + NUM_LEDS_G, NUM_LEDS_H);

  FastLED.setBrightness(BRIGHTNESS);
}


void loop() {

  FastLED.clear();
  //función para prender todos los leds, si no funciona comentar y probar el codigo comentado
  fill_solid(leds, NUM_LEDS, CRGB(255, 0, 0));
  FastLED.show();
  delay(1000);

  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(1000);

/*
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(255, 0, 0);
  }
  FastLED.show();
  delay(1000);
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
  delay(1000);
*/

}
