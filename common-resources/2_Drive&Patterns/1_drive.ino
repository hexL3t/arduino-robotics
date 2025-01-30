// Robot setup
void setup() {
  // Motor Set Up
  pinMode(13, OUTPUT);  // Set Pin 13 as output
  pinMode(11, OUTPUT);  // Set Pin 11 as output
}

void loop() {
  delay(5000);   // Wait 5 seconds
  drive(100);    // Move at speed 100
}

// Drive function - makes the robot move
// void → This means the function doesn't "return" anything (it just does something).
// drive → This is the name of the function. We call this to make the robot move.
// (int motorspeed) → This is the "input." When we call drive(100), motorspeed = 100.
void drive(int motorspeed){  
  digitalWrite(13, HIGH);  // Turn on Pin 13
  analogWrite(11, motorspeed);  // Set motor speed using pulse-width modulation (PWM)
}