#include "bigDigits.h"
#include <LiquidCrystal_I2C.h>
#include "LCDActuator.h"


/**
 *  Цифры в формате 3х4
 * 
 * 
 * BUG: Непонятно что с областью видимости...
 * 
 * 
//Цифра (0)
 int symbol_0[12] = {
      0,  1,  2,
      3,  32, 4,
      3,  32, 4,
      5,  6,  7
  };

// Цифра (1)
  int symbol_1[12] = {
	  0,  1, 32, 
	  32, 3, 32,
	  32, 3, 32,
	  32, 6, 32
  };

 //... И Т.Д..... 
  int symbol_2[12] = {
	  0,  1,   2, 
	  32, 32,  4,
	  3,  6,   7,
	  5,  6,   7
  };

  int symbol_3[12] = {
	  0,   1,  2, 
	  32,  0,  7,
	  32,  32, 4,
	  5,   6,  7
  };

  int symbol_4[12] = {
	  0,  32,  2, 
	  3,  1,   4,
	  32, 32,  4,
	  32, 32,  7
  };

  int symbol_5[12] = {
	  0,  1,  2, 
	  3,  1,  2,
	  32, 32, 4,
	  5,  6,  7
  };

  int symbol_6[12] = {
	  0,  1,  2, 
	  3,  1,  2,
	  3,  32, 4,
	  5,  6,  7
  };

  int symbol_7[12] = {
	  0,  1,  2, 
	  32, 32, 4,
	  32, 32, 4,
	  32, 32, 7
  };

  int symbol_8[12] = {
	  0,  1,  2, 
	  3,  1,  4,
	  3,  32, 4,
	  5,  6,  7
  };

  int symbol_9[12] = {
	  0,  1,  2, 
	  3,  1,  4,
	  32, 32, 4,
	  5,  6,  7
  };

*/


/**
 * Наши кастомные символы для прошики в модуль экрана, 
 * с помошью которых будем рисовать цифры и буквы тоже может быть
 * размером 3x4

byte bar0[8] = {
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00001,		// 0x01
  B00011,		// 0x03
  B00111,		// 0x07
  B01111		// 0x0F
};

byte bar1[8] = {
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B11111,		// 0x1F
  B11111,		// 0x1F
  B11111,		// 0x1F
  B11111		// 0x1F
};

byte bar2[8] = {
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B10000,		// 0x10
  B11000,		// 0x18
  B11100,		// 0x1C
  B11110		// 0x1E
};

byte bar3[8] = {
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111,		// 0x0F
  B01111		// 0x0F
};

byte bar4[8] = {
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110,		// 0x1E
  B11110		// 0x1E
};

byte bar5[8] = {
  B01111,		// 0x0F
  B00111,		// 0x07
  B00011,		// 0x03
  B00001,		// 0x01
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000		// 0x00
};

byte bar6[8] = {
  B11111,		// 0x1F
  B11111,		// 0x1F
  B11111,		// 0x1F
  B11111,		// 0x1F
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000		// 0x00
};

byte bar7[8] = {
  B11110,		// 0x1E
  B11100,		// 0x1C
  B11000,		// 0x18
  B10000,		// 0x10
  B00000,		// 0x00
  B00000,		// 0x00
  B00000,		// 0x00
  B00000		// 0x00
};
*/

/**
Чтобы небыло простыни - упакуем в 16-ричном формате:
*/
byte custom_char_0[8] = {0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F};
byte custom_char_1[8] = {0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F};
byte custom_char_2[8] = {0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1C, 0x1E};
byte custom_char_3[8] = {0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F};
byte custom_char_4[8] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
byte custom_char_5[8] = {0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00};
byte custom_char_6[8] = {0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00};
byte custom_char_7[8] = {0x1E, 0x1C, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00};

 /**
 * Здесь будем делать начальные установки
 */
  bool bigDigit_Setup()
  {
	  bigDigit_AllocateCustomChars();
	  return true;
}

/**
 *  Размещаем 8 кастомных символов в памяти экрана
*/
bool bigDigit_AllocateCustomChars() {
	LiquidCrystal_I2C *lcd = LCD_Get_LCDPointer();
    lcd->createChar(0, custom_char_0);
    lcd->createChar(1, custom_char_1);
    lcd->createChar(2, custom_char_2);
    lcd->createChar(3, custom_char_3);
    lcd->createChar(4, custom_char_4);
    lcd->createChar(5, custom_char_5);
    lcd->createChar(6, custom_char_6);
    lcd->createChar(7, custom_char_7);
    return true;
}

/**
 * Рисуем символ 3Х4 по матрице из одномерного массива:
 * 0, 1,  2, 	// Это цифра (0)
 * 3, 32, 4, 	// - 0, 1, 2, 3, 4, 5, 6, 7 - это наши кастомные символы
 * 3, 32, 4, 	// - 32 - это пустой символ
 * 5, 6,  7
 * 
  *  int symbol_9[12] = {
	  0,  1,  2, 
	  3,  1,  4,
	  32, 32, 4,
	  5,  6,  7
  };

 * В позиции заданой параметром position - от начала строки
 * 
 * BUG: Наблюдается артефакт, когда символ уходит за 
 * облать экрана. надо разобраться....
 */
void bigDidit_DrawSymbol(int matrix[], int position = 0)
{
	
	LiquidCrystal_I2C *lcd = LCD_Get_LCDPointer();

	int n, i, idx = 0;
	// Проходимся по рядам
	for (n = 0; n < LCD_DIGIT_SIZE_ROW; n++) {
		// Теперь по колонкам
		for (i = 0; i < LCD_DIGIT_SIZE_COL; i++) {
			// Устанавливаем курсор в нужною позицию
			lcd->setCursor(i + position, n);

      // Чтобы посмотреть как оно рисуется - 
      // расскоментировать строчку ниже
      delay(100);

      // Рисуем символ из матрицы
			lcd->write(matrix[idx++]);
    }
  }
}
