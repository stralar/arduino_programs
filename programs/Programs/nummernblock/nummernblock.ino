#include <Servo.h>
#include <Keypad.h>
#include "configuration.h"


#define ledpin 13


const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


Servo servo1;
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);

  servo1.attach(12);
  servo1.write(15);

}

void loop() {
 static String temp;
  char key = kpd.getKey();


  if(temp == password)
  {
      for(int i = 0; i <= 140; i+=1)
      {
        servo1.write(i);
        delay(15);
      }
      
     for(int i = temp.length(); i >= 0; i-=1)
      {
        temp.remove(i);
      }
        
      digitalWrite(ledpin, HIGH);
  }
 
  if(key)
  {
    switch(key)
    {
      case '*':
        for(int i = temp.length(); i >= 0; i-=1)
        {
          temp.remove(i);
        }
        digitalWrite(ledpin, LOW);
        servo1.write(15);
        Serial.println(key);
        break;
 
      default:
          temp += key;
          Serial.println(key);
    }
  }
}
