#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 		8 	
#define NUMSTRIPS       8	
#define DELAY			100 

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
const RGBLED WITHE	= {255,255,255};


Adafruit_NeoPixel strips[NUMSTRIPS];
const uint8_t PINS[NUMSTRIPS]={9,8,7,6,5,4,3,2};

void setPixel2D(uint8_t x, uint8_t y, struct RGBLED_t ledValues) {
    if(x >= NUMSTRIPS || y >= NUMPIXELS){
    	return; 
  }
	
  for (int i = 0; i < NUMSTRIPS; i++) {
    if (i == x) {
      strips[i].setPixelColor(y, strips[i].Color(ledValues.R, ledValues.G, ledValues.B));
      
      strips[i].show(); 
    }
  }
}



void setup(){  
    for (int i = 0; i < NUMSTRIPS; i++) {
        strips[i] = Adafruit_NeoPixel(NUMPIXELS, PINS[i], NEO_GRB + NEO_KHZ800);
        strips[i].begin();
    }
}

void loop(){
  	setPixel2D(4,5,GREEN);
    delay(DELAY);

}
