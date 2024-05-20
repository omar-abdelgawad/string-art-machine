#include <Servo.h>
Servo g_NeedleServo;
/*
Initializes Servo motor (Needle Servo) State.
*/
void initializeNeedleServo() {
  g_NeedleServo.attach(Servo_pin);
}

/*
Moves the needle backwards (out of the canvas).
*/
void needleBackwards() {
  g_NeedleServo.write(0);
}

/*
Moves the needle Forwards (into the canvas).
*/
void needleForwards() {
  g_NeedleServo.write(90);
}
