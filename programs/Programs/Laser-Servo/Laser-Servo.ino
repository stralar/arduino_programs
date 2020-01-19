#include <Servo.h>

Servo servo1;
int in1servo = 13;
int button1 = 0;

int pos0 = 85;
int pos_max = 120;
int pos_default = 90;
int servo_speed = 30;

int button1status = 1;

int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;
int led7 = 6;
int led8 = 5;
int led9 = 4;
int led10 = 3;
int led11 = 2;


int time_Counter_On = 0;
int time_Counter_Off = 0;

int pin_num_min = 9;             //min 3 by arduino nano
int pin_num_max = 12;             //max 12 by arduino nano

void setup() {

  pinMode(in1servo, INPUT);
  pinMode(button1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);


  
  while(!Serial);
  Serial.begin(9600);

    servo1.attach(in1servo);
    servo1.write(pos_default);
}

void loop() {
 digitalWrite(button1, HIGH);
 digitalWrite(led11, HIGH);
 digitalWrite(led10, HIGH);
 digitalWrite(led9, HIGH);
 digitalWrite(led8, HIGH);
 digitalWrite(led7, HIGH);
 digitalWrite(led6, HIGH);
 digitalWrite(led5, HIGH);
 
  if(digitalRead(button1) == LOW){
    while(digitalRead(button1) == LOW){ }
    
    button1status += 1;
    Serial.println(button1status);
  } 
      servo_laser(8,8,0,0);                                   //servo_laser(On-time, OFF-time, nothing, nothing)

    delay(100);
}

void servo_laser(int time1, int time2, int time3, int time4){
          servo1.write(pos_default);
          int pos = pos_default;
          

          while(digitalRead(button1) != LOW){
              
              Serial.println(time_Counter_On);
              for(; pos <= pos_max; pos += 1){

                    laser_time(time1,time2,1,1,true);
                    laser_time(time1,time2,1,1,false);

                    servo1.write(pos);                    
                    if(digitalRead(button1) == LOW) return;
                    delay(servo_speed);          
              }
              for(; pos >= pos0; pos -= 1){

                    laser_time(time1,time2,1,1,true);
                    laser_time(time1,time2,1,1,false);
                
                    servo1.write(pos);                    
                    if(digitalRead(button1) == LOW) return;    
                    delay(servo_speed);
              }
              
          }                 
}


void laser_time(int time1, int time2, int time3, int time4, bool pin_On){
         if(pin_On == true && time_Counter_On < time1){
            time_Counter_On += 1;
            time_Counter_Off = 0;
            for(int pin_min = pin_num_min; pin_min <= pin_num_max; pin_min += 1){
                digitalWrite(pin_min,HIGH);
            }
         }
         
          if(pin_On == false && time_Counter_Off < time2 && time_Counter_On >= time1) {  
              time_Counter_Off += 1;
              
              if(time_Counter_Off == time2)time_Counter_On = 0;
              
             for(int pin_min = pin_num_min; pin_min <= pin_num_max; pin_min += 1){
                 digitalWrite(pin_min,LOW);                 
             }
          }
  
}

