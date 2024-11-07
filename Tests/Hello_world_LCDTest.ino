// Source:
// - https://github.com/blackhack/LCD_I2C 

#include <LCD_I2C.h>

// Address from sources above, number of columns in LCD, number of rows in LCD
LCD_I2C lcd(0x27,16,2);

void setup()
{
  // Initialize LCD Display
  lcd.begin();
  // Turn on backlight of LCD (turn on the display)
  lcd.backlight();
  // Clears the LCD screen and positions the cursor in the upper-left corner
  lcd.clear();
}

void loop()
{
    // Initilize cursor to the top row, first column in LCD
    lcd.setCursor(0, 0);
    // Print Hello in the top row of the LCD
    lcd.print("Hello");

    // Wait 2 seconds
    delay(1000);

    // Initialize cursor to the bottom row, first column in LCD
    lcd.setCursor(0, 1);
    // Print World! to the bottom row of the LCD
    lcd.print("World!");

    // Wait 4 seconds
    delay(4000);

    // Turn of backlight of LCD (turn off the display)
    lcd.noBacklight();
    // Wait 3 seconds
    delay(3000);

    // Turn on backlight of LCD (turn on the display)
    lcd.backlight();
    // Wait 3 seconds
    delay(3000);

    // Clears the LCD screen and positions the cursor in the upper-left corner
    lcd.clear();

    // Wait 3 seconds
    delay(3000);
}





