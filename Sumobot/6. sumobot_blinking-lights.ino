int randomNumber = 0;     // Global Variable for Random Number
int beat = 250;           // 0.25 seconds in milliseconds

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
  blinkingLights();   
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
    flash(rabndomNumber, 0.25));     // Flash the LED using the function
    delay(1000);                     // Wait 1 second before next pattern
}

void flash(int numberOfFlashes. float interval){ 
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