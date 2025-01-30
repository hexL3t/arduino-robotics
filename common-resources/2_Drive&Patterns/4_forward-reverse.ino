// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);    // Wait 5 seconds
  forward(100);   // Move at speed 100
  delay(5000);    // Wait 5 seconds
  reverse(100);   // Move at speed 100
  delay(5000);    // Wait 5 seconds
  stopMotors();   // Stop Motors
}

// Stop the motors
void stopMotors(){  
  analogWrite(11, 0);  // Set motor speed to 0 (this stops the motor)  
  analogWrite(3, 0);  // Set motor speed to 0 (this stops the motor)  
}

// Reverse function - makes the robot move backward
void reverse(int motorspeed){  
  digitalWrite(13, HIGH);  // Turn off Pin 13
  digitalWrite(12, HIGH);  // Turn off Pin 12
  analogWrite(11, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
  analogWrite(3, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
}

// Forward function - makes the robot move
// void → This means the function doesn't "return" anything (it just does something).
// drive → This is the name of the function. We call this to make the robot move.
// (int motorspeed) → This is the "input." When we call drive(100), motorspeed = 100.
void forward(int motorspeed){  
  digitalWrite(13, HIGH);  // Turn on Pin 13
  digitalWrite(12, HIGH);  // Turn on Pin 12
  analogWrite(11, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
  analogWrite(3, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
}