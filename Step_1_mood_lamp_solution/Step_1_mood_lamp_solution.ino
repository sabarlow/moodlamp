// Smooth RGB mood lamp
// Changes an RGB LED's color smoothly.
//
// Updated 11/10/18
// Author: Shaun Barlow
// ---------------------------------------------------
// The brightness of the leds follows these equations:
// Red = sin(x)
// Green = sin(x + 60)
// Blue = sin(x + 120)
// for x from 0 to 360 degrees
// ---------------------------------------------------

// TASK: Add a second LED to this program.
// Make it display the same colour as the other LED.
//
// HINT: look for all uses of variables: redLed, blueLed and greenLed

float colourSpeed = 0.001;

int redLed1   = 9;  // red LED in Digital Pin 9 (PWM)
int greenLed1 = 10;  // green LED in Digital Pin 10 (PWM)
int blueLed1  = 11;   // blue LED in Digital Pin 11 (PWM)

int redLed2   = 6;  // red LED in Digital Pin 6 (PWM)
int greenLed2 = 3;  // green LED in Digital Pin 3 (PWM)
int blueLed2  = 5;   // blue LED in Digital Pin 5 (PWM)

float redBrightness = 0;
float greenBrightness = 0;
float blueBrightness = 0;

void setup() {
  pinMode(redLed1, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed1, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed1, OUTPUT);   // tell arduino it's an output

  pinMode(redLed2, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed2, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed2, OUTPUT);   // tell arduino it's an output
}

void loop() {
  //  The "for" loop lets us step through a set of values.
  //  For example, this "for" loop starts with the variable called "x" at a value of 0.
  //  It then executes all of the code inside its {} (curly braces).
  //  Then it adds the value of colourSpeed to x and runs the code in its {} again.
  //    That means x = 0 + colourSpeed  = colourSpeed
  //  Then it adds colourSpeed to x and runs the code in its {} again.
  //    That means x = colourSpeed + colourSpeed = 2 * colourSpeed
  //  Then it adds colourSpeed to x and runs the code in its {} again.
  //    That means x = 2 * colourSpeed + colourSpeed = 3 * colourSpeed
  //  It keeps doing this...
  //  UNTIL x is no longer less than 180.
  //  Then the "for" loop ends and the subsequent code is run.
  //
  //  In this case, there isn't any other code after the "for" loop,
  //  so the main loop starts again (i.e. we begin the "for" loop afresh with "x" = 0).
  for (float x = 0; x < 360; x = x + colourSpeed) {

    // Use a sine wave to cycle nicely through all of the colours
    redBrightness   = 255 * (sin(x * PI / 180)         + 1) / 2; // calculate the brightness for red led
    greenBrightness = 255 * (sin((x + 120) * PI / 180) + 1) / 2; // calculate the brightness for green led
    blueBrightness  = 255 * (sin((x + 240) * PI / 180) + 1) / 2; // calculate the brightness for blue led

    // write the brightness to the leds
    analogWrite(redLed1,   redBrightness);        // Red LED brightness
    analogWrite(greenLed1, greenBrightness);      // Green LED brightness
    analogWrite(blueLed1,  blueBrightness);       // Blue LED brightness

    analogWrite(redLed2,   redBrightness);        // Red LED brightness
    analogWrite(greenLed2, greenBrightness);      // Green LED brightness
    analogWrite(blueLed2,  blueBrightness);       // Blue LED brightness
  }
}
