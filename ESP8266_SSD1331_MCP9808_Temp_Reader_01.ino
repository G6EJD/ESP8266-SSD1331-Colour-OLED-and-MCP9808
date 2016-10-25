/*************************************************** 
  This is a example sketch demonstrating the graphics
  capabilities of the SSD1331 library  for the 0.96" 
  16-bit Color OLED with SSD1331 driver chip

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/684

  These displays use SPI to communicate, 4 or 5 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// You can use any (4 or) 5 pins 
#define sclk D5 //--- connect this to the display module SCL pin (Serial Clock)
#define mosi D7 //--- connect this to the display module SDA pin (Seiral Data)
#define rst  D6 //--- connect this to the display module RES pin (Reset)
#define dc   D8 //--- connect this to the display module DC  pin (Data or Command)
#define cs   D0 //--- connect this to the display module CS  pin (Chip Select)

// Color definitions
#define	BLACK           0x0000
#define	BLUE            0x0006
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define BACKGROUND      0x0000

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Option 1: to use you can define any pins but it's a little slower, the pins defined above are the ESP8266 hardware pins
//Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);  

// Option 2: to use this you must use the hardware SPI pins 
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

float tempC,maxC,minC,last_C,last_minC,last_maxC;

void setup(void) {
  Serial.begin(9600);
  display.begin();
  Wire.begin(D3,D4); // (SCL, SDA)
  if (!tempsensor.begin()) {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  } else Serial.println("Found MCP9808");
  maxC = 0;
  minC = 100;
  display.fillScreen(BACKGROUND);
  display.setCursor(0,0);
}

void loop() {
  display.setTextColor(GREEN);
  display.setTextSize(2);
  display.setCursor(0,5);
  
  tempsensor.shutdown_wake(0);   // Don't remove this line! required before reading temp
  tempC = tempsensor.readTempC();
  if (tempC >= maxC) maxC = tempC;
  if (tempC <= minC) minC = tempC;

  if (last_C != tempC) {
    display.fillRect(10,5,96,15,BACKGROUND);
    display.print(" ");
    display.print(tempC,1);
    display.print(char(247));
    display.print("C");
  }
  display.setTextSize(1);
  if (last_maxC != maxC) {
    display.setTextColor(RED);
    display.fillRect(15,30,75,8,BACKGROUND);
    display.setCursor(15,30);
    display.print("Max:");
    display.print(maxC,1);
    display.print(char(247));
    display.print("C");
  }
  if (last_minC != minC) {
    display.setCursor(15,40);
    display.setTextColor(BLUE);
    display.fillRect(15,40,75,7,BACKGROUND);
    display.print("Min:");
    display.print(minC,1);
    display.print(char(247));
    display.print("C");
  }
  last_C = tempC;
  last_minC = minC;
  last_maxC = maxC;
  delay(1000);
}

