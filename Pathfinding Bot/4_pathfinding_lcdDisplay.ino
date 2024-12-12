#include <Wire.h>                    // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>      // Include library for LCD display
#include <Servo.h>                  // Include library for controlling servos

// Initialize the LCD (Update address to 0x27 or 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with address 0x27 and 16x2 dimensions
Servo myServo;                      // Create a servo object to control the servo motor

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