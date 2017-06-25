#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//Data pin
#define PIN            6

//Strand size
#define NUMPIXELS      200

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

// Size of each ring (may not use all of them)
const int BIG_RING_SIZE = 111;
const int RING_1_SIZE = 14;
const int RING_2_SIZE = 16;
const int RING_3_SIZE = 16;
const int RING_4_SIZE = 18;
const int RING_5_SIZE = 0;
const int RING_6_SIZE = 0;
const int RING_7_SIZE = 0;
const int RING_8_SIZE = 0;

struct RGB
{
  char m_red;
  char m_green;
  char m_blue;
};

RGB ring_1;
RGB ring_2;
RGB ring_3;
RGB ring_4;
RGB ring_5;
RGB ring_6;
RGB ring_7;
RGB ring_8;

RGB main_ring_color_1[BIG_RING_SIZE];



uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<255; j++) {
    for(i=0; i<BIG_RING_SIZE; i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<BIG_RING_SIZE; i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}

void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif


  ring_1.m_red = 0; ring_1.m_green = 255; ring_1.m_blue = 255;
  ring_2.m_red = 255; ring_2.m_green = 0; ring_2.m_blue = 255;
  ring_3.m_red = 255; ring_3.m_green = 255; ring_3.m_blue = 0;
  ring_4.m_red = 255; ring_4.m_green = 165; ring_4.m_blue = 0;
  ring_5.m_red = 255; ring_5.m_green = 255; ring_5.m_blue = 255;
  ring_6.m_red = 255; ring_6.m_green = 255; ring_6.m_blue = 255;
  ring_7.m_red = 255; ring_7.m_green = 255; ring_7.m_blue = 255;
  ring_8.m_red = 255; ring_8.m_green = 255; ring_8.m_blue = 255;
  
  int c=60;
  for (int i = 0; i<BIG_RING_SIZE; i++)
  {
    c++;
    main_ring_color_1[i].m_red = (255/110)*c;
    main_ring_color_1[i].m_green = (255/110)*(110-c);
    main_ring_color_1[i].m_blue = 0;
    if(c>110)c=60;
  }
  
  pixels.begin();
  
}



int animate_counter=0;
char acl=0;
void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  animate_counter++;

  for(int i=0;i<BIG_RING_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(main_ring_color_1[i].m_red,main_ring_color_1[i].m_green,main_ring_color_1[i].m_blue)); 
  }

  for(int i=BIG_RING_SIZE;i<BIG_RING_SIZE+RING_1_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_1.m_red,ring_1.m_green,ring_1.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_2.m_red,ring_2.m_green,ring_2.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_3.m_red,ring_3.m_green,ring_3.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_4.m_red,ring_4.m_green,ring_4.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_5.m_red,ring_5.m_green,ring_5.m_blue)); 
  }  
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE+RING_6_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_6.m_red,ring_6.m_green,ring_6.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE+RING_6_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE+RING_6_SIZE+RING_7_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_7.m_red,ring_7.m_green,ring_7.m_blue)); 
  }
  for(int i=BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE+RING_6_SIZE+RING_7_SIZE;i<BIG_RING_SIZE+RING_1_SIZE+RING_2_SIZE+RING_3_SIZE+RING_4_SIZE+RING_5_SIZE+RING_6_SIZE+RING_7_SIZE+RING_8_SIZE;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(ring_8.m_red,ring_8.m_green,ring_8.m_blue)); 
  }

  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(delayval); // Delay for a period of time (in milliseconds).

  
}
