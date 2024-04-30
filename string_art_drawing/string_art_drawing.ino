#include <Servo.h>

#define Number_of_nails 256
/*The motor has normally 200 Steps (Nema 17 or Nema 23 stepper motor)
the number of steps is multiplied by 6 due to the gear reduction applied
to the stepper motor, so now 200 steps x 6 = 1200 step for each full 
revolution, the man used a microsteping of resolution 1/64 which means
that it needs 1200*64 = 76,800 step for a full revolution, and he gave
300 steps tor move from a nail to another. giving us 76,800/300 = 256
nail
*/ 

#define step_microseconds 700
#define Steps_per_nail 300

#define Step_pin 5
#define Dir_pin 4

#define Servo_pin 6
Servo Nedil_Servo;

int Nail_List[] = {};

int Current_nail = 0;
int adjacent_nail = 1;
int Opposing_nail = 128;
int Steps = 0;
bool drawing_done = false;

void Nedil_Backward(){
  Nedil_Servo.write(0);
}
void Nedil_Forward(){
  Nedil_Servo.write(90);
}

void setup() {
  Nedil_Servo.attach(Servo_pin);
  pinMode(Step_pin, OUTPUT);
  pinMode(Dir_pin, OUTPUT);
}

void loop() {
  if (!drawing_done){
    for (int Nail : Nail_List){
      if (Current_nail <= 127){
        if ((Current_nail < Nail) && (Opposing_nail > Nail)){
          digitalWrite(Dir_pin, LOW);
          Steps = (Nail - Current_nail) * Steps_per_nail;
          for(int x = 0; x < Steps; x++){
            digitalWrite(Step_pin, HIGH);
            delayMicroseconds(step_microseconds);
            digitalWrite(Step_pin, LOW);
            delayMicroseconds(step_microseconds);
          }
          
          //Needing to make it rotate backward a little bit?? may be.
          delay(1000);
          Nedil_Backward();
          delay(1000);
          for(int x = 0; x < 300; x++){
            digitalWrite(Step_pin, HIGH);
            delayMicroseconds(step_microseconds);
            digitalWrite(Step_pin, LOW);
            delayMicroseconds(step_microseconds);
          }
          delay(1000);
          Nedil_Forward();
          delay(1000);

          Current_nail = Nail;
          Opposing_nail = (Current_nail + 128) % 256;
        }
        else {
          if (Current_nail > Nail){
            digitalWrite(Dir_pin, HIGH);
            Steps = (Current_nail - Nail) * Steps_per_nail;
            for(int x = 0; x < Steps; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            
            //Needing to make it rotate backward a little bit?? may be.
            delay(100);
            Nedil_Backward();
            delay(1000);
            for(int x = 0; x < 300; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            delay(1000);
            Nedil_Forward();
            delay(1000);

            Current_nail = Nail;
            Opposing_nail = (Current_nail + 128) % 256;
          }
          else {
            digitalWrite(Dir_pin, HIGH);
            Steps = (128 - (Nail - Opposing_nail)) * Steps_per_nail;
            for(int x = 0; x < Steps; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            
            //Needing to make it rotate backward a little bit?? may be.
            delay(100);
            Nedil_Backward();
            delay(1000);
            for(int x = 0; x < 300; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            delay(1000);
            Nedil_Forward();
            delay(1000);

            Current_nail = Nail;
            Opposing_nail = (Current_nail + 128) % 256;
          }
        }
      }
      else {
        if ((Opposing_nail < Nail) && (Current_nail > Nail)){
          digitalWrite(Dir_pin, HIGH);
          Steps = (Current_nail - Nail) * Steps_per_nail;
          for(int x = 0; x < Steps; x++){
            digitalWrite(Step_pin, HIGH);
            delayMicroseconds(step_microseconds);
            digitalWrite(Step_pin, LOW);
            delayMicroseconds(step_microseconds);
          }
          
          //Needing to make it rotate backward a little bit?? may be.
          delay(1000);
          Nedil_Backward();
          delay(1000);
          for(int x = 0; x < 300; x++){
            digitalWrite(Step_pin, HIGH);
            delayMicroseconds(step_microseconds);
            digitalWrite(Step_pin, LOW);
            delayMicroseconds(step_microseconds);
          }
          delay(1000);
          Nedil_Forward();
          delay(1000);

          Current_nail = Nail;
          Opposing_nail = (Current_nail + 128) % 256;
        }
        else {
          if (Nail > Current_nail){
            digitalWrite(Dir_pin, LOW);
            Steps = (Nail - Current_nail) * Steps_per_nail;
            for(int x = 0; x < Steps; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            
            //Needing to make it rotate backward a little bit?? may be.
            delay(1000);
            Nedil_Backward();
            delay(1000);
            for(int x = 0; x < 300; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            delay(1000);
            Nedil_Forward();
            delay(1000);

            Current_nail = Nail;
            Opposing_nail = (Current_nail + 128) % 256;
          }
          else{
            digitalWrite(Dir_pin, HIGH);
            Steps = (128 - (Opposing_nail - Nail)) * Steps_per_nail;
            for(int x = 0; x < Steps; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            
            //Needing to make it rotate backward a little bit?? may be.
            delay(1000);
            Nedil_Backward();
            delay(1000);
            for(int x = 0; x < 300; x++){
              digitalWrite(Step_pin, HIGH);
              delayMicroseconds(step_microseconds);
              digitalWrite(Step_pin, LOW);
              delayMicroseconds(step_microseconds);
            }
            delay(1000);
            Nedil_Forward();
            delay(1000);

            Current_nail = Nail;
            Opposing_nail = (Current_nail + 128) % 256;
          }
        }
      }
    }
  }
  drawing_done = true;
}
