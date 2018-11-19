#include <FastLED.h>

#define TOP_LED_BLUE_PIN 10
#define TOP_LED_RED_PIN 11
#define TOP_LED_GREEN_PIN 9
#define STRIP_DATA_PIN 4
#define SWITCH_PIN 6

#define NUM_LEDS 29
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

#define PULSE_DELAY 5
#define PULSE_MAX 255
#define PULSE_MIN 75

#define DISCO_DELAY 250

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  pinMode(TOP_LED_BLUE_PIN, OUTPUT);
  pinMode(TOP_LED_RED_PIN, OUTPUT);
  pinMode(TOP_LED_GREEN_PIN, OUTPUT);
  pinMode(STRIP_DATA_PIN, OUTPUT);
  // pinMode(SWITCH_PIN, INPUT);

  FastLED.addLeds<LED_TYPE, STRIP_DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 255);
  }
  FastLED.show();
  topLedColor(0, 0, 255);
}

void loop() {
  bool discoLights = digitalRead(SWITCH_PIN);
  if (discoLights) {
    FastLED.setBrightness(255);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(random(0, 255), random(0, 255), random(0, 255));
      FastLED.show();

    }

    topLedColor(random(0, 255), random(0, 255), random(0, 255));
    delay(DISCO_DELAY);
  }
  else {

    for (int i = PULSE_MAX; i > PULSE_MIN; i--) {
      FastLED.setBrightness(i);
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB(0, 0, i);
      }
      FastLED.show();
      topLedColor(0, 0, i);
      delay(PULSE_DELAY);
    }
    for (int i = PULSE_MIN; i < PULSE_MAX; i++) {
      FastLED.setBrightness(i);
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB(0, 0, i);
      }
      FastLED.show();
      topLedColor(0, 0, i);
      delay(PULSE_DELAY);
    }
  }
}
void topLedColor(int red, int green, int blue) {
  analogWrite(TOP_LED_BLUE_PIN, blue);
  analogWrite(TOP_LED_RED_PIN, red);
  analogWrite(TOP_LED_GREEN_PIN, green);
}
