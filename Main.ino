#include <MPU6050.h>
#include <LCD_I2C.h>
// #include <LiquidCrystal_I2C.h>

// Update if necessary
int LED_PIN = 13;
int BTN_PIN = 12;



// This was a method from File->Exmples->Examples from Custom Libraries->LiquidCrystal I2C->HelloWorld
// Address from Hello_World_LCDTest test, number of columns in LCD, number of rows in LCD
LCD_I2C lcd(0x27, 16, 2); 
// LiquidCrystal_I2C lcd(0x27,16,2); 
MPU6050 mpu;
int buttonState = 0;  // variable for reading the pushbutton status

char current_state;
enum State{start, reset, level};
// Accelerometer data in x,y,z directiuons respectively that is svaed upon reset
int16_t x, y, z;
// Accelerometer data in x,y,z directiuons respectively. Note: az is not used within this project
int16_t ax, ay, az;
// Threshold values to determine if MPU6050 is level aka the degree of error in our data recieved
int16_t threshold = 300;

void setup() {
  // Initilize Accelerometer
  mpu.initialize();

  //Initilize LED for completely level
  pinMode(LED_PIN, OUTPUT);


  // initialize the pushbutton pin as an input:
  pinMode(BTN_PIN, INPUT);

  // Ititilize LCD Display
  lcd.begin(); 
  lcd.backlight();
  lcd.clear();
  lcd.print("Press Reset!!");

  // Initilize state machine
  current_state = start;

  //Delay to ensure proper setup before main loop operation
  delay(100);
}

void loop() {

  // Read if Button is being pressed
  buttonState = digitalRead(BTN_PIN);

  switch(current_state){

    case start:
      if (buttonState == HIGH) {
        lcd.clear();
        lcd.print("Starting");
        delay(1000);

        // Read data from accelerometer 
        mpu.getAcceleration(&x, &y, &z);

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
        
        // Read data from accelerometer 
        mpu.getAcceleration(&ax, &ay, &az);

        //Adjust new accelerometer data to accomodate level position
        ax = x-ax;
        ay = y-ay;
        az = z-az;
        
        // Check x and y are "level" within our set degree of error
        // Turn LED on if yes, Turn LED off if no
        if (abs(ax) < threshold && abs(ay) < threshold) {
          digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
        } 
        else {
          digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
        }

        // Initilize top row in LCD for displayying x level
        lcd.setCursor(0, 0);
        lcd.print("X: ");
        lcd.setCursor(3, 0);

        // print to the LCD an line to determine how un-level our system is
        // print 0 if we are level (within our threshold of error)
        // if not level print a line with an approximation of how un-level we are
        if(abs(ax) < threshold){
          lcd.print("------0------");
        }
        else {

          // Update LCD with positive x tilt
          if(ax > 0 && ax <= (threshold * 2) ){
            lcd.print("-------|-----");
          }
          else if(ax > 0 && ax <= (threshold * 3) ){
            lcd.print("--------|----");
          }
          else if(ax > 0 && ax <= (threshold * 5) ){
            lcd.print("---------|---");
          }
          else if(ax > 0 && ax <= (threshold * 10) ){
            lcd.print("----------|--");
          }
          else if(ax > 0 && ax <= (threshold * 15) ){
            lcd.print("-----------|-");
          }
          else if(ax >  (threshold * 15) ){
            lcd.print("------------|");
          }
          
          //Update LCD with negative x tilt
          else if(ax < 0 && ax >= -(threshold * 2) ){
            lcd.print("-----|-------");
          }
          else if(ax < 0 && ax >= -(threshold * 3) ){
            lcd.print("----|--------");
          }
          else if(ax < 0 && ax >= -(threshold * 5) ){
            lcd.print("---|---------");
          }
          else if(ax < 0 && ax >= -(threshold * 10) ){
            lcd.print("--|----------");
          }
          else if(ax < 0 && ax >= -(threshold * 15) ){
            lcd.print("-|-----------");
          }
          else if(ax < -(threshold * 15) ){
            lcd.print("|------------");
          }
        }

        // Initilize bottom row in LCD for displayying y level
        lcd.setCursor(0, 1);
        lcd.print("Y: ");
        lcd.setCursor(3, 1);

        // print to the LCD an line to determine how un-level our system is
        // print 0 if we are level (within our threshold of error)
        // if not level print a line with an approximation of how un-level we are
        if(abs(ay) < threshold){
          lcd.print("------0------");
        }
        else{

          // Update LCD with positive x tilt
          if(ay > 0 && ay <= (threshold * 2) ){
            lcd.print("-------|-----");
          }
          else if(ay > 0 && ay <= (threshold * 3) ){
            lcd.print("--------|----");
          }
          else if(ay > 0 && ay <= (threshold * 5) ){
            lcd.print("---------|---");
          }
          else if(ay > 0 && ay <= (threshold * 10) ){
            lcd.print("----------|--");
          }
          else if(ay > 0 && ay <= (threshold * 15) ){
            lcd.print("-----------|-");
          }
          else if(ay >  (threshold * 15) ){
            lcd.print("------------|");
          }
          
          //Update LCD with negative x tilt
          else if(ay < 0 && ay >= -(threshold * 2) ){
            lcd.print("-----|-------");
          }
          else if(ay < 0 && ay >= -(threshold * 3) ){
            lcd.print("----|--------");
          }
          else if(ay < 0 && ay >= -(threshold * 5) ){
            lcd.print("---|---------");
          }
          else if(ay < 0 && ay >= -(threshold * 10) ){
            lcd.print("--|----------");
          }
          else if(ay < 0 && ay >= -(threshold * 15) ){
            lcd.print("-|-----------");
          }
          else if(ay < -(threshold * 15) ){
            lcd.print("|------------");
          }
        }

        break;
      }


    case reset:
      lcd.print("Reseting");
      delay(1000);

      mpu.getAcceleration(&x, &y, &z);

      current_state = level;

      lcd.clear();
      break;

  }

  delay(250);
}


