#include <Wire.h>                    // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>      // Include library for LCD display

// Initialize the LCD (Update address to 0x27 or 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with address 0x27 and 16x2 dimensions

// Declare variables
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
  Wire.begin();                     // Initialize I2C communication
  lcd.begin(16, 2);                 // Initialize LCD with 16x2 dimensions
  lcd.backlight();                  // Turn on the LCD backlight
}

void loop() {
  delay(300);                       // 0.3s Delay for stability
  lcdCounter();
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