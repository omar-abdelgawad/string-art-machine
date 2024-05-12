#include <Arduino.h>
inline void initializeNeedleServo() __attribute__((always_inline));
inline void needleForwards() __attribute__((always_inline));
inline void needleBackwards() __attribute__((always_inline));
inline void initializeStepperPins() __attribute__((always_inline));
inline void goToNextNail(int, int) __attribute__((always_inline));
inline void moveOneNail() __attribute__((always_inline));
/*The motor has normally 200 steps (Nema 17 or Nema 23 stepper motor)
the number of steps is multiplied by 6 due to the gear reduction applied
to the stepper motor, so now 200 steps x 6 = 1200 step for each full
revolution, the man used a microsteping of resolution 1/64 which means
that it needs 1200*64 = 76,800 step for a full revolution, and he gave
300 steps tor move from a nail to another. giving us 76,800/300 = 256
nail
*/
#define NUMBER_OF_NAILS 256
#define STEP_MICROSECONDS 200
#define GEAR_RATIO 6
#define MICRO_STEPPING_FACTOR 16
const int STEPS_PER_NAIL = (200 * GEAR_RATIO * MICRO_STEPPING_FACTOR) / NUMBER_OF_NAILS;

#define STEP_PIN 5
#define DIR_PIN 3
#define Servo_pin 6

const int NAIL_LIST[] = { 64, 128, 64, 0 };

bool g_drawing_done = false;

void setup() {
  initializeNeedleServo();
  initializeStepperPins();
  Serial.begin(9600);
  Serial.println("f setup");
  delay(3000);
}

void loop() {
  if (!g_drawing_done) {
    int previous_nail = 0;
    for (int current_nail : NAIL_LIST) {
      goToNextNail(previous_nail, current_nail);
      // Needing to make it rotate backward a little bit?? may be.
      delay(1000);
      needleBackwards();
      delay(1000);
      moveOneNail();
      delay(1000);
      needleForwards();
      delay(1000);
      previous_nail = current_nail;
    }
  }
  g_drawing_done = true;
}
