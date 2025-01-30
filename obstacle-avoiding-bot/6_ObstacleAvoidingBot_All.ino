int randomNumber = 0;  // Global Variable for Random Number
int beat = 250;
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
  int randomNumber = random(1, 2);                            // Generate a random number between 1 and 2
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

// Counting Bot - Counts button presses and flashes the LED to show the total count
void countingBot() {
  int total = 0;
  do {
    flash(5, 0.1);                    // Flash the LED 5 times at the start
    while (!(digitalRead(8) == 0)) {  // Wait for the button on pin 8 to be pressed
      if (digitalRead(6) == 0) {      // If the button on pin 6 is pressed
        total++;                      // Increment the total count
        flash(1, 0.5);                // Flash the LED once to show it's counting
      }
    }
    flash(5, 0.1);                     // Flash the LED 5 times when done counting
    delay(1000);                       // Wait for 1 second before moving on
    for (int i = 0; i < total; i++) {  // Flash the LED the same number of times as the count
      flash(1, 0.5);                   // Flash the LED once for each count
    }
  } while (!(digitalRead(6) == 0 && digitalRead(8) == 0));  // Check the condition: both buttons need to be pressed
  flash(5, 0.1);                                            // End signal: Flash the LED 5 times to finish
}

// ForceBot - Moves backward when both sensors detect an obstacle
// Turns in reverse when only one sensor detects an obstacle
void forceBot() {
  while (true) {
    if (digitalRead(6) == 0 && digitalRead(8) == 0) {  // If both sensors detect something
      reverse(100);                                    // Move backward at speed 100
      delay(100);                                      // Short delay before checking again
    } else if (digitalRead(6) == 0) {                  // If only left sensor detects something
      reverseTurn(90, 20);                             // Reverse turn slightly to the right
      delay(100);                                      // Short delay before checking again
    } else if (digitalRead(8) == 0) {                  // If only right sensor detects something
      reverseTurn(20, 90);                             // Reverse turn slightly to the left
      delay(100);                                      // Short delay before checking again
    } else {                                           // If no obstacles are detected
      stopMotors();                                    // Stop the motors
    }
  }
}

// Force Chooser - Moves the robot backward if either sensor detects something
void forceChooser() {
  while (true) {                       // Keep checking the sensors
    if (digitalRead(6) == 0) {         // If sensor on pin 6 detects something (LOW)
      reverse(100);                    // Move backward at speed 100
      delay(100);                      // Short delay before checking again
    } else if (digitalRead(8) == 0) {  // If sensor on pin 8 detects something (LOW)
      reverse(100);                    // Move backward at speed 100
      delay(100);                      // Short delay before checking again
    } else {                           // If no sensor detects anything (HIGH)
      stopMotors();                    // Stop the motors
    }
  }
}

// Force Lefty - Moves the robot backward if sensor detects something
void forceLefty() {
  while (true) {                // Keep checking the sensor
    if (digitalRead(6) == 0) {  // If sensor detects something (LOW)
      reverse(100);             // Move backward at speed 100
      delay(100);               // Wait 0.1 seconds
    } else {                    // If no detection (HIGH)
      stopMotors();             // Stop the motors
    }
  }
}

// Sensor Test - Turns the light ON or OFF based on sensor input
void sensorTest() {
  if (digitalRead(8) == 0) {  // If sensor detects something (LOW)
    ON();                     // Turn the LED ON
  } else {                    // If sensor does not detect anything (HIGH)
    OFF();                    // Turn the LED OFF
  }
}

// Perform Dance - Repeats the dance routine multiple times
void performDance() {
  int danceRepeats = 4;  // Number of times to repeat the dance
  for (int i = 0; i < danceRepeats; i++) {
    danceRoutine();  // Call the dance routine
  }
}

// Dance Routine - Moves the robot in a fun pattern
void danceRoutine() {
  ON();          // Turn LED ON
  forward(100);  // Move forward at speed 100
  delay(beat);   // Wait for one beat

  OFF();         // Turn LED OFF
  reverse(100);  // Move backward at speed 100
  delay(beat);   // Wait for one beat

  ON();           // Turn LED ON
  spinLeft(100);  // Spin left at speed 100
  delay(beat);    // Wait for one beat

  OFF();           // Turn LED OFF
  spinRight(100);  // Spin right at speed 100
  delay(beat);     // Wait for one beat
}

