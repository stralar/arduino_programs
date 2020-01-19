#include "Arduino.h"
#include <Stepper.h>
#include "Stepper_function.h"

int in1Pin = A2;
int in2Pin = A3;
int in3Pin = A4;
int in4Pin = A5;

boolean doorstatus = false;
int steps = 10;
int stepcount = 0;
int stepsleft = 2048;
int stepsright = -2048;

Stepper motor(256, in1Pin, in2Pin, in3Pin, in4Pin);



Stepper_function::Stepper_function()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  
}

void Stepper_function::doorOpen()
{   
        motor.setSpeed(40);

        if(doorstatus != true)
        {
              motor.step(stepsleft);
              delay(3);
          
          Serial.println("O");
          doorstatus = true;
        }
          
}

void Stepper_function::doorClose()
{
          motor.setSpeed(60);

      if(doorstatus != false)
       
      {
          motor.step(stepsright); 
          Serial.println("C");
          doorstatus = false;
       }
}

