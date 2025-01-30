int randomNumber = 0;     // Global Variable for Random Number

void setup() {
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output

  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output
}

void loop() {
  delay(5000);            // Wait for 5 seconds
  blinkingLights();     // Perform Blinking Lights Pattern
}

void ON(){
  digitalWrite(9, HIGH);  // Set Pin 9 to HIGH = ON
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}
void OFF() {
  digitalWrite(9, LOW);   // Set Pin 9 to LOW = OFF
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

// Blinking lights function - flashes the LED a random number of times with a set interval
void blinkingLights() {
  int randomNumber = 0;               // Initialize randomNumber to 0

  while(true){                        // Create an infinite loop to keep flashing
    randomNumber = random(1, 7);      // Generate a random number between 1 and 6

    for(int i = 0; i < randomNumber; i++){  // Loop to flash LED 'randomNumber' times
      ON();                           // Turn the LED ON
      delay(250);                     // Wait for 250 milliseconds
      OFF();                          // Turn the LED OFF
      delay(250);                     // Wait for 250 milliseconds
    }
    delay(1000);                      // Wait for 1 second before the next random pattern
  }
}