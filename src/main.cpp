#include "main.h"

/**
 *  Цифры в формате 3х4
 
 */
// ЦИФРА (0)
int DIGIT_0[12] = {
      0,  1,  2,
      3,  32, 4,
      3,  32, 4,
      5,  6,  7
  };
// ЦИФРА (1)
  int DIGIT_1[12] = {
	  0,  1, 32, 
	  32, 3, 32,
	  32, 3, 32,
	  32, 6, 32
  };
// ЦИФРА (2)
  int DIGIT_2[12] = {
	  0,  1,   2, 
	  32, 32,  4,
	  3,  6,   7,
	  5,  6,   7
  };
// ЦИФРА (3)
  int DIGIT_3[12] = {
	  0,   1,  2, 
	  32,  0,  7,
	  32,  32, 4,
	  5,   6,  7
  };
// ЦИФРА (4)
  int DIGIT_4[12] = {
	  0,  32,  2, 
	  3,  1,   4,
	  32, 32,  4,
	  32, 32,  7
  };
// ЦИФРА (5)
  int DIGIT_5[12] = {
	  0,  1,  2, 
	  3,  1,  2,
	  32, 32, 4,
	  5,  6,  7
  };
  // ЦИФРА (6)
  int DIGIT_6[12] = {
	  0,  1,  2, 
	  3,  1,  2,
	  3,  32, 4,
	  5,  6,  7
  };
// ЦИФРА (7)
  int DIGIT_7[12] = {
	  0,  1,  2, 
	  32, 32, 4,
	  32, 32, 4,
	  32, 32, 7
  };
// ЦИФРА (8)
  int DIGIT_8[12] = {
	  0,  1,  2, 
	  3,  1,  4,
	  3,  32, 4,
	  5,  6,  7
  };
// ЦИФРА (9)
  int DIGIT_9[12] = {
	  0,  1,  2, 
	  3,  1,  4,
	  32, 32, 4,
	  5,  6,  7
  };


void setup()
{
  Serial.begin(9600);

  LiquidCrystal_I2C *lcd = LCD_Get_LCDPointer();

  LCD_Setup();

  lcd->backlight();
  lcd->clear();
  lcd->home();

  bigDigit_Setup();

}

void loop()
{

  LiquidCrystal_I2C *lcd = LCD_Get_LCDPointer();

  lcd->backlight();

  delay(5000);
  lcd->clear();
  bigDidit_DrawSymbol(DIGIT_0, 0);
  bigDidit_DrawSymbol(DIGIT_1, 3);

  bigDidit_DrawSymbol(DIGIT_2, 7);
  bigDidit_DrawSymbol(DIGIT_3, 10);

  bigDidit_DrawSymbol(DIGIT_4, 14);
  bigDidit_DrawSymbol(DIGIT_5, 17);

  Serial.println("Draw the simbols");

  delay(5000);
  lcd->clear();
  bigDidit_DrawSymbol(DIGIT_9, 0);
  bigDidit_DrawSymbol(DIGIT_8, 3);

  bigDidit_DrawSymbol(DIGIT_7, 7);
  bigDidit_DrawSymbol(DIGIT_6, 10);

  bigDidit_DrawSymbol(DIGIT_5, 14);
  bigDidit_DrawSymbol(DIGIT_4, 17);
}
