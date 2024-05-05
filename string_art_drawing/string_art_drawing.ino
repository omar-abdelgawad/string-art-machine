#include <Arduino.h>
/*The motor has normally 200 steps (Nema 17 or Nema 23 stepper motor)
the number of steps is multiplied by 6 due to the gear reduction applied
to the stepper motor, so now 200 steps x 6 = 1200 step for each full
revolution, the man used a microsteping of resolution 1/64 which means
that it needs 1200*64 = 76,800 step for a full revolution, and he gave
300 steps tor move from a nail to another. giving us 76,800/300 = 256
nail
*/
#define NUMBER_OF_NAILS 256

#define STEP_MICROSECONDS 700
#define STEPS_PER_NAIL 300

#define STEP_PIN 5
#define DIR_PIN 4

#define Servo_pin 6

const int NAIL_LIST[] = {};

int g_previous_nail = 0;
int g_opposing_nail = 128;
int g_steps = 0;
bool g_drawing_done = false;

void setup()
{
  initializeNeedleServo();
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop()
{
  if (!g_drawing_done)
  {
    for (int current_nail : NAIL_LIST)
    {
      if (g_previous_nail <= 127)
      {
        if ((g_previous_nail < current_nail) && (g_opposing_nail > current_nail))
        {
          digitalWrite(DIR_PIN, LOW);
          g_steps = (current_nail - g_previous_nail) * STEPS_PER_NAIL;
          goToNextNail();

          // Needing to make it rotate backward a little bit?? may be.
          delay(1000);
          needleBackwards();
          delay(1000);
          moveOneNail();
          delay(1000);
          needleForwards();
          delay(1000);

          g_previous_nail = current_nail;
          g_opposing_nail = (g_previous_nail + 128) % 256;
        }
        else
        {
          if (g_previous_nail > current_nail)
          {
            digitalWrite(DIR_PIN, HIGH);
            g_steps = (g_previous_nail - current_nail) * STEPS_PER_NAIL;
            goToNextNail();

            // Needing to make it rotate backward a little bit?? may be.
            delay(100);
            needleBackwards();
            delay(1000);
            moveOneNail();
            delay(1000);
            needleForwards();
            delay(1000);

            g_previous_nail = current_nail;
            g_opposing_nail = (g_previous_nail + 128) % 256;
          }
          else
          {
            digitalWrite(DIR_PIN, HIGH);
            g_steps = (128 - (current_nail - g_opposing_nail)) * STEPS_PER_NAIL;
            goToNextNail();

            // Needing to make it rotate backward a little bit?? may be.
            delay(100);
            needleBackwards();
            delay(1000);
            moveOneNail();
            delay(1000);
            needleForwards();
            delay(1000);

            g_previous_nail = current_nail;
            g_opposing_nail = (g_previous_nail + 128) % 256;
          }
        }
      }
      else
      {
        if ((g_opposing_nail < current_nail) && (g_previous_nail > current_nail))
        {
          digitalWrite(DIR_PIN, HIGH);
          g_steps = (g_previous_nail - current_nail) * STEPS_PER_NAIL;
          goToNextNail();

          // Needing to make it rotate backward a little bit?? may be.
          delay(1000);
          needleBackwards();
          delay(1000);
          moveOneNail();
          delay(1000);
          needleForwards();
          delay(1000);

          g_previous_nail = current_nail;
          g_opposing_nail = (g_previous_nail + 128) % 256;
        }
        else
        {
          if (current_nail > g_previous_nail)
          {
            digitalWrite(DIR_PIN, LOW);
            g_steps = (current_nail - g_previous_nail) * STEPS_PER_NAIL;
            goToNextNail();

            // Needing to make it rotate backward a little bit?? may be.
            delay(1000);
            needleBackwards();
            delay(1000);
            moveOneNail();
            delay(1000);
            needleForwards();
            delay(1000);

            g_previous_nail = current_nail;
            g_opposing_nail = (g_previous_nail + 128) % 256;
          }
          else
          {
            digitalWrite(DIR_PIN, HIGH);
            g_steps = (128 - (g_opposing_nail - current_nail)) * STEPS_PER_NAIL;
            goToNextNail();

            // Needing to make it rotate backward a little bit?? may be.
            delay(1000);
            needleBackwards();
            delay(1000);
            moveOneNail();
            delay(1000);
            needleForwards();
            delay(1000);

            g_previous_nail = current_nail;
            g_opposing_nail = (g_previous_nail + 128) % 256;
          }
        }
      }
    }
  }
  g_drawing_done = true;
}
