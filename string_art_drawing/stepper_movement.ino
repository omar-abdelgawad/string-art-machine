/*
moves the stepper g_steps number of times
*/
void goToNextNail(void)
{
  for (int _ = 0; _ < g_steps; _++)
  {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_MICROSECONDS);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_MICROSECONDS);
  }
}

void moveOneNail(void)
{
  for (int x = 0; x < STEPS_PER_NAIL; x++)
  {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_MICROSECONDS);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_MICROSECONDS);
  }
}