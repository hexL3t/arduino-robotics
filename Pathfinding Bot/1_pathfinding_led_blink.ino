void setup() {
  // inititalise digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() {
  // turn the LED on (HIGH = voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second (1000ms = 1s)
  delay(1000);
  // turn the LED off (LOW = voltage level)
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a second (1000ms = 1s)
  delay(1000);
}
