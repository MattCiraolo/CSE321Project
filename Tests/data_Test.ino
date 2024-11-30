#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
// Accelerometer data in x,y,z directiuons respectively that is svaed upon reset
int16_t x, y, z;
// Accelerometer data in x,y,z directiuons respectively. Note: az is not used within this project
int16_t ax, ay, az;

void setup() {
  //Connect to seareail to print continous data
  Serial.begin(9600);


  Wire.begin();
  mpu.initialize();
  mpu.getAcceleration(&x, &y, &z);
}

void loop() {

  // Display if we successfully concnceted to the accelerometer 
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully.");

    // Read data from accelerometer 
    mpu.getAcceleration(&ax, &ay, &az);

    
      //Adjust new accelerometer data to accomodate level position
      ax = x-ax;
      ay = y-ay;
      az = z-az;

    // Threshold values to determine if MPU6050 is level
    int16_t threshold = 400;

    // Check if X, Y, and Z(adjusted for breadboard oreintation) are close to zero 
    if (abs(ax) < threshold && abs(ay) < threshold) {
      Serial.println("The MPU6050 is level.");
    } else {
      Serial.println("The MPU6050 is not level.");
    }

    // Display what data was read from the sensor
    Serial.print("Accel X = "); Serial.print(ax);
    Serial.print(" | Y = "); Serial.println(ay);

    // Wait 1 second
    delay(1000);

  } else {
    Serial.println("MPU6050 connection failed.");
  }

}
