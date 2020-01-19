#include <Servo.h>

Servo servo1;

int pos0 = 10;
int pos_max = 170;

void setup() {
  Serial.begin(9600);

  servo1.attach(A0);

}

void loop() {
  for(pos0 = 0; pos0 <= pos_max; pos0 += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    servo1.write(pos0); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15ms for the servo to reach the position
  }
  for(pos0 = pos_max; pos0>=0; pos0-=1) // goes from 180 degrees to 0 degrees
  {
    servo1.write(pos0); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15ms for the servo to reach the position
  }
}
