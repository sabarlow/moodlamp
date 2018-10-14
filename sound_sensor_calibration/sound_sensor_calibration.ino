// Sound Sensor Calibration
// 
// Open the Serial Monitor to see the values output
// by the microphone.
//
// Turn the small screw on the sound sensor and see how the
// mic level changes. 
// Adjust the screw so that the LED on the sound sensor
// blinks on and off when low levels of sound are present.
//
// This should coincide with a value of approximately 512 
// on the Serial Monitor.

int micPin = A7;

void setup() {
  // Open the serial port
  Serial.begin(9600);
}

void loop() {
  // Read the mic level
  int mic_level = analogRead(micPin);
  // Print it to the Serial Monitor
  Serial.println(mic_level);
  // Wait 200 milliseconds
  delay(200);
}
