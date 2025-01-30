// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

void loop() {
  delay(5000);            // Wait for 5 seconds
  forwardTurn(70, 40);    // Turn forward with left motor speed 70 and right motor speed 40
  delay(5000);            // Wait for another 5 seconds
  forwardTurn(90, 20);    // Turn forward with left motor speed 90 and right motor speed 20
  delay(5000);            // Wait for another 5 seconds
  stopMotors();           // Stop the motors
}

// Forward turn function - turns the robot while moving forward
// leftspeed and rightspeed control the speed of the left and right motors.
void forwardTurn(int leftspeed, int rightspeed){
  digitalWrite(13, HIGH);  // Turn on Pin 13 (move forward)
  digitalWrite(12, HIGH);  // Turn on Pin 12 (move forward)
  analogWrite(11, leftspeed);  // Set speed for right motor
  analogWrite(3, rightspeed);    // Set speed for left motor
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