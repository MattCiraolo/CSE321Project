# CSE321 Project: Digital Level
Matthew Ciraolo

## Requiremnets

### Hardware Components List:
  - Arduino Uno Rev 3
  - HiLetgo GY-521 MPU-6050 MPU6050 3 Axis Accelerometer Gyroscope Module
  - Blue LED
  - SunFounder IIC/I2C/TWI LCD1602 Display
  - Button
  - 2x 200Ohm Resistors
  - Wiring (ideally multiple colors for orgainzation)
  - (Reccomended) Breadboard

### Required Software Libraires:
  - LiquidCrystal_I2C.h
  - MPU6050.h

## Setup

### Hardware Setup Diagram:

![screenshot](images/Diagram.PNG)

### Software Setup
  1. Download and install the Arduino IDE from Arduino's official website.
  2. Clone this repository:
```
git clone https://github.com/MattCiraolo/CSE321Project.git
```
  4. Install Required Software Libraires from above
  5. Download the Main.ino file
  6. Open Main.ino file in the Arduino IDE
  7. Update LED and Button Pin in software if necessary
  8. Connect computer with Arduino IDE installed to Arduino Uno using a USB cable
  9. Upload the code
   10. Enjoy!

## How To Use:
1. Properly Set Up and Configure the system as per instractions within this README file
2. Connect the system to Power using USB cable connected to the Arduino
3. Place device on surface you woule like to evaluate if it is level
4. Press the Reset Button to set the surface you would like to level
5. Use the system
6. Repeat Steps 2-4 when measuring different surfaces and angles.

## Future Improvements
1. Creating a Case to concolidate hardware and make system more visually appealing
2. Adding an On/Off feature besides unplugging it or plugging it back in, note that this is done currently to more efficiently demonstrate how the tests were used with the system for demonstrational purposes. 

