int randomNumber = 0;     // Global Variable for Random Number

void setup() {
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output

  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output
}

// Main loop - runs repeatedly
void loop() {
  delay(5000);            // Wait for 5 seconds
  blinkingLights();       // Run the blinkingLights function
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

// Blinking lights function - flashes the LED a random number of times with a set interval
void blinkingLights() {
  int randomNumber = 0;               // Initialize randomNumber to 0

  randomNumber = random(1, 7);        // Generate a random number between 1 and 6
  flash(randomNumber, 0.25);          // Flash the LED using the random number and 0.25s interval
  delay(1000);                        // Wait for 1 second before the next pattern
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