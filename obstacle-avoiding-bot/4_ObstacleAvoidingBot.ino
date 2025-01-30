int randomNumber = 0;  // Global Variable for Random Number
int fullSpinTime = 1.65 * 1000;

void setup() {
  // Motor control pins
  pinMode(13, OUTPUT);  // set Pin 13 as an output
  pinMode(11, OUTPUT);  // set Pin 11 as an output
  pinMode(12, OUTPUT);  // set Pin 12 as an output
  pinMode(3, OUTPUT);   // set Pin 3 as an output

  // Light Pins
  pinMode(9, OUTPUT);   // set Pin 9 as an Output
  pinMode(10, OUTPUT);  // set Pin 10 as an Output
  pinMode(LED_BUILTIN, OUTPUT);

  // Sensor Pins
  pinMode(6, INPUT);  // set Pin 6 as an Input
  pinMode(8, INPUT);  // set Pin 8 as an Input
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  obstacleAvoidingBot();  // Call the obstacleAvoidingBot function
}

// obstacleAvoidingBot - Controls the robot's movement to avoid obstacles based on sensor input
// It moves forward, spins left or right, or stops and reverses based on the sensor readings.
void obstacleAvoidingBot() {
  int randomNumber = random(1, 2);  // Generate a random number between 1 and 2
  while (true) {                                              // Infinite loop to keep checking sensor inputs and adjust behavior accordingly
    if (digitalRead(6) == 1 && digitalRead(8) == 1) {         // If both sensors detect no obstacles (both high)
      forward(100);                                           // Move forward at full speed
    } else if (digitalRead(6) == 0 && digitalRead(8) == 1) {  // If the left sensor detects an obstacle (low)
      spinRight(100);                                         // Spin right to avoid obstacle
      delay(random(5, 10) * 100);                             // Wait for a random time between 5-10 seconds
    } else if (digitalRead(6) == 1 && digitalRead(8) == 0) {  // If the right sensor detects an obstacle (low)
      spinLeft(100);                                          // Spin left to avoid obstacle
      delay(random(5, 10) * 100);                             // Wait for a random time between 5-10 seconds
    } else if (digitalRead(6) == 0 && digitalRead(8) == 0) {  // If both sensors detect obstacles (both low)
      stopMotors();                                           // Stop the robot
      reverse(100);                                           // Move backward at full speed
      delay(500);                                             // Wait for 500 milliseconds
      if (randomNumber == 1) {                                // Randomly choose a direction to spin
        spinRight(100);                                       // Spin right
      } else {
        spinLeft(100);  // Spin left
      }
      delay(random(5, 10) * 100);  // Wait for a random time between 5-10 seconds
    }
  }
}

// Drive Functions
void spinRight(int motorspeed) {
  digitalWrite(13, LOW);        // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void spinLeft(int motorspeed) {
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, LOW);        // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void stopMotors() {
  // Set the motor speed to 0 to stop the motors.
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void reverse(int motorspeed) {
  digitalWrite(13, LOW);        // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);        // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void forward(int motorspeed) {
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}