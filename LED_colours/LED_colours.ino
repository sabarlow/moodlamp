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
}

void loop() {
  // analogWrite(pin_number, brightness 0-255);
  // We can change the brightness of each LED using 
  // a value between 0 and 255.

  // What colour is this?
  analogWrite(redLed1, 255);
  analogWrite(greenLed1, 0);
  analogWrite(blueLed1, 255);

  analogWrite(redLed2, 127);
  analogWrite(greenLed2, 127);
  analogWrite(blueLed2, 0);
}
