/*

   @version 0.1
   @author Lars Stratmann

   Program:
   0 Normal
   1 ON/OFF
   2 Flash
   3 Dynamisch 1
   4 Dynamisch 2
   5 Dynamisch 3
   6 Dynamisch 4
   7 Dynamisch 5
   8 Dynamisch 6
   9 Jump 3
   10 Jumo 7
   11 Auto
   12 Fade 3
   13 Fade 7

   IRCode
    0  1  2  3
    4  5  6  7
    8  9 10 11
   12 13 14 15
   16 17 18 19
   20 21 22 23
   24 25 26 27
   28 29 30 31
   32 33 34 35
   36 37 38 39
   40 41 42 43 
*/
#include "arduino.h"
#include "RGB_function.h"
#include "IRCODE_Table.h"
#include "configuration.h"
#include <IRremote.h>


IRrecv irrecv(RECV_PIN);

decode_results results;

boolean RED_STATE = HIGH;
boolean GREEN_STATE = LOW;
boolean BLUE_STATE = LOW;

// Variable die durch den Interrupt verändert wird
volatile boolean tmpSound = false;
volatile boolean holdSound = false;
volatile unsigned long counter;

boolean clapStatus = false;


//RGB_function(int IRCode, int Program, int Brightness_R, int Brightness_G, int Brightness_B, float RED_IDLES, float GREEN_IDLES,
//              float BLUE_IDLES, int Direction_R, int Direction_G, int Direction_B, int Timer_R, int Timer_G, int Timer_B
// IDLES: # of loop cycles to wait before changing the brightness level
// Timer: counter of loop cycles left to wait before changing the pin value

int localBrightness_R = 127;
int localBrightness_G = 127;
int localBrightness_B = 127;

int localTimer_R = 0;
int localTimer_G = 0;
int localTimer_B = 0;

// LOOP_Delay - localSPEED 
int localSPEED = Default_Speed;

//   # of loop cycles to wait before changing the brightness level
float RED_IDLES = 2;
float GREEN_IDLES = 4;
float BLUE_IDLES = 6;

//   direction of change in brightness level (-1 or +1)
  int localDirection_R = 1;
  int localDirection_G = -1;
  int localDirection_B = 1;

int program = 0;



RGB_function red = RGB_function(5, 0, 255, 0, 0);
RGB_function red1 = RGB_function(9, 0, 255, 50, 0);
RGB_function red2 = RGB_function(13, 0, 255, 100, 0);
RGB_function red3 = RGB_function(17, 0, 255, 200, 0);
RGB_function red4 = RGB_function(21, 0, 255, 255, 0);

RGB_function green = RGB_function(6, 0, 0, 255, 0);
RGB_function green1 = RGB_function(10, 0, 0, 200, 255);
RGB_function green2 = RGB_function(14, 0, 0, 255, 255);
RGB_function green3 = RGB_function(18, 0, 0, 102, 204);
RGB_function green4 = RGB_function(22, 0, 0, 128, 255);

RGB_function blue = RGB_function(7, 0, 0, 0, 255);
RGB_function blue1 = RGB_function(11, 0, 0, 0, 135);
RGB_function blue2 = RGB_function(15, 0, 25, 0, 51);
RGB_function blue3 = RGB_function(19, 0, 102, 0, 102);
RGB_function blue4 = RGB_function(23, 0, 153, 0, 76);

RGB_function white = RGB_function(7, 0, 255, 255, 255);
RGB_function white1 = RGB_function(12, 0, 255, 204, 230);
RGB_function white2 = RGB_function(16, 0, 229, 204, 255);
RGB_function white3 = RGB_function(20, 0, 153, 255, 255);
RGB_function white4 = RGB_function(24, 0, 102, 255, 255);



long ITCode_List[] = {
  LIGHT_HIGH,
  LIGHT_LOW,
  NEXT,
  POWER,
  RED,
  GREEN,
  BLUE,
  WHITE,
  RED1,
  GREEN1,
  BLUE1,
  WHITE1,
  RED2,
  GREEN2,
  BLUE2,
  WHITE2,
  RED3,
  GREEN3,
  BLUE3,
  WHITE3,
  RED4,
  GREEN4,
  BLUE4,
  WHITE4,
  REDUP,
  GREENUP,
  BLUEUP,
  QUICK,
  REDDOWN,
  GREENDOWN,
  BLUEDOWN,
  SLOW,
  DIY1,
  DIY2,
  DIY3,
  AUTO,
  DIY4,
  DIY5,
  DIY6,
  FLASH,
  JUMP3,
  JUMP7,
  FADE3,
  FADE7
};

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(SOUNDSENSOR_PIN), setSound, LOW);

  pinMode(SOUNDSENSOR_PIN, INPUT);

  irrecv.enableIRIn();
  
}
int delayMilli = 2500;

