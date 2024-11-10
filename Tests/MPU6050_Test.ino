//  Sources
// - https://www.arduino.cc/reference/tr/language/functions/communication/serial/
// - https://github.com/ElectronicCats/mpu6050 
// - https://docs.arduino.cc/language-reference/en/functions/communication/Wire/

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  // Connect to serial to print continuous data
  // 9600 bits per second
  Serial.begin(9600);

  // Initialize the Wire library and join the I2C bus as a controller or a peripheral
  Wire.begin();

  // Initialize Accelerometer
  mpu.initialize();
}

void loop() {
 
  // Accelerometer data in x,y,z directions respectively. Noye: az is not used within this project
  int16_t ax, ay, az;

  // Display if we successfully connected to the accelerometer
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully.");

    // Read data from accelerometer
    mpu.getAcceleration(&ax, &ay, &az);


    // Threshold values to determine if MPU6050 is level
    int16_t threshold = 500;

    // Check if X, Y, and Z(adjusted) are close to zero
    if (abs(ax) < threshold && abs(ay) < threshold  && abs(az) - 18000 < threshold) {
      Serial.println("The MPU6050 is level.");
    } else {
      Serial.println("The MPU6050 is not level.");
    }

    // Display what data was read from the sensor
    Serial.print("Accel X = "); 
    Serial.print(ax);
    Serial.print(" | Y = "); 
    Serial.print(ay);
    Serial.print(" | Z = "); 
    Serial.print(az);
    Serial.print(" | Z' = "); 
    Serial.print(az-18000);
    Serial.println("");


    // Wait 1 second
    delay(1000);

  } else {
    Serial.println("MPU6050 connection failed.");
  }
}



