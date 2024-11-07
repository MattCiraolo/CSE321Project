// Sources:
// - https://docs.arduino.cc/built-in-examples/basics/Blink/

void setup() {
  // Connect to LED in arduino port 12
  pinMode(12, OUTPUT);
}

void loop() {
    // Turn LED connected to arduino port 12 ON
    digitalWrite(12, HIGH);

    // wait for 1 second
    delay(1000);

    // Turn LED connected to arduino port 12 OFF
    digitalWrite(12, LOW);

    // wait for 1 second
    delay(1000);
}



