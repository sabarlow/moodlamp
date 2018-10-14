// Smooth RGB mood lamp with music response
//
// Updated 11/10/18
// Author: Shaun Barlow

float colourSpeed = 0.00005;

int redLed1   = 9;  // red LED in Digital Pin 9 (PWM)
int greenLed1 = 10;  // green LED in Digital Pin 10 (PWM)
int blueLed1  = 11;   // blue LED in Digital Pin 11 (PWM)

int redLed2  = 6;  // red LED in Digital Pin 6 (PWM)
int greenLed2 = 5;  // green LED in Digital Pin 5 (PWM)
int blueLed2  = 3;   // blue LED in Digital Pin 3 (PWM)

int micPin = A2; // Analog output of microphone connected to an Analog pin

float redBrightness = 0;
float greenBrightness = 0;
float blueBrightness = 0;

int lastMicLevel = 0; // we'll store the previously read mic level here

// smoothWeight is used in the filter for smoothing out the music response
float smoothWeight = 0.02; 

float lastLowPass = 1; // also used in the filter

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
  for (float x = 0; x < 180; x = x + colourSpeed) {

    int mic_in = analogRead(micPin); // read the volume of sound

    // create code here to change the LEDs based on the volume of sound

    // Use a sine wave to cycle nicely through all of the colours
    redBrightness   = (255 * (sin(x)        + 1) / 2) * lastLowPass;     // calculate the brightness for red led
    greenBrightness = (255 * (sin(x + 60)   + 1) / 2) * lastLowPass;     // calculate the brightness for green led
    blueBrightness  = (255 * (sin(x + 120)  + 1) / 2) * lastLowPass;     // calculate the brightness for blue led

    // write the brightness to the leds
    analogWrite(redLed1,   redBrightness);        // Red LED brightness
    analogWrite(greenLed1, greenBrightness);      // Green LED brightness
    analogWrite(blueLed1,  blueBrightness);       // Blue LED brightness

    analogWrite(redLed2,   redBrightness);        // Red LED brightness
    analogWrite(greenLed2, greenBrightness);      // Green LED brightness
    analogWrite(blueLed2,  blueBrightness);       // Blue LED brightness
  }
}



