// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);   // Wait 5 seconds
  reverse(100);    // Move at speed 100
}

// Reverse function - makes the robot move backward
void reverse(int motorspeed){  
  digitalWrite(13, LOW);  // Turn off Pin 13 (to move backward)  
  analogWrite(11, motorspeed);  // Set motor speed using pulse-width modulation (PWM)  
}

// Drive function - makes the robot move
// void → This means the function doesn't "return" anything (it just does something).
// drive → This is the name of the function. We call this to make the robot move.
// (int motorspeed) → This is the "input." When we call drive(100), motorspeed = 100.
void drive(int motorspeed){  
  digitalWrite(13, HIGH);  // Turn on Pin 13
  analogWrite(11, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
}