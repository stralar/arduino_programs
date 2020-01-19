#include "arduino.h"
#include "Servo_function.h"
#include "configuration.h"
#include <Servo.h>



int in1Pin = 10;

int servoClose = 0;

bool doorOpenStatus = false;

Servo  myservo;

Servo_function::Servo_function(){


}


void Servo_function::doorOpen()
{   
    

        if(doorOpenStatus != true)
        {
              myservo.attach(in1Pin);
              myservo.write(servoOpen);
              delay(500);
              myservo.detach();          
              doorOpenStatus = true;
        }

}

void Servo_function::doorClose()
{

      if(doorOpenStatus != false)
      {
          myservo.attach(in1Pin);
          myservo.write(servoClose);
          delay(500);
          myservo.detach();
          doorOpenStatus = false;
       }

}

