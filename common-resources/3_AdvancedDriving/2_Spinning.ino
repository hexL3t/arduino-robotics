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

// Spinning function - spins the robot left and right
void spinning(){
  spinLeft(100);           // Spin left with both motors running at speed 100
  delay(5000);             // Wait for 5 seconds
  spinRight(100);          // Spin right with both motors running at speed 100
  delay(5000);             // Wait for 5 seconds
}

// Drive Functions
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