// Random actions function - picks a random action to execute
void randomActions() {
  int randomNumber = random(1, 8);  // Generate a random number between 1 and 7

  if (randomNumber == 1) {
    forward(100);  // Move forward with speed 100
  } else if (randomNumber == 2) {
    reverse(100);  // Move in reverse with speed 100
  } else if (randomNumber == 3) {
    spinLeft(100);  // Spin left with speed 100
  } else if (randomNumber == 4) {
    spinRight(100);  // Spin right with speed 100
  } else if (randomNumber == 5) {
    forwardTurn(40, 90);  // Perform a forward turn with left speed 40 and right speed 90
  } else if (randomNumber == 6) {
    reverseTurn(90, 40);  // Perform a reverse turn with left speed 90 and right speed 40
  } else if (randomNumber == 7) {
    stopMotors();  // Stop the motors
  }
}

// Turn the LED ON by setting Pin 9 HIGH and Pin 10 LOW
void ON() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(9, HIGH);  // Set Pin 9 to HIGH = ON
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Turn the LED OFF by setting both Pins 9 and 10 to LOW
void OFF() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(9, LOW);   // Set Pin 9 to LOW = OFF
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Blinking lights function - flashes the LED a random number of times with a set interval
void blinkingLights() {
  int randomNumber = 0;  // Initialize randomNumber to 0

  randomNumber = random(1, 7);  // Generate a random number between 1 and 6
  flash(randomNumber, 0.25);    // Flash the LED using the random number and 0.25s interval
  delay(1000);                  // Wait for 1 second before the next pattern
}

// Flash function - flashes the LED a specified number of times with a given interval
void flash(int numberOfFlashes, float interval) {
  for (int i = 0; i < numberOfFlashes; i++) {  // Loop to flash LED 'randomNumber' times
    ON();                                      // Turn the LED ON
    delay(interval * 1000);                    // Wait for the interval (in milliseconds)
    OFF();                                     // Turn the LED OFF
    delay(interval * 1000);                    // Wait for the interval (in milliseconds)
  }
}

void hexagon() {
  // Loop 6 times for each side of the hexagon
  for (int count = 0; count < 6; count++) {
    forward(100);    // Drive forward at 100% speed
    delay(1000);     // Wait for 1 second
    spinRight(100);  // Spin Right at 100% speed
    delay(275);      // Wait 275 milliseconds
  }
}

void pentagon() {
  // Loop 5 times for each side of the pentagon
  for (int count = 0; count < 5; count++) {
    forward(100);    // Drive forward at 100% speed
    delay(1000);     // Wait for 1 second
    spinRight(100);  // Spin Right at 100% speed
    delay(330);      // Wait 330 milliseconds
  }
}
void triangle() {
  // Loop 3 times for each side of the triangle
  for (int count = 0; count < 3; count++) {
    forward(100);    // Drive forward at 100% speed
    delay(1000);     // Wait for 1 second
    spinRight(100);  // Spin Right at 100% speed
    delay(550);      // Wait 550 milliseconds
  }
}
void square() {
  // Loop 4 times for each side of the square
  for (int count = 0; count < 4; count++) {
    forward(100);    // Drive forward at 100% speed
    delay(1000);     // Wait for 1 second
    spinRight(100);  // Spin Right at 100% speed
    delay(4000);     // Wait 400 milliseconds
  }
}

// Figure 8
void figureEight() {
  forwardTurn(90, 40);  // Turn forward, left 90%, right 40%.
  delay(5250);          // Wait 5.25 seconds.
  forwardTurn(40, 90);  // Turn forward, left 40%, right 90%.
  delay(5250);          // Wait 5.25 seconds.
}

// Drive Functions
void reverseTurn(int leftspeed, int rightspeed) {
  digitalWrite(13, LOW);        // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);        // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, rightspeed);  // Set the right motor's speed using PWM
  analogWrite(3, leftspeed);    // Set the left motor's speed using PWM
}

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

void forwardTurn(int leftspeed, int rightspeed) {
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
  analogWrite(11, rightspeed);  // Set the right motor's speed using PWM
  analogWrite(3, leftspeed);    // Set the left motor's speed using PWM
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