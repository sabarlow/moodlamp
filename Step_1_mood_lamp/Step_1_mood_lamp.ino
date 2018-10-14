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
// for x from 0 to 180 degrees
// ---------------------------------------------------

// TASK: Add a second LED to this program.
// Make it display the same colour as the first LED.
//
// HINT: look for all uses of variables: redLed, blueLed and greenLed 

float colourSpeed = 0.0001;

int redLed   = 11;  // red LED in Digital Pin 10 (PWM)
int greenLed = 10;  // green LED in Digital Pin 11 (PWM)
int blueLed  = 9;   // blue LED in Digital Pin 9 (PWM)

// store the brightness value for each colour
float redBrightness = 0; 
float greenBrightness = 0;
float blueBrightness = 0;

void setup() {
  pinMode(redLed, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed, OUTPUT);   // tell arduino it's an output
}



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

void loop() {
  for (float x = 0; x < 180; x = x + colourSpeed) {

    // Use a sine wave to cycle nicely through all of the colours
    // calculate the brightness for each led
    redBrightness   = 255 * (sin(x * PI / 180)         + 1) / 2; 
    greenBrightness = 255 * (sin((x + 120) * PI / 180) + 1) / 2; 
    blueBrightness  = 255 * (sin((x + 240) * PI / 180) + 1) / 2; 

    // write the brightness to the leds
    analogWrite(redLed,   redBrightness);        // Red LED brightness
    analogWrite(greenLed, greenBrightness);      // Green LED brightness
    analogWrite(blueLed,  blueBrightness);       // Blue LED brightness
  }
}
