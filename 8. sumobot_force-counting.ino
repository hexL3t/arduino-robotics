int randomNumber = 0;     // Global Variable for Random Number
int beat = 250;           // 0.25 seconds in milliseconds

void setup() {
  pinMode(13, OUTPUT);    // set Pin 13 as an output
  pinMode(11, OUTPUT);    // set Pin 11 as an output
  pinMode(12, OUTPUT);    // set Pin 12 as an output
  pinMode(3, OUTPUT);     // set Pin 3 as an output

  pinMode(9, OUTPUT);     // set Pin 9 as an Output
  pinMode(10, OUTPUT);    // set Pin 10 as an Output

  pinMode(6, INPUT);     // set Pin 6 as an Input
  pinMode(8, INPUT);     // set Pin 8 as an Input
}

void loop() {
  delay(5000);            // Wait for 5 seconds

}

void countingRobot() {
  flash(5, 0.1);                                                // Inital Light Flash

  while ((digitalRead(8) == 0 && digitalRead(6) == 0)) {       // Loop until not both pins 8 and 6 are reading 0

      if (digitalRead(6) == 0) {                                // If Pin 6 reads 0, then...
        flash(1, 0.5);                                          // Flash once per 0.5 (500ms)
      }
      else if (digitalRead(8) == 0){                            // If Pin 8 reads 0, then...
        flash(2, 0.2);                                          // Flash twice per 0.2 (200ms)                                
      }
  }
}

void useForce(){
  while (!(digitalRead(8) == 0 && digitalRead(6) == 0)) {       // Loop until not both pins 8 and 6 are reading 0
    
    if (digitalRead(6) == 0) {                                  // If Pin 6 reads 0, then...
      reverseTurn(80, 50);                                      // Reverse turn Left at 80 speed and 50 speed
      delay(1000);                                              // Delay for 1 second
    }
    else if (digitalRead(8) == 0){                              // If Pin 8 reads 0, then...
      reverseTurn(50, 80);                                      // Reverse turn Right at 50 speed and 80 speed
      delay(1000);                                              // Delay for 1 second
    }
    else {
      stopMotors();
    }
  }
  reverse(50);                                                 // Reverse at half speed.
}

void performDance() {
  int danceRepeats = 4;    // Number of Times to repeat    
  // Run dance routine for specified number of times
  for (int i = 0; i < danceRepeats; i++) {
    danceRoutine();
  }
  stopMotors();
  OFF();
}

void danceRoutine(){
  ON();           // Forward with lights
  forward(100);
  delay(beat);

  OFF();          // Reverse with lights off
  reverse(100);
  delay(beat);

  ON();           // Spin Left with lights on
  spinLeft(100);
  delay(beat);

  OFF();          // Spin Right with lights off
  spinRight(100);
  delay(beat);
}

void randomActions() {
  randomNumber = random(1,8);   // Generate a random number between 1 and 7
  // excute actions based on random number
  if (randomNumber == 1) {
    forward(100);
  }
  else if (randomNumber == 2) {
    reverse(100);
  }
  else if (randomNumber == 3) {
    spinLeft(100);
  }
  else if (randomNumber == 4) {
    spinRight(100);
  }
  else if (randomNumber == 5) {
    forward(100);
  }
  else if (randomNumber == 6) {
    reverse(100);
  }
  else if (randomNumber == 7) {
    spinLeft(100);
  }
  else {
    stopMotors();
  }
}

void ON(){
  digitalWrite(9, HIGH);  // Set Pin 9 to HIGH = ON
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}
void OFF() {
  digitalWrite(9, LOW);   // Set Pin 9 to LOW = OFF
  digitalWrite(10, LOW);  // Set Pin 10 to LOW = OFF
}

void blinkingLights() {
  int randomNumber = 0;               // Initalise randomNumber to 0

  while (true){                       // Create an indefinate loop as long as 'true' is met.
    int randomNumber = random(1,7);  // Random number between 1 and 6
    flash(randomNumber, 0.25);     // Flash the LED using the function
    delay(1000);                     // Wait 1 second before next pattern
  }
}

void flash(int numberOfFlashes, float interval){ 
  // Loop to repeat the flashing pattern  
  for (int i = 0; i < numberOfFlashes; i++){
    ON();                     // Turn LED On
    delay(interval * 1000);   // Delay by specified interval
    OFF();                    // Turn LED Off
    delay(interval * 1000);   // Delay by specified interval   
  }
}

 void hexagon() {
  // Loop 6 times for each side of the hexagon
  for(int count=0; count <6; count++) {
    forward(100);       // Drive forward at 100% speed
    delay(1000);        // Wait for 1 second
    spinRight(100);     // Spin Right at 100% speed
    delay(275);         // Wait 275 milliseconds
  }
 }
void pentagon(){
  // Loop 5 times for each side of the pentagon
  for(int count=0; count < 5; count++) {
    forward(100);        // Drive forward at 100% speed
    delay(1000);        // Wait for 1 second
    spinRight(100);     // Spin Right at 100% speed
    delay(330);         // Wait 330 milliseconds
  }
}
void triangle() {
  // Loop 3 times for each side of the triangle
  for(int count=0; count < 3; count++) {
    forward(100);       // Drive forward at 100% speed
    delay(1000);        // Wait for 1 second
    spinRight(100);     // Spin Right at 100% speed
    delay(550);         // Wait 550 milliseconds
  }
}
void square(){
    // Loop 4 times for each side of the square
    for(int count=0; count < 4; count++){
    forward(100);       // Drive forward at 100% speed
    delay(1000);        // Wait for 1 second
    spinRight(100);     // Spin Right at 100% speed
    delay(4000);        // Wait 400 milliseconds
   }
}


void spinning(int motorspeed){
  digitalWrite(13, HIGH);        // Set Pin 13 to LOW, LOW = Reverse
  digitalWrite(12, LOW);        // Set Pin 12 to LOW, LOW = Reverse
  analogWrite(11, motorspeed);  // Add Specified Speed to Pin 11 using PWM
  analogWrite(3, motorspeed);   // Add Specified Speed to Pin 3 using PWM
}


// Figure 8
void figureEight(){
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