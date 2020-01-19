void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);

}



void loop() {
  // put your main code here, to run repeatedly:

  //int sensorValue = analogRead(A0);
  int sensorValue2 = digitalRead(3);
  int variable1 = digitalRead(2);
  int variable2 = digitalRead(2);
  int variable3 = digitalRead(2);
  int variable4 = digitalRead(2);

 
  static bool zahl1 = false;
  static bool zahl2 = false;
  static bool zahl3 = false;
  static bool zahl4 = false;
           // Serial.println(sensorValue);

    if(zahl1 == false) 
    {
      while(variable1 == 1)
      { 
            Serial.println(1);
            zahl1 = true; 
            variable1 = digitalRead(2);         
            //delay(300);
      }
    }else if(zahl2 == false)
    {
      while(variable2 == 1)
      {
          Serial.println(2);
          zahl2 = true;
          variable2 = digitalRead(2);
          //delay(300);

      }
    }else if(zahl3 == false)
    {
      while(variable3 == 1)
      {
         Serial.println(3);
          zahl3 = true;
          variable3 = digitalRead(2);
      }
    }else if(zahl4 == false)
    {
      while(variable4 == 1)
      {
         Serial.println(4);
          zahl4 = true;
          variable4 = digitalRead(2);
      }
    }

 
    if(zahl1 == true && zahl2 == true && zahl3 == true && zahl4 == true)
    {
    digitalWrite(4, HIGH);

    }

    if(sensorValue2 == 1)
    {
      digitalWrite(4, LOW);
      zahl1 = false;
      zahl2 = false;
      zahl3 = false;
      zahl4 = false;
      
    }
 

  
  
  //Serial.println(sensorValue);
  //Serial.println(sensorValue2);

  delay(1);
  

}
