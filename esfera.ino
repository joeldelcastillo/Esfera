
#include <FastLED.h>

#define NUM_STRIPS 19
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS_PER_STRIP 13
#define BRIGHTNESS 64

//Enlazar todos los leds por software
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

int NUM_PER_TIRA[] = {66, 108, 144, 177, 206, 229};
//Usar el codigo Python para calcular las distancias
int LEDS_DISTANCES[] = {0, 66, 174, 318, 495, 701};
//Usar el codigo Python para calcular el arreglo de angulos
float alpha[] = {1.83, 2.01, 2.17, 2.33, 2.5, 2.66}
///Usar el codigo Python para el total de leds
int maxLEDS = 930;
//Distancia entre cada led
float dLed = 0.07;
//distancia del radio de la esfera
float radio = 0.75;

CRGB leds[maxLEDS];

void setup()
{
  delay(1000);
  //Tipo de led, input, color
  FastLED.addLeds<LED_TYPE, LED_PIN_A, COLOR_ORDER>(leds, 0, NUM_LEDS_A);
  FastLED.addLeds<LED_TYPE, LED_PIN_B, COLOR_ORDER>(leds, NUM_LEDS_A, NUM_LEDS_B);
  FastLED.addLeds<LED_TYPE, LED_PIN_C, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B, NUM_LEDS_C);
  FastLED.addLeds<LED_TYPE, LED_PIN_D, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C, NUM_LEDS_D);
  FastLED.addLeds<LED_TYPE, LED_PIN_E, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D, NUM_LEDS_E);
  //6 Controles
  FastLED.addLeds<LED_TYPE, LED_PIN_F, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E, NUM_LEDS_F);
  //7 Controles
  FastLED.addLeds<LED_TYPE, LED_PIN_G, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F, NUM_LEDS_G);
  //8 Controles
  FastLED.addLeds<LED_TYPE, LED_PIN_H, COLOR_ORDER>(leds, NUM_LEDS_A + NUM_LEDS_B + NUM_LEDS_C + NUM_LEDS_D + NUM_LEDS_E + NUM_LEDS_F + NUM_LEDS_G, NUM_LEDS_H);

  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  FastLED.clear();
  
  for (int i = 0; i < NUM_STRIPS; i++)
  {
    for (int j = 0; j < NUM_PER_TIRA[i]; j++)
    {

      //coordenadas polares
      //beta = map(j, 0, LED[i], 0, 2*PI)
      //k = ceil((radio*sin(alpha[i])*beta)/dLed)

      color = map(i, 0, NUM_STRIPS, 0, 255);
      leds[LEDS_DISTANCES[i] + j] = CRGB(255, color, color);
    }
  }
  FastLED.show();
}

//void map(value, start1, start1, stop1, stop2) {
//  float outgoing = start1 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
//  return outgoing;
//}
