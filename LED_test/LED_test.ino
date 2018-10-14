int redLed1   = 9;  // red LED in Digital Pin 9 (PWM)
int greenLed1 = 10;  // green LED in Digital Pin 10 (PWM)
int blueLed1  = 11;   // blue LED in Digital Pin 11 (PWM)

int redLed2   = 6;  // red LED in Digital Pin 6 (PWM)
int greenLed2 = 3;  // green LED in Digital Pin 3 (PWM)
int blueLed2  = 5;   // blue LED in Digital Pin 5 (PWM)

void setup() {
  pinMode(redLed1, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed1, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed1, OUTPUT);   // tell arduino it's an output

  pinMode(redLed2, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed2, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed2, OUTPUT);   // tell arduino it's an output

  // Set all the outputs to low. That is, turn off all LEDs.
  // We can test that each pin is connected to the correct
  // LED pin by changing LOW to HIGH one at a time.
  digitalWrite(redLed1, LOW);
  digitalWrite(greenLed1, LOW);
  digitalWrite(blueLed1, LOW);

  digitalWrite(redLed2, LOW);
  digitalWrite(greenLed2, LOW);
  digitalWrite(blueLed2, LOW);

}

void loop() {
  // Nothing in our loop
}
