void setup() {
  // Motor control pins
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output

  // Light Pins
  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output

  // Sensor Pins
  pinMode(6, INPUT);     // set Pin 6 as an Input
  pinMode(8, INPUT);     // set Pin 8 as an Input
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  forceBot();             // Call the forceBot function
}

// ForceBot - Moves backward when both sensors detect an obstacle
// Turns in reverse when only one sensor detects an obstacle
void forceBot(){
  while(true){  
    if(digitalRead(6) == 0 && digitalRead(8) == 0){  // If both sensors detect something
      reverse(100);                                  // Move backward at speed 100
      delay(100);                                    // Short delay before checking again
    }
    else if(digitalRead(6) == 0){                    // If only left sensor detects something
      reverseTurn(90, 20);                           // Reverse turn slightly to the right
      delay(100);                                    // Short delay before checking again
    }
    else if(digitalRead(8) == 0){                    // If only right sensor detects something
      reverseTurn(20, 90);                           // Reverse turn slightly to the left
      delay(100);                                    // Short delay before checking again
    }
    else {                                           // If no obstacles are detected
      stopMotors();                                  // Stop the motors
    }
  }
}

// Drive Functions
void reverseTurn(int leftspeed, int rightspeed){
  digitalWrite(13, LOW);       // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, rightspeed);  // Set the right motor's speed using PWM
  analogWrite(3, leftspeed);    // Set the left motor's speed using PWM
}

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