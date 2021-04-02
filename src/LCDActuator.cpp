#include "main.h"
#include "LCDActuator.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C *lcd;
/*
byte drop[8] = {
    0b00100,
    0b01010,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    0b00000,
    0b00000};
//lcd.createChar(0, drop);
lcd.write(byte(0));
  lcd.print(char(223));
*/

byte Lock[] = {
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};



//LiquidCrystal_I2C *lcd = nullptr;


bool LCD_Setup()
{
    lcd = new LiquidCrystal_I2C(LCD_PORT, LCD_COLS, LCD_ROWS); //port = 0x27 for PCF8574T and PCF8574AT for 0x3F, 16 cols, 2 raws
    lcd->init();
    return true;    
}

LiquidCrystal_I2C * LCD_Get_LCDPointer()
{
    return lcd;
}

void LCD_Clear()
{
    lcd->clear();
}

void LCD_Set_Light(bool light)
{
    if (light)
    {
        lcd->backlight();
    }
    else
    {
        lcd->noBacklight();
    }
}

void LCD_Print_Right(String text)
{
    if (text.length() == 0)
    {
        return;
    }
    if (text.length() < 20)
    {
        String empty = "";
        for (unsigned int i=0; i < 20 - text.length(); i++)
        {
            empty += " ";
        }
        text = text + empty;
    }
    lcd->print(text);
}

void LCD_Print_Center(String text)
{
    if (text.length() == 0)
    {
        return;
    }

    if (text.length() < 20)
    {
        String empty = "";
        for (unsigned int i=0; i < (20 - text.length()) / 2; i++)
        {
            empty += " ";
        }
        text = empty + text + empty;
    }    
    lcd->print(text);        
}


/*
    @denis.ovcharenko
    Добавил, чтобы объеденить функции (LCD_Print_Line# LCD_Print_CenterLine#) 
    в одну (они по сути одинаковые, зависит только от агрумента - номер строки)

    Потом надо будет по проекту отрефакторить этот момент
*/

/*
    void LCD_Print_Line(String text, int line = 0)
    выводит текст (Sting text) в строке экрана указанной 
    в аргументе line (по умолчанию = 0)
    используя функцию LCD_Print_Right(text)
    line находится в диапазоне от 0 до (LCD_ROWS - 1)
*/
void LCD_Print_Line(String text, int line = 0)
{
    if (line >= LCD_ROWS) {
        return;
    }
    lcd->setCursor(0, line);
    LCD_Print_Right(text);
}

/*
    void LCD_Print_CenterLine(String text, int line = 0)
    выводит текст (Sting text) в строке экрана указанной 
    в аргументе line (по умолчанию = 0)
    используя функцию LCD_Print_Center(text)
    line находится в диапазоне от 0 до (LCD_ROWS - 1)
*/
void LCD_Print_CenterLine(String text, int line = 0)
{
    if (line >= LCD_ROWS) {
        return;
    }
    lcd->setCursor(0, line);
    LCD_Print_Center(text);
}