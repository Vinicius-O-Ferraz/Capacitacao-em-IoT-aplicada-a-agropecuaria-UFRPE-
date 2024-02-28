#include <Adafruit_NeoPixel.h>
#define pixels 8             
#define STRIPS 8              
#define switch_pin 13        

typedef struct RGBLED_t {
  uint8_t R;
  uint8_t G;
  uint8_t B;
} RGBLED;

const RGBLED green = {0, 255, 0};
const RGBLED red = {255, 0, 0};

Adafruit_NeoPixel strips[STRIPS];

const uint8_t pins[STRIPS] = {9, 8, 7, 6, 5, 4, 3, 2};

void setStairs(struct RGBLED_t ledOff, struct RGBLED_t ledOn) {

  bool switch_state = digitalRead(switch_pin);

  for (int x = 0; x < STRIPS; x++) {
    for (int y = 0; y < pixels; y++) {

      if (y <= x) {
        if (switch_state) {
          strips[x].setPixelColor(y, strips[x].Color(ledOff.R, ledOff.G, ledOff.B));
        } else {
          strips[x].setPixelColor(y, strips[x].Color(ledOn.R, ledOn.G, ledOn.B));
        }
      } else {
        strips[x].setPixelColor(y, strips[x].Color(0, 0, 0));
      }
    }
    strips[x].show();
  }
  delay(100);
}

void setup() {
  for (int i = 0; i < STRIPS; i++) {
    strips[i] = Adafruit_NeoPixel(pixels, pins[i], NEO_GRB + NEO_KHZ800);
    strips[i].begin();
  }
  pinMode(switch_pin, OUTPUT);
}

void loop() {
  setStairs(red, green);
  delay(100);
}
