#include <Adafruit_NeoPixel.h>
#define PIN 				2	// pino de dados do NeoPixel
#define NUMPIXELS 			8 	// quantidade de pixels na fita
#define NUMSTRIPS           8   // quantidade de fitas
#define DELAY				100 // tempo de delay entre pixels
#define RAINBOW_NUM_COLORS 	7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

typedef struct RGBLED_t {
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGBLED;

const RGBLED VIOLET = {148, 0, 211};
const RGBLED INDIGO = {75, 0, 130};
const RGBLED BLUE   = {0, 0, 255};
const RGBLED GREEN  = {0, 255, 0};
const RGBLED YELLOW = {255, 255, 0};
const RGBLED ORANGE = {255, 127, 0};
const RGBLED RED    = {255, 0, 0};

RGBLED rainbow_colors[NUMPIXELS] = {VIOLET, INDIGO, BLUE, GREEN, YELLOW, ORANGE, RED};


Adafruit_NeoPixel strips[NUMSTRIPS];

const uint8_t PINS[NUMSTRIPS]={2,3,4,5,6,7,8,9};

void setRGBLED(uint8_t LED_index, struct RGBLED_t LED) {
    pixels.setPixelColor(LED_index, pixels.Color(LED.R, LED.G, LED.B));
}

void setPixel2D(uint8_t x, uint8_t y, struct RGBLED_t ledValues) {
    //TODO
}

void setup() {
  	// inicializa a biblioteca NeoPixel
  	 for (int i = 0; i <= NUMSTRIPS; i++) {
        strips[i] = Adafruit_NeoPixel(NUMPIXELS, PINS[i], NEO_GRB + NEO_KHZ800);
        strips[i].begin();
    }
}

void loop() {
    for(int i = 0; i <= NUMSTRIPS;i++){
    uint32_t color = strips[i].Color(148, 211, 211);
    
    for (int j = 0; j <= NUMPIXELS; j++) {
	    strips[i].setPixelColor(j, color);
    }
    strips[i].show();
    delay(DELAY);
    
  }
	
    
}
