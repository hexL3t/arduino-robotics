// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  spinning();             // Perform the spinning function
  stopMotors();           // Stop the motors
}

// Square function - makes the robot move in a square pattern
void square(){
  delay(5000);            // Wait for 5 seconds
  forward(100);           // Move forward at speed 100
  delay(1000);            // Wait for 1 second
  spinLeft(100);          // Spin left at speed 100
  delay(400);             // Wait for 0.4 seconds
  forward(100);           // Move forward at speed 100
  delay(1000);            // Wait for 1 second
  spinLeft(100);          // Spin left at speed 100
  delay(400);             // Wait for 0.4 seconds
  forward(100);           // Move forward at speed 100
  delay(1000);            // Wait for 1 second
  spinLeft(100);          // Spin left at speed 100
  delay(400);             // Wait for 0.4 seconds
  forward(100);           // Move forward at speed 100
  delay(1000);            // Wait for 1 second
}

// Spinning function - spins the robot left and right
void spinning(){
  spinLeft(100);           // Spin left with both motors running at speed 100
  delay(5000);             // Wait for 5 seconds
  spinRight(100);          // Spin right with both motors running at speed 100
  delay(5000);             // Wait for 5 seconds
}

// Figure eight function - makes the robot move in a figure-eight pattern
void figureEight(){
  forwardTurn(90,40);     // Turn forward with left motor speed 90 and right motor speed 40
  delay(5250);            // Wait for 5.25 seconds
  forwardTurn(40,90);     // Turn forward with left motor speed 40 and right motor speed 90
  delay(5250);            // Wait for 5.25 seconds
}

// Drive Functions

// Reverse turn function - turns the robot while moving backwards
// leftspeed and rightspeed control the speed of the left and right motors.
void reverseTurn(int leftspeed, int rightspeed){
  digitalWrite(13, LOW);  // Turn off Pin 13 (move forward)
  digitalWrite(12, LOW);  // Turn off Pin 12 (move forward)
  analogWrite(11, rightspeed);  // Set speed for right motor
  analogWrite(3, leftspeed);    // Set speed for left motor
}

// Spin right function - spins the robot to the right while both motors are running at the same speed
void spinLeft(int motorspeed){
  digitalWrite(13, LOW);  // Turn off Pin 13 (move forward)
  digitalWrite(12, HIGH);  // Turn on Pin 12 (move forward)
  analogWrite(11, motorspeed);  // Set speed for right motor
  analogWrite(3, motorspeed);   // Set speed for left motor (both motors move at same speed to spin left)
}

// Spin left function - spins the robot to the left while both motors are running at the same speed
void spinLeft(int motorspeed){
  digitalWrite(13, HIGH);  // Turn on Pin 13 (move forward)
  digitalWrite(12, LOW);  // Turn off Pin 12 (move forward)
  analogWrite(11, motorspeed);  // Set speed for right motor
  analogWrite(3, motorspeed);   // Set speed for left motor (both motors move at same speed to spin left)
}

// Forward turn function - turns the robot while moving forward
// leftspeed and rightspeed control the speed of the left and right motors.
void forwardTurn(int leftspeed, int rightspeed){
  digitalWrite(13, HIGH);  // Turn on Pin 13 (move forward)
  digitalWrite(12, HIGH);  // Turn on Pin 12 (move forward)
  analogWrite(11, leftspeed);  // Set speed for left motor
  analogWrite(3, rightspeed);    // Set speed for right motor
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