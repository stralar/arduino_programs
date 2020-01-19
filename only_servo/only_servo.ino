#include <Servo.h>

Servo servo1;
int in1servo = 13;

int pos0 = 80;
int pos_max = 90;
int pos_default = 0;

int serial_number = 0;


void setup() {
  // put your setup code here, to run once:
  while(!Serial);
  Serial.begin(9600);

   pinMode(in1servo, INPUT);
    servo1.attach(in1servo);
    servo1.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
   // servo1.write(serial.write());
  // servo1.write(Serial.read());
     /* for(int pos_default = 0; pos_default <= pos_max; pos_default += 10b)
     {
        servo1.write(pos_default);
        delay(100);
      }*/
      //servo1.write(30);
      //delay(200);
      //servo1.write(120);

  
}