// Methode für den Interrupt
void setSound(){
  if(tmpSound == false) {
   // Serial.println("First Clap");
    tmpSound = true;
    delayMicroseconds(delayMilli);
    counter = millis();
  } else 
    if((millis() - counter) > 2 && (millis() - counter) < 800 && holdSound == false){
     // Serial.println("Secound Clap");
      holdSound = true;
      tmpSound = false;
      delayMicroseconds(delayMilli);
  } else { 
      //Serial.println("Clear");
      tmpSound = false; 
      delayMicroseconds(delayMilli);

    }
}

void setCollors(RGB_function newMode) {
  
  localBrightness_R = newMode.getBrightness_R();
  localBrightness_G = newMode.getBrightness_G();
  localBrightness_B = newMode.getBrightness_B();

  // In welcher stärke sich die Farbe ändert
  localTimer_R = newMode.getTimer_R();   
  localTimer_G = newMode.getTimer_G();
  localTimer_B = newMode.getTimer_B();
  
  localSPEED = Default_Speed;

  program = 0;
}

void setCollors(int _red, int _green, int _blue) {
  
  localBrightness_R = _red;
  localBrightness_G = _green;
  localBrightness_B = _blue;

  // In welcher stärke sich die Farbe ändert
  localTimer_R = 0;   
  localTimer_G = 0;
  localTimer_B = 0;
  
  localSPEED = Default_Speed;

  program = 0;
}


void setLIGHT_HIGH(){
  localBrightness_R += Brightness_UpDow;
  localBrightness_G += Brightness_UpDow;
  localBrightness_B += Brightness_UpDow;
}
void setLIGHT_LOW(){
  localBrightness_R -= Brightness_UpDow;
  localBrightness_G -= Brightness_UpDow;
  localBrightness_B -= Brightness_UpDow;
}

void setRED_HIGH(){
  localBrightness_R += Brightness_UpDow;
}
void setRED_LOW(){
  localBrightness_R -= Brightness_UpDow;
}


void setGREEN_HIGH(){
  localBrightness_G += Brightness_UpDow;
}
void setGREEN_LOW(){
  localBrightness_G -= Brightness_UpDow;
}


void setBLUE_HIGH(){
  localBrightness_B += Brightness_UpDow;
}
void setBLUE_LOW(){
  localBrightness_B -= Brightness_UpDow;
}

void setDefaultSpeed() {
  localSPEED = Default_Speed;
}

void setSpeedUP() {
  if(localSPEED > MAX_SPEED) {
    localSPEED -= 10;
  }
}

void setSpeedDOWN() {
  if(localSPEED < MIN_SPEED) {
    localSPEED += 10;
  }
}

void setClap() {
  if(clapStatus){
    Serial.println("OFF");
    clapStatus = false;
  } else { 
    Serial.println("ON");
    clapStatus = true;
    }
}


void setFLASH() {
  setCollors(white);

  program = 2;
  
  localTimer_R = 255;
  localTimer_G = 255;
  localTimer_B = 255;  
}

void setON_OFF() {
  if(RED_STATE == HIGH || GREEN_STATE == HIGH || BLUE_STATE == HIGH) {
    RED_STATE = LOW;
    GREEN_STATE = LOW;
    BLUE_STATE = LOW;
    
    Serial.println("OFF");
  } else {
    RED_STATE = HIGH;
    GREEN_STATE = HIGH;
    BLUE_STATE = HIGH;
    
    Serial.println("ON");
  }
}



