#include <Servo.h>

Servo servo1;

int pos0 = 10;
int pos_max = 170;

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT);
  servo1.attach(A0);

}

void loop() {
  servo1.write(10);
  int push1 = 0;
 push1 = digitalRead(2);
  if(push1 == 1)
  {

    while(pos0 <= pos_max){
      
    servo1.write(pos0);
    pos0 += 1;
    delay(35);
    }
  }
 delay(1);


}
