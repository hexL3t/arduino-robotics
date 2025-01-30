// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  figureEight();          // Perform the figure eight pattern
  stopMotors();           // Stop the motors
}

// Figure eight function - makes the robot move in a figure-eight pattern
void figureEight(){
  forwardTurn(90,40);     // Turn forward with left motor speed 90 and right motor speed 40
  delay(5250);            // Wait for 5.25 seconds
  forwardTurn(40,90);     // Turn forward with left motor speed 40 and right motor speed 90
  delay(5250);            // Wait for 5.25 seconds
}

// Drive Functions
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