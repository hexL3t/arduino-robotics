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

  // Additional motor-related pins
  pinMode(9, OUTPUT);               // Additional output pin (not used in this code)
  pinMode(10, OUTPUT);              // Additional output pin (not used in this code)

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
void socialDistancingBot(int distance) {
  lcd.clear();
  count += 10 * direction;          // Adjust servo angle based on the current direction

  if (count >= 0 || count <= 180) {
    myServo.write(count);           // Move servo to current angle
    lcd.setCursor(0, 0);
    lcd.print("Checking...");

    lcd.clear();

    if (distance < 25) {            // If object is too close, reverse
      displayDistance(distance);
      reverse(100);
      delay(1000);
    } else if (distance > 30) {     // If path is clear, move forward
      displayDistance(distance);
      forward(100);
      delay(1000);
    } else if (distance > 25 && distance < 30) { // If within range, stop
      displayDistance(distance);
      stopMotors();
      delay(1000);
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Checking...");
    }

    delay(300);                     // Delay to allow sensor and servo stabilization
  }

  if (count >= 180 || count <= 0) {
    direction *= -1;               // Reverse servo direction when reaching the range ends
  }
}

// Sweep servo in a full circle
void servoMotorMovement(int distance) {
  for (count = 0; count <= 180; count++) {
    myServo.write(count);           // Set servo to the current angle
    displayAngle(distance);         // Display the angle and distance
    delay(300);                     // Delay for smooth movement
  }
  for (count = 180; count >= 0; count--) {
    myServo.write(count);           // Set servo to the current angle
    displayAngle(distance);         // Display the angle and distance
    delay(300);                     // Delay for smooth movement
  }
}

// Sweep servo in a half circle
void halfCircle(int distance) {
  lcd.clear();
  for (count = 0; count <= 180; count++) {
    myServo.write(count);           // Set servo to the current angle
    displayAngle(distance);         // Display the angle and distance
    delay(300);                     // Delay for smooth movement
  }
}

// Display distance on the LCD
void displayDistance(int distance) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
}

// Display distance and servo angle on the LCD
void displayAngle(int distance) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Angle: ");
  lcd.print(count);
}

// Read distance from ultrasonic sensor
int readUltrasonicSensor() {
  digitalWrite(A1, LOW);            // Clear the trigger pin
  delayMicroseconds(2);
  digitalWrite(A1, HIGH);           // Send a 10us pulse to the trigger pin
  delayMicroseconds(10);
  digitalWrite(A1, LOW);

  long duration = pulseIn(A0, HIGH); // Measure the time taken for the echo
  distance = duration * 0.034 / 2;  // Convert the duration to distance in cm
  return distance;
}
void lcdCounter(){
  for(int i = 0; i < 100; i++){
    displayCount();
    delay(1000);                  // wait 1 second
    lcd.clear();
    count++;
  }
}

void displayCount(){
  lcd.setCursor(0,0);  // Set cursor to column 0, row 0
  lcd.print(count);
}

void lcdNames() {
  lcd.setCursor(0,0);     // Position Cursor at (0,0) = first column, first row.
  lcd.print("Hello");     // Print First Name
  lcd.setCursor(0,1);     // Position Cursor at (0,1) = first column, second row.
  lcd.print("World!");    // Print Last Name
}

// Motor control functions
void spinRight(int motorspeed) {
  digitalWrite(13, LOW);            // Set right motor to reverse
  digitalWrite(12, HIGH);           // Set left motor to forward
  analogWrite(11, motorspeed);      // Set right motor speed
  analogWrite(3, motorspeed);       // Set left motor speed
}

void spinLeft(int motorspeed) {
  digitalWrite(13, HIGH);           // Set right motor to forward
  digitalWrite(12, LOW);            // Set left motor to reverse
  analogWrite(11, motorspeed);      // Set right motor speed
  analogWrite(3, motorspeed);       // Set left motor speed
}

void stopMotors() {
  analogWrite(11, 0);               // Stop right motor
  analogWrite(3, 0);                // Stop left motor
}

void forward(int motorspeed) {
  digitalWrite(13, HIGH);           // Set right motor to forward
  digitalWrite(12, HIGH);           // Set left motor to forward
  analogWrite(11, motorspeed);      // Set right motor speed
  analogWrite(3, motorspeed);       // Set left motor speed
}

void reverse(int motorspeed) {
  digitalWrite(13, LOW);            // Set right motor to reverse
  digitalWrite(12, LOW);            // Set left motor to reverse
  analogWrite(11, motorspeed);      // Set right motor speed
  analogWrite(3, motorspeed);       // Set left motor speed
}