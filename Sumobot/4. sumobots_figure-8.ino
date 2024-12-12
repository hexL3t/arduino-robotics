void setup() {
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output
}

void loop() {
  delay(5000);          // Wait for 5 seconds.
  spinning();           // Have the bot Spin
  stopMotors();         // Stop Motors
}

void spinning() {
  spinLeft(100);        // Spin the bot to the left
  delay(5000);          // Wait for 5 seconds.
  spinRight(100);       // Spin the bot to the right.
  delay(5000);          // Wait for 5 seconds.
}

void figureEight() {
  forwardTurn(90,40);   // Turn forward, left 90%, right 40%.
  delay(5250);          // Wait 5.25 seconds.
  forwardTurn(40,90);   // Turn forward, left 40%, right 90%.
  delay(5250);          // Wait 5.25 seconds.
}

// Drive Functions
void reverseTurn(int leftspeed, int rightspeed){
  digitalWrite(13, LOW);       // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, rightspeed);  // Set the right motor's speed using PWM
  analogWrite(3, leftspeed);    // Set the left motor's speed using PWM
}

void spinRight(int motorspeed) {
  digitalWrite(13, LOW);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void spinLeft(int motorspeed) {
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, LOW);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void forwardTurn(int leftspeed, int rightspeed){
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
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

void forward(int motorspeed){
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}