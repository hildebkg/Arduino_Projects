/* This is the code that I made for our first project in ENED 1100. Our goal was to create a motion-activated hand sanitizer dispenser. 
The idea was to use a PIR sensor combined with a servo motor to dispense sanitizer from a bottle. When the PIR sensor detected motion,
the servo motor, which was attached to the bottom of the bottle, would  move once and allow hand sanitizer to fall out before moving 
back to its original position to again block the flow of the hand sanitizer. */

#include <Servo.h>           // makes use of the servo library that is available for use with Arduino boards
Servo servo;

int pinM = 8;                // the pin that the servo motor is attached to
int sensor = 4;              // the pin that the sensor is attached to
int state = LOW;             // default: no motion detected
int val = 0;                 // variable for sensor

void setup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input
  servo.attach(pinM);        // tells board which pin the servo motor is attached to
}

void loop() {                 // code that runs repeatedly
  val = digitalRead(sensor); // read sensor value
  if (val == HIGH) {         // check if the sensor is HIGH
    servo.write(90);         // servo motor moves back and forth once
    delay(1000);
    servo.write(0);
    delay(1000);
  } else {
      servo.write(0);        // turn servo OFF
      delay(1000);           // wait one second 
    }
}
