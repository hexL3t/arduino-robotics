#include <Wire.h>                    // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>      // Include library for LCD display
#include <Servo.h>                  // Include library for controlling servos

// Initialize the LCD (Update address to 0x27 or 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with address 0x27 and 16x2 dimensions
Servo myServo;                      // Create a servo object to control the servo motor

// Declare variables
int distance;                        // Variable to store the measured distance

int count = 0;                       // Servo angle counter
int direction = 1;                   // Direction for servo sweep (1 = forward, -1 = backward)

void setup() {
  // Motor control pins
  pinMode(13, OUTPUT);              // Right motor direction pin
  pinMode(11, OUTPUT);              // Right motor speed (PWM) pin
  pinMode(12, OUTPUT);              // Left motor direction pin
  pinMode(3, OUTPUT);               // Left motor speed (PWM) pin

  // Ultrasonic sensor pins
  pinMode(A1, OUTPUT);              // Trigger pin for ultrasonic sensor
  pinMode(A0, INPUT);               // Echo pin for ultrasonic sensor

  // Initialize serial communication and peripherals
  Serial.begin(9600);               // Start serial communication at 9600 baud
  Wire.begin();                     // Initialize I2C communication
  lcd.begin(16, 2);                 // Initialize LCD with 16x2 dimensions
  lcd.backlight();                  // Turn on the LCD backlight
  myServo.attach(8);                // Attach servo motor to pin 8
}

void loop() {
  delay(300);                       // 0.3s Delay for stability
  readUltrasonicSensor();           
  socialDistancingBot(distance);        
}

// Function to handle motion based on distance
void socialDistancingBot(int distance){
  lcd.clear();                  // Clear the LCD screen
  count += 10 * direction;      // Adjust the servo angle based on the current direction
 
  // Ensure the servo angle stays within the valid range (0 to 180 degrees)
  if (count >= 0 && count <= 180) {
    myServo.write(count);       // Move the servo to the current angle

    // Display a message on the LCD indicating the bot is checking the distance
    lcd.setCursor(0, 0);
    lcd.print("Checking...");
    lcd.clear();                  // Clear the LCD screen

    // Check the distance and take appropriate action:
    if (distance < 25){           // If the object is too close
      displayDistance(distance);  // Display the distance,
      reverse(100);               // Reverse the bot
      delay(1000);                // Wait 1 second
    } 
    else if (distance > 30){    // If the path is clear
      displayDistance(distance);  // Display the distance,
      forward(100);               // Move the bot forward
      delay(1000);                // Wait 1 second
    }
    else if (distance > 25 && distance < 30){    // If the distance is within the safe range
      displayDistance(distance);                 // Display the distance,
      stopMotors();                              // Stop the Bot
      delay(1000);                               // Wait 1 second
    }
    else {
       // If none of the above conditions are met, display a "Checking..." message
      lcd.setCursor(0, 0);
      lcd.print("Checking...");
    }
    // Delay to allow the sensor and servo to stabilize
    delay(300);
  }
  // Reverse the servo direction if it reaches the end of its range
  if (count >= 180 || count <= 0) {
    direction *= -1;
  }
}

// Sweep the Servo from Left to Right (0 to 180), and Right to Left (180 to 0)
void servoMotorMovement(int distance){
  for (count = 0; count <= 180; count++) {
    myServo.write(count);                      // Set servo to the current angle
    displayDistanceAndAngle(distance);         // Display the angle and distance
    delay(300);                                // Delay for smooth movement
  }
    for (count = 180; count >= 0; count++) {
    myServo.write(count);                      // Set servo to the current angle
    displayDistanceAndAngle(distance);         // Display the angle and distance
    delay(300);                                // Delay for smooth movement
  }
}

// Sweep the Servo from Left to Right (0 to 180)
void servoMotor(int distance){
  lcd.clear();                  // Clear the LCD screen
  for (count = 0; count <= 180; count++) {
    myServo.write(count);           // Set servo to the current angle
    displayDistanceAndAngle(distance);         // Display the angle and distance
    delay(300);                     // Delay for smooth movement
  }
}

// Display distance and servo angle on the LCD
void displayDistanceAndAngle(int distance){
  lcd.clear();                  // Clear the LCD screen

  lcd.setCursor(0, 0);          // Position Cursor at (0,0) = first column, first row.
  lcd.print("Distance: ");      // Print the "Distance: " text on the first line
  lcd.print(distance);          // Print the measured distance value on the same line
  lcd.print(" cm");             // Print the "cm" unit on the same line

  lcd.setCursor(0, 1);          // Position Cursor at (0,0) = first column, second row.
  lcd.print("Angle: ");         // Print the "Angle: " text on the first line
  lcd.print(count);             // Print the servo current angle value on the same line
}

// Display distance on LCD
void displayDistance(int distance){
  lcd.clear();                  // Clear the LCD screen
  lcd.setCursor(0, 0);          // Position Cursor at (0,0) = first column, first row.
  lcd.print("Distance: ");      // Print the "Distance: " text on the first line
  lcd.print(distance);          // Print the measured distance value on the same line
  lcd.print(" cm");             // Print the "cm" unit on the same line
}

// Read Distance from Ultrasonic Sensor
int readUltrasonicSensor(){
  digitalWrite(A1, LOW);          // Send a low pulse to the trigger pin
  delayMicroseconds(2);           // Delay for 2 microseconds
  digitalWrite(A1, HIGH);         // Send a high pulse to the trigger pin
  delayMicroseconds(10);           // Delay for 10 microseconds
  digitalWrite(A1, LOW);          // Send a low pulse to the trigger pin

  long duration = pulseIn(A0, HIGH);              // Read the pulse duration
  distance = duration*0.034/2;                    // Calculate distance in centimeters
  Serial.println(distance);                       // Print the distance to the serial monitor  
}

void lcdCounter(){
  for(int i = 0; i < 100; i++){
    displayCount();
    delay(1000);      // Delay 1 second
    lcd.clear();
    count++;
  }
}

void displayCount(){
  lcd.setCursor(0,0);   // Position Cursor at (0,0) = first column, first row.
  lcd.print(count);
}

void lcdNames(){
  lcd.setCursor(0,0); // Position Cursor at (0,0) = first column, first row.
  lcd.print("Hello"); // Print a Word or Name

  lcd.setCursor(0,1);     // Position Cursor at (0,1) = first column, second row.
  lcd.print("World!");    // Print Last Name
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