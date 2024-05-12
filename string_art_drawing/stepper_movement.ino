/*
moves the stepper g_steps number of times
*/
void goToNextNail(void) {
  _move_n_steps(g_steps);
}
/*
moves the stepper one nail in the same direction
*/
void moveOneNail(void) {
  _move_n_steps(STEPS_PER_NAIL);
}
void _move_n_steps(int n_steps) {
  for (int _ = 0; _ < n_steps; _++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_MICROSECONDS);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_MICROSECONDS);
  }
}

void initializeStepperPins(void) {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}