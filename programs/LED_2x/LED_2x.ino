#include <Stepper.h>
int verzoegert = 30;
Stepper motor(512, A0, A1, A2, A3);
void setup() {
  // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);

  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);

  while(!Serial);

  Serial.begin(9600);
  motor.setSpeed(20);


}

void loop() {
  // put your main code here, to run repeatedly:
/*
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);*/

  //motor.step(10);


   for(int j=0; j <= 1; j++){
    if(j == 0){
      motor.step(30);
      digitalWrite(13,HIGH);
      delay(verzoegert);
      digitalWrite(12,LOW); 
      motor.step(-30);     
    }
    if(j == 1){
          motor.step(30);
    digitalWrite(12,HIGH);
    delay(verzoegert);
    digitalWrite(13,LOW); 
    motor.step(-30);  
    }

   }
   
  //delay(20);

}
