#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "LCDActuator.h"
#include "bigDigits.h"


//LCD Define section
#define LCD_PORT 0x27 //0x3F
#define LCD_COLS 20
#define LCD_ROWS 4
