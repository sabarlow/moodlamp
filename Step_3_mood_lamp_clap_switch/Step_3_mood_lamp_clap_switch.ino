// Smooth RGB mood lamp with clap switch
//
// Updated 11/10/18
// Author: Shaun Barlow
// ---------------------------------------------------

// change this value to adjust the sensitivity of the clap switch
int clapVolume = 20; 

float colourSpeed = 0.00005;

int redLed1   = 9;  // red LED in Digital Pin 9 (PWM)
int greenLed1 = 10;  // green LED in Digital Pin 10 (PWM)
int blueLed1  = 11;   // blue LED in Digital Pin 11 (PWM)

int redLed2  = 6;  // red LED in Digital Pin 6 (PWM)
int greenLed2 = 5;  // green LED in Digital Pin 5 (PWM)
int blueLed2  = 3;   // blue LED in Digital Pin 3 (PWM)

int micPin = A7; // Analog output of microphone connected to an Analog pin

bool lightsOn = true; // store whether the lights are on or off

float redBrightness = 0;
float greenBrightness = 0;
float blueBrightness = 0;

int lastMicLevel = 0; // we'll store the previously read mic level here

void setup() {
  pinMode(redLed1, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed1, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed1, OUTPUT);   // tell arduino it's an output

  pinMode(redLed2, OUTPUT);    // tell arduino it's an output
  pinMode(greenLed2, OUTPUT);  // tell arduino it's an output
  pinMode(blueLed2, OUTPUT);   // tell arduino it's an output

  lastMicLevel = analogRead(micPin); // read the volume of sound
}

void loop() {
  //  The "for" loop lets us step through a set of values.
  for (float x = 0; x < 180; x = x + colourSpeed) {
    int mic_in = analogRead(micPin); // read the volume of sound

    // compare this volume with the previous volume
    int difference = lastMicLevel - mic_in;

    if (difference > clapVolume) {
      lightsOn = !lightsOn;      // if lightsOn turn off. If not, turn on.
      delay(100);
      lastMicLevel = analogRead(micPin); // read the volume of sound
    } else {
      lastMicLevel = mic_in;     // save this value for the next round
    }

    // Use a sine wave to cycle nicely through all of the colours
    redBrightness   = (255 * (sin(x)        + 1) / 2);     // calculate the brightness for red led
    greenBrightness = (255 * (sin(x + 60)   + 1) / 2);     // calculate the brightness for green led
    blueBrightness  = (255 * (sin(x + 120)  + 1) / 2);     // calculate the brightness for blue led

    if (lightsOn) {
      // write the brightness to the leds
      analogWrite(redLed1,   redBrightness);        // Red LED brightness
      analogWrite(greenLed1, greenBrightness);      // Green LED brightness
      analogWrite(blueLed1,  blueBrightness);       // Blue LED brightness

      analogWrite(redLed2,   redBrightness);        // Red LED brightness
      analogWrite(greenLed2, greenBrightness);      // Green LED brightness
      analogWrite(blueLed2,  blueBrightness);       // Blue LED brightness
    } else {
      // if the lights are off, we just send 0 to each LED
      analogWrite(redLed1,   0);        // Red LED brightness
      analogWrite(greenLed1, 0);      // Green LED brightness
      analogWrite(blueLed1,  0);       // Blue LED brightness

      analogWrite(redLed2,   0);        // Red LED brightness
      analogWrite(greenLed2, 0);      // Green LED brightness
      analogWrite(blueLed2,  0);       // Blue LED brightness
    }
  }
}



