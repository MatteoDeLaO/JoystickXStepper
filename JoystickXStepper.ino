#include <Stepper.h> 
#define STEPS 32 //  define number of steps per revolution
#define IN1  11 // define stepper  motor control pins
#define IN2  10
#define IN3   9
#define  IN4   8
Stepper stepper(STEPS, IN4, IN2,  IN3, IN1); // initialize stepper library
#define  joystick  A0 // joystick pot output is connected to Arduino A0
void setup()
{ 
}
void loop()
{
  int val = analogRead(joystick);  //  read analog value from the potentiometer
  if(  (val > 500)  && (val < 523) ) // if the joystic is in the middle ===> stop the motor
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,  LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else
  {
    while (val  >= 523) // move the motor in the first direction
    {
      int speed_  = map(val, 523, 1023, 5, 500);// map the speed between 5 and 500 rpm
      stepper.setSpeed(speed_); // set motor speed
      stepper.step(1);// move the motor (1 step)
      val  = analogRead(joystick);
    }
    while (val <= 500)// move the motor in the other direction
    {
      int speed_ = map(val, 500, 0, 5, 500);// map the speed between 5 and 500 rpm
      stepper.setSpeed(speed_); // set motor speed
      stepper.step(-1);// move the motor (1 step)
      val  = analogRead(joystick);
    }
  }
}

