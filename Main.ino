#include <Wire.h>
#include <MPU6050.h>
#include <LCD_I2C.h>

// Address from Hello_World_LCDTest test, number of columns in LCD, number of rows in LCD
LCD_I2C lcd(0x27, 16, 2);
MPU6050 mpu;

void setup() {

  // Initialize the Wire library and join the I2C bus as a controller or a peripheral
  Wire.begin();

  // Initialize MPU6050
  mpu.initialize();

  //Initialize LED for completely level
  pinMode(12, OUTPUT);

  // Initialize LCD Display
  lcd.begin();
  lcd.backlight();
  lcd.clear();

  //Delay to ensure proper setup before main loop operation
  delay(100);
}

void loop() {
  // Accelerometer data in x,y,z directions respectively. Noye: az is not used within this project
  int16_t ax, ay, az;
  // Threshold values to determine if MPU6050 is level aka the degree of error in our data received
  int16_t threshold = 500;

  // Read data from accelerometer
  mpu.getAcceleration(&ax, &ay, &az);
 
  // Check x and y are "level" within our set degree of error
  // Turn LED on if yes, Turn LED off if no
  if (abs(ax) < threshold && abs(ay) < threshold) {
    // turn the LED on
    digitalWrite(12, HIGH);  
  }
  else {
    // turn the LED off
    digitalWrite(12, LOW);   
  }

  // Used to get rid of extra 
  
  lcd.clear();

  // print to the LCD an line to determine how un-level our system is
  // print 0 if we are level (within our threshold of error)
  // if not level print a line with an approximation of how un-level we are
  // Initialize top row in LCD for displaying x level
  lcd.setCursor(0, 0);
  lcd.print("X: ");
  lcd.setCursor(3, 0);
  lcd.print(ax);

  // print to the LCD an line to determine how un-level our system is
  // print 0 if we are level (within our threshold of error)
  // if not level print a line with an approximation of how un-level we are
  // delay data so that the LCD can be more easily interpreted
  // Initialize bottom row in LCD for displaying y level
  lcd.setCursor(0, 1);
  lcd.print("Y: ");
  lcd.setCursor(3, 1);
  lcd.print(ay);

  delay(250);
}

