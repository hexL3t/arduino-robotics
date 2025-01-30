void setup() {
  // Light Pins
  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output

  // Sensor Pins
  pinMode(8, INPUT);     // set Pin 8 as an Input
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  sensorTest();         // Call the sensorTest function
}

// Sensor Test - Turns the light ON or OFF based on sensor input
void sensorTest(){
  if(digitalRead(8) == 0){  // If sensor detects something (LOW)
    ON();                   // Turn the LED ON
  }
  else {                    // If sensor does not detect anything (HIGH)
    OFF();                  // Turn the LED OFF
  }
}

// Turn the LED ON by setting Pin 9 HIGH and Pin 10 LOW
void ON(){
  digitalWrite(9, HIGH);  // Set Pin 9 to HIGH = ON
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Turn the LED OFF by setting both Pins 9 and 10 to LOW
void OFF() {
  digitalWrite(9, LOW);   // Set Pin 9 to LOW = OFF
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}