/*
initializes arduino STEP_PIN and DIR_PIN to output pins
*/
void initializeStepperPins(void) {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}
/*
moves the stepper from previous_nail to next_nail
*/
void goToNextNail(int previous_nail, int next_nail) {
  int n_steps;
  Serial.println(next_nail);
  int dist_in_clockwise_dir = (next_nail - previous_nail + NUMBER_OF_NAILS) % NUMBER_OF_NAILS;
  if (dist_in_clockwise_dir < NUMBER_OF_NAILS / 2) {
    // rotate canvas clockwise
    Serial.println("CW");
    _setCanvasClockWiseDirection();
    n_steps = (dist_in_clockwise_dir - 1) * STEPS_PER_NAIL;
  } else {
    // rotate canvase counterclockwise
    Serial.println("CCW");
    _setCanvasCounterClockWiseDirection();
    n_steps = (NUMBER_OF_NAILS - dist_in_clockwise_dir - 1) * STEPS_PER_NAIL;
  }
  _move_n_steps(n_steps);
}
/*
moves the stepper one nail in the same direction
*/
void moveOneNail(void) {
  _move_n_steps(STEPS_PER_NAIL);
}

inline void _move_n_steps() __attribute__((always_inline));
void _move_n_steps(int n_steps) {
  for (int _ = 0; _ < n_steps; _++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_MICROSECONDS);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_MICROSECONDS);
  }
}
inline void _setCanvasClockWiseDirection() __attribute__((always_inline));
void _setCanvasClockWiseDirection(void) {
  digitalWrite(DIR_PIN, HIGH);
}
inline void _setCanvasCounterClockWiseDirection() __attribute__((always_inline));
void _setCanvasCounterClockWiseDirection(void) {
  digitalWrite(DIR_PIN, LOW);
}