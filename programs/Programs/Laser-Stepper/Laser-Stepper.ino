#include <Stepper.h>

int in1Pin = A2;
int in2Pin = A3;
int in3Pin = A4;
int in4Pin = A5;
int button1 = 2;

int stepcount = 0;
int stepmax = 100;
int steps = 10;


int button1status = 0;

bool stepdefault = false;


Stepper motor(256, in1Pin, in2Pin, in3Pin, in4Pin);


void setup() {


  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(button1, INPUT);
  
  while(!Serial);
  Serial.begin(9600);
  motor.setSpeed(40);

}

void loop() {
 digitalWrite(button1, HIGH);
 button1status = 1;
 
 /*if(Serial.available()) {
  
  int steps = Serial.parseInt();
    Serial.println(steps);
  motor.step(steps);
  }*/
  if(digitalRead(button1) == LOW){

    while(digitalRead(button1) == LOW){ }
    
    button1status += 1;
    Serial.println(button1status);
    
  } 
  if(button1status > 3){
    button1status = 0;
  }
  switch(button1status){
    case 1:
          stepper_laser(2,3,4,2);

    case 2:

    case 3:


    case 4:
    default:{
      
    }
           
  }
  delay(100);
}

void stepper_laser(int time1, int time2, int time3, int time4){
        if(stepcount <= stepmax){
          motor.step(stepcount);
          stepcount += steps;
          delay(3);
          
          if(digitalRead(button1 == LOW)) {
            exit;
          }
        }else{
           stepcount -= ((2 * stepmax)-2*steps);
        }

  
}

