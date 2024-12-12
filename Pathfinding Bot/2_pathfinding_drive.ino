void setup() {
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);    // set Pin 13 as an output
}

void loop() {
  delay(5000);          // Wait for 5 seconds.
  forward(100);         // Drive the motor at the specified speed
  delay(5000);          // Wait for 5 seconds.
  reverse(100);         // Reverse the motors for the specified time
  delay(5000);          // Wait for 5 seconds.
  StopMotors();         // Function to stop the motors.
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
  analogWrite(3, motorspeed);  // Add Specified Speed to Pin 3 using PWM
}

void forward(int motorspeed){
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(13, motorspeed);  // Add Specified Speed to Pin 3 using PWM
}