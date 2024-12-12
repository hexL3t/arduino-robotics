#include <Wire.h>                    // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>      // Include library for LCD display
#include <Servo.h>                  // Include library for controlling servos

// Initialize the LCD (Update address to 0x27 or 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with address 0x27 and 16x2 dimensions
Servo myServo;                      // Create a servo object to control the servo motor

// Declare variables
int distance;                        // Variable to store the measured distance
int count = 0;                       // Servo angle counter

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
  servoMotor(distance);
  displayDistanceAndAngle(distance);  
}

// Sweep the Servo from Left to Right (0 to 180)
void servoMotor(int distance){
  lcd.clear();                             // Clear the LCD screen
  for (count = 0; count <= 180; count++) {
    myServo.write(count);                 // Set servo to the current angle
    displayDistanceAndAngle(distance);    // Display the angle and distance
    delay(300);                           // Delay for smooth movement
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