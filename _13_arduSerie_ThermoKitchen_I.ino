/*
  Project name:
     Arduino 1-Wire Thermocouple in the kitchen- 13 # arduSerie
     Flavour I
     Hex File: _13_arduSerie_ThermoKitchen_I.ino
   Revision History:
      20160627:
      Description:
      This serie makes several experiments with thermocouple in the home kitchen.
      The purpose is to record the temperature over time. We will experiment with 
      cheese bread, sandwich cheese, gelatin and more. Here we will make the 
      thermocouple works without any components. Get on!!! Check it over !!!

  MCU:              Arduino v.1.6.7 - @16MHz  http://www.arduino.cc/
  IC Chip:          MAX31850K 
      https://www.adafruit.com/products/1727
  Library: Adafruit_MAX31855_lib 
      https://github.com/adafruit/Adafruit-MAX31855-library
  Connections:
      See you.tube vid:
  Based on https://learn.adafruit.com/thermocouple/using-a-thermocouple
      Tutorial - Adafruit Learning System
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License v3 as published by
   the Free Software Foundation
*/
/***************************************************
  This is an example for the Adafruit Thermocouple Sensor w/MAX31855K
  Designed specifically to work with the Adafruit Thermocouple Sensor
  ----> https://www.adafruit.com/products/269
  These displays use SPI to communicate, 3 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <SPI.h>
#include "Adafruit_MAX31855.h"

// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins.
#define MAXDO   3
#define MAXCS   4
#define MAXCLK  5

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

// Example creating a thermocouple instance with hardware SPI (Uno/Mega only)
// on a given CS pin.
//#define MAXCS   10
//Adafruit_MAX31855 thermocouple(MAXCS);

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
#define Serial SerialUSB
#endif

void setup() {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  Serial.begin(9600);

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  Serial.print("Internal Temp = ");
  Serial.println(thermocouple.readInternal());

  double c = thermocouple.readCelsius();
  if (isnan(c)) {
    Serial.println("Something wrong with thermocouple!");
  } else {
    Serial.print("C = ");
    Serial.println(c);
  }
  //Serial.print("F = ");
  //Serial.println(thermocouple.readFarenheit());

  delay(1000);
}