void loop() {
  setCollors(white);


  if(holdSound == true) {
    setON_OFF();
    //delay(250);   
    holdSound = false;
    Serial.println("Sound");
  }

  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    int code = -1;
    
    for (int i = 0; i < 44; i++)
    {
     if (results.value == ITCode_List[i])
      {
        Serial.print("FOUND: ");
        Serial.println(i);
        code = i;
      }
     }     
     
      switch(code)
      {
        // Brightness higher
        case 0:
          Serial.println("Light higher");
          setLIGHT_HIGH();
          break;
          
        // Brightness lower
        case 1:
          Serial.println("Light lower");
          setLIGHT_LOW();
          break;
          
        // Next                                 
        case 2:
          Serial.println("Clap");
          setClap();
          break;
          
        // ON/OFF
        case 3:
          Serial.println("POWER");
          setON_OFF();        
          break;

        // RED
        case 4:
          Serial.println("Red");
          setCollors(red);
          break;

         // GREEN
        case 5:
          Serial.println("Green");
          setCollors(green);
          break;

        // BLUE
        case 6:
          Serial.println("Blue");
          setCollors(blue);
          break;

        // WHITE 
        case 7:
          Serial.println("White");
          setCollors(white);
          break;
          
        case 8:
          setCollors(255, 50, 0);
          break;

        case 9:
          setCollors(green1);
          break;
          
        case 10:
          setCollors(blue1);
          break;
          
        case 11:
          setCollors(white1);
          break;
          
        case 12:
          setCollors(red2);
          break;
          
        case 13:
          setCollors(green2);
          break;
          
        case 14:
          setCollors(blue2);
          break;
          
        case 15:
          setCollors(white2);
          break;
          
        case 16:
          setCollors(red3);
          break;
          
        case 17:
          break;
          
        case 18:
          break;
          
        case 19:
          break;
          
        case 20:
          break;
          
        case 21:
          break;
          
        case 22:
          break;
          
        case 23:
          break;

        // REDUP
        case 24:
          setRED_HIGH();
          break;

        // GREENUP
        case 25:
          setGREEN_HIGH();
          break;
          
        // BLUEUP  
        case 26:
          setBLUE_HIGH();
          break;
          
        // QUICK   
        case 27:
          setSpeedUP();
          break;
          
        // REDDOWN  
        case 28:
          setRED_LOW();
          break;
          
        // GREENDOWN  
        case 29:
          setGREEN_LOW();
          break;
          
        // BLUEDOWN  
        case 30:
          setBLUE_LOW();
          break;
          
        // SLOW
        case 31:
          setSpeedDOWN();
          break;
          
        // DIY1  
        case 32:
          break;
          
        // DIY2  
        case 33:
          break;
          
        // DIY3  
        case 34:
          break;
          
        // AUTO  
        case 35:
          program = 11;
          break;
          
        // DIY4  
        case 36:
          break;
          
        // DIY5  
        case 37:
          break;
          
        // DIY6  
        case 38:
          break;
          
        // FLASH  
        case 39:
          Serial.println("FLASH");
          setFLASH();
          break;
          
        // JUMP3  
        case 40:
          break;
          
        // JUMP7 
        case 41:
          break;
          
        // FADE3  
        case 42:
          break;
          
        // FADE7  
        case 43:
          break;
           
          
        default:
        Serial.println("Fehler ist aufgetreten");
        break;
      }
      Serial.println(localBrightness_R);
      Serial.println(localBrightness_G);
      Serial.println(localBrightness_B);
      Serial.print("Speed");
      Serial.println(localSPEED);

  irrecv.resume(); // Receive the next value

  }
  
  // Dynamisch 1
  if(program == 3) {
    if(localBrightness_R > 0) {
      setRED_LOW();
    } else if(localBrightness_G > 0 ){
      setRED_LOW();
    } else if(localBrightness_B > 0) {
      setRED_LOW();
    }
  }  // Flash oder Blink effekte
  if(program == 2) {
    if(localBrightness_R <= 0) {
      localBrightness_R += localTimer_R;
    } else {
      localBrightness_R -= localTimer_R;
    }
  
    if(localBrightness_G <= 0) {
      localBrightness_G += localTimer_G;
    } else {
      localBrightness_G -= localTimer_G;
    }
  
    if(localBrightness_B <= 0) {
      localBrightness_B += localTimer_B;
    } else {
      localBrightness_B -= localTimer_B;
    }
  }
  // Auto Programm
  if(program == 11) {
   
     if (localTimer_R == 0)
      {(localBrightness_R = localBrightness_R + localDirection_R); (localTimer_R = RED_IDLES);}
     if (localBrightness_R == 0 or localBrightness_R == 255) {localDirection_R = localDirection_R * -1;}

    if (localTimer_G == 0) 
    {(localBrightness_G = localBrightness_G + localDirection_G); (localTimer_G = GREEN_IDLES);}  
    if (localBrightness_G == 0 or localBrightness_G == 255) {localDirection_G = localDirection_G * -1;} 

    if (localTimer_B == 0) 
    {(localBrightness_B = localBrightness_B + localDirection_B); (localTimer_B = BLUE_IDLES);}
    if (localBrightness_B == 0 or localBrightness_B == 255) {localDirection_B = localDirection_B * -1;}

     localTimer_R = localTimer_R - 1;
    localTimer_G = localTimer_G - 1;
    localTimer_B = localTimer_B - 1;
  }


  
  // Absicherung das die Werte zwischen 0 und 255 bleiben
  localBrightness_R = constrain(localBrightness_R, 0, 255);
  localBrightness_G = constrain(localBrightness_G, 0, 255);
  localBrightness_B = constrain(localBrightness_B, 0, 255);

  if(RED_STATE == HIGH || GREEN_STATE == HIGH || BLUE_STATE == HIGH) {
    analogWrite(RED_PIN, localBrightness_R);
    analogWrite(GREEN_PIN, localBrightness_G);
    analogWrite(BLUE_PIN, localBrightness_B);
  } else {
    digitalWrite(RED_PIN, RED_STATE);
    digitalWrite(GREEN_PIN, GREEN_STATE);
    digitalWrite(BLUE_PIN, BLUE_STATE);
  }

  delay(localSPEED);
}




