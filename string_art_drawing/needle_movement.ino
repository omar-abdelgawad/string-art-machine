#include <Servo.h>
Servo Nedil_Servo;

/*
Moves the needle backwards (out of the canvas).
*/
void needleBackwards()
{
  Nedil_Servo.write(0);
}
/*
Moves the needle Forwards (into the canvas).
*/
void needleForwards()
{
  Nedil_Servo.write(90);
}
/*
Initializes Servo motor (Needle Servo) State.
*/
void initializeNeedleServo(){
    Nedil_Servo.attach(Servo_pin);
}