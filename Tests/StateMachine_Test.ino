#include <Wire.h>
#include <LCD_I2C.h>
// #include <LiquidCrystal_I2C.h>



// This was a method from File->Exmples->Examples from Custom Libraries->LiquidCrystal I2C->HelloWorld
// Address from Hello_World_LCDTest test, number of columns in LCD, number of rows in LCD
LCD_I2C lcd(0x27, 16, 2); 
// LiquidCrystal_I2C lcd(0x27,16,2); 
const int BTN_PIN = 12;
char current_state;
int buttonState = 0;  // variable for reading the pushbutton status


enum State{start, reset, level};

void setup() {

  Wire.begin();

  // initialize the pushbutton pin as an input:
  pinMode(BTN_PIN, INPUT);

  // Ititilize LCD Display
  lcd.begin(); 
  lcd.backlight();

  current_state = start;

  lcd.print("Press Reset!!");

  //Delay to ensure proper setup before main loop operation
  delay(100);
}

void loop() {

  buttonState = digitalRead(BTN_PIN);

  switch(current_state){

    case start:
      if (buttonState == HIGH) {
        lcd.clear();
        lcd.print("Starting");
        delay(3000);

        lcd.clear();
        current_state = level;
      } 
      else {
        break;
      }

    case level:
      if (buttonState == HIGH) {
        lcd.clear();
        current_state = reset;
      } 
      else {
        lcd.clear();
        lcd.print("Getting Level");
        break;
      }


    case reset:
      lcd.print("Reseting");
      delay(1000);

      current_state = level;

      lcd.clear();
      break;

    default:
      lcd.clear();
      lcd.print("System Error");
      delay(1000);

      lcd.clear();
      break;

  }

  delay(250);
}
