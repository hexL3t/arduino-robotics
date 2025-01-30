void setup() {
  // Motor control pins
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output

  // Sensor Pins
  pinMode(6, INPUT);     // set Pin 6 as an Input
  pinMode(8, INPUT);     // set Pin 8 as an Input
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  forceLefty();           // Call the forceLefty function
}

// Force Lefty - Moves the robot backward if sensor detects something
void forceLefty(){
  while(true){                          // Keep checking the sensor
    if(digitalRead(6) == 0){            // If sensor detects something (LOW)
      reverse(100);                     // Move backward at speed 100
      delay(100);                       // Wait 0.1 seconds
    } else {                            // If no detection (HIGH)
      stopMotors();                     // Stop the motors
    }
  }
}

// Drive Functions
void stopMotors(){
  // Set the motor speed to 0 to stop the motors.
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void reverse(int motorspeed){
  digitalWrite(13, LOW);        // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);        // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}