#include <Wire.h>
#include <LCD_I2C.h>

// Address from Hello_World_LCDTest test, number of columns in LCD, number of rows in LCD
LCD_I2C lcd(0x27, 16, 2);

void setup() {

  // Initialize the Wire library and join the I2C bus as a controller or a peripheral
  Wire.begin();

  //Initialize LED 
  pinMode(12, OUTPUT);

  // Initialize LCD Display
  lcd.begin();
  lcd.clear();

  //Delay to ensure proper setup before main loop operation
  delay(100);
}

void loop() {

  // turn the LED off by making the voltage LOW
  digitalWrite(12, LOW);   
 
  // Turn off LCD
  lcd.noBacklight();

  // 5 second delay
  delay(5000);
}

