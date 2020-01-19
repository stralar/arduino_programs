/*
 * LED Klingel
 * 
 * Lars Stratmann
 * Version 1.1
 * liest ein ~2V Signal ein und lässt für einen bestimmten 
 * Zeitraum eine LED aufläuchten
 * 
 * 
 */

int ledOUT = 12;
int led2 = 11;
int led3 = 10;


int count = 30;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  
  pinMode(ledOUT, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(2, INPUT);
  //pinMode(A0, INPUT);
  //attachInterrupt(digitalPinToInterrupt(2), checkBlink, RISING);

  blinkFkt();
}

void loop() {  

  while(digitalRead(2) == HIGH) {
    blinkFkt();
  }
  //delay(1);
}

void blinkFkt() {
   
    delay(20);
    
    digitalWrite(ledOUT, HIGH);
    
    for(int i = 0; i < count; i++) {
      digitalWrite(led2, !digitalRead(led2));
      digitalWrite(led3, !digitalRead(led3));
      //Serial.println("Blink");
      delay(200);
    }
    //Serial.println("Blink end");
    
    digitalWrite(ledOUT,LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(10);
}
