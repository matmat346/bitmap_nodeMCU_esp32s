
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#include "bitmaps.h"
#include "bitmapsLarge.h"

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS        5
  #define TFT_RST        0 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC  1

#define TFT_MOSI 21  // Data out
#define TFT_SCLK 18  // Clock out
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
	tft.initR(INITR_BLACKTAB);
	tft.setRotation(0);
	tft.fillScreen(ST7735_BLACK);


//Case 2: Multi Colored Images/Icons
  int h = 160,w = 128, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row, pgm_read_word(evive_in_hand + buffidx));
      buffidx++;
    } // end pixel
  }
}

void loop() {
}
