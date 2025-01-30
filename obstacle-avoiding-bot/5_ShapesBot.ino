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
  delay(5000);  // Wait for 5 seconds
  shapesBot();  // Call the shapesBot function
}

// Shapes Bot - Counts button presses and then draws a shape based on the total count, using the count as the number of sides.
void shapesBot() {
  int total = countingBot();  // Get the total count from countingBot
  shapes(total);              // Use the total count as the number of sides for the shape
}

// Shapes - Moves the robot to draw a shape with the specified number of sides, based on the total count, by moving forward and spinning at each corner.
void shapes(int sides) {
  double cornerTime = fullSpinTime / sides;  // Calculate time for each corner based on the shape's sides
  for (int i = 0; i < sides; i++) {
    forward(100);       // Move forward at full speed
    delay(1000);        // Wait 1 second
    spinRight(100);     // Spin right at full speed
    delay(cornerTime);  // Wait for the calculated time for each corner
  }
  stopMotors();  // Stop the motors after completing the shape
}

// Counting Bot - Counts button presses and flashes the LED to show the total count
int countingBot() {
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
    break;                             // Exit the do-while loop after counting is done
  } while (!(digitalRead(6) == 0 && digitalRead(8) == 0));  // Check the condition: both buttons need to be pressed
  flash(5, 0.1);                                            // End signal: Flash the LED 5 times to finish
  return total;                                             // Return the total count
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

// Flash function - flashes the LED a specified number of times with a given interval
void flash(int numberOfFlashes, float interval) {
  for (int i = 0; i < numberOfFlashes; i++) {  // Loop to flash LED 'randomNumber' times
    ON();                                      // Turn the LED ON
    delay(interval * 1000);                    // Wait for the interval (in milliseconds)
    OFF();                                     // Turn the LED OFF
    delay(interval * 1000);                    // Wait for the interval (in milliseconds)
  }
}


// Drive Functions
void spinRight(int motorspeed) {
  digitalWrite(13, LOW);        // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}

void stopMotors() {
  // Set the motor speed to 0 to stop the motors.
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void forward(int motorspeed) {
  digitalWrite(13, HIGH);       // Set Pin 13 to HIGH, HIGH = Forward
  digitalWrite(12, HIGH);       // Set Pin 12 to HIGH, HIGH = Forward
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}