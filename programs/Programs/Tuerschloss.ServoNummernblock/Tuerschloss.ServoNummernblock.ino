#include <Keypad.h>
#include "configuration.h"
#include "Servo_function.h"


#define gruen 11
#define rot  12


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

Servo_function motor;

void setup() {
  Serial.begin(9600);
  pinMode(gruen, OUTPUT);
  pinMode(rot, OUTPUT);
  digitalWrite(gruen, LOW);
  digitalWrite(rot, LOW);


}

void loop() {
 static String temp;
  char key = kpd.getKey();


 
  if(key)
  {
    switch(key)
    {
      case '*':
        for(int i = temp.length(); i >= 0; i-=1)
        {
          temp.remove(i);
        }
        digitalWrite(rot, HIGH);
        delay(20);
        digitalWrite(rot, LOW);
        delay(20);
        digitalWrite(rot, HIGH);

        Serial.println(key);
        break;

      case '#':

        if(temp == password) 
        {
          motor.doorOpen();
          Serial.println("Door opens");
          digitalWrite(gruen, HIGH);
           
        }else
        {
          digitalWrite(gruen, LOW);
          motor.doorClose();
          Serial.println("Door closed");
          digitalWrite(rot, HIGH);
          delay(1000);
          digitalWrite(rot, LOW);
        }
        
        for(int i = temp.length(); i >= 0; i-=1)
        {
          temp.remove(i);
        }
        Serial.println(key);
        break; 
        
      default:
          temp += key;
          Serial.println(key);
    }
  }
  delay(100);
}
