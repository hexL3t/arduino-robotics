void setup() {
  // Light Pins
  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output

  // Sensor Pins
  pinMode(6, INPUT);     // set Pin 6 as an Input
  pinMode(8, INPUT);     // set Pin 8 as an Input
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  countingBot();         // Call the countingBot function
}

// Counting Bot - Counts button presses and flashes the LED to show the total count
void countingBot(){
  do {
    flash(5, 0.1);                    // Flash the LED 5 times at the start
    int total = 0;                    // Initialize the total count to 0

    while (!(digitalRead(8) == 0)){   // Wait for the button on pin 8 to be pressed
      if (digitalRead(6) == 0){       // If the button on pin 6 is pressed
        total++;                       // Increment the total count
        flash(1, 0.5);                 // Flash the LED once to show it's counting
      }
    }

    flash(5, 0.1);                    // Flash the LED 5 times when done counting
    delay(1000);                       // Wait for 1 second before moving on

    for (int i = 0; i < total; i++){  // Flash the LED the same number of times as the count
      flash(1, 0.5);                  // Flash the LED once for each count
    }
  } while (!(digitalRead(6) == 0 && digitalRead(8) == 0));  // Check the condition: both buttons need to be pressed
  flash(5, 0.1);                       // End signal: Flash the LED 5 times to finish
}

// Turn the LED ON by setting Pin 9 HIGH and Pin 10 LOW
void ON(){
  digitalWrite(9, HIGH);  // Set Pin 9 to HIGH = ON
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Turn the LED OFF by setting both Pins 9 and 10 to LOW
void OFF() {
  digitalWrite(9, LOW);   // Set Pin 9 to LOW = OFF
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Flash function - flashes the LED a specified number of times with a given interval
void flash(int numberOfFlashes, float interval){
  for(int i = 0; i < numberOfFlashes; i++){  // Loop to flash LED 'randomNumber' times
    ON();                           // Turn the LED ON
    delay(interval * 1000);         // Wait for the interval (in milliseconds)
    OFF();                          // Turn the LED OFF
    delay(interval * 1000);         // Wait for the interval (in milliseconds)
  }
}