void setup() {
pinMode(LED_BUILTIN, OUTPUT);                   // Initialise digital pin LED_BUILTIN as an output
}

void loop() {
digitalWrite(LED_BUILTIN, HIGH);                // turn LED ON (HIGH = On)
delay(1000);                                    // Wait for 1 Second (1000ms)
digitalWrite(LED_BUILTIN, LOW);                // turn LED OFF (LOW = Off)
delay(1000);                                    // Wait for 1 Second (1000ms)
}
