// #ifndef LCD_ACTUATOR
// #define LCD_ACTUATOR

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


bool LCD_Setup();

LiquidCrystal_I2C * LCD_Get_LCDPointer();

void LCD_Clear();

void LCD_Set_Light(bool light);

void LCD_Print_Line(String text, int line);
void LCD_Print_CenterLine(String text, int line);
