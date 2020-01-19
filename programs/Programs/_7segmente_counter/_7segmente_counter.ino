int aPin = A2;  //                     A
int bPin = A5 ;  //             ________
int cPin = 5;  //           |                   |
int dPin = 7;  //       F  |                   |  B
int ePin = 8;  //           |         G       |
int fPin = A3;  //            |________|
int gPin = 4;  //           |                   |
int dotdeci = 6;
int GND1 = 12;  //           |                   |
int GND2 = 11; //         E |                   |   C
int GND3 = 9; //            |________|
int GND4 = 2; //    A7   
int num = 0;       //         D
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
double dig4 = 0;
int DTime = 4;

void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  pinMode(dotdeci, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
 digitalWrite( GND1, HIGH);
 digitalWrite( GND2, HIGH);
 digitalWrite( GND3, HIGH);
 digitalWrite( GND4, HIGH);
  digitalWrite( dotdeci, LOW);
Serial.println("test");


if(dig4 < 10) {
   dig4 = dig4 + (0.016 / 60);
  }else{
    dig4 =0 ;
  if(dig3 < 5) {
    dig3 = dig3 + 1;
  }else{
    dig3 = 0;
    if(dig2 <= 9) {
      dig2 = dig2 + 1;
    }else{
      dig2 = 0;
      if(dig1 <= 2){
        dig1 = dig1 +1;
      }
      else{
        dig1 = 0;
      }
    }
  }
}

 

  digitalWrite( GND4, LOW);    //digit 4
  pickNumber(dig4);
 delay(DTime);
  digitalWrite( GND4, HIGH);
 
  digitalWrite( GND3, LOW);    //digit 3
  pickNumber(dig3);
  delay(DTime);
  digitalWrite( GND3, HIGH);
 
  digitalWrite( GND2, LOW);   //digit 2
  pickNumber(dig2);
    digitalWrite( dotdeci, HIGH);
 delay(DTime);
  digitalWrite( GND2, HIGH);
 
  digitalWrite( GND1, LOW);   //digit 1
    digitalWrite( dotdeci, LOW);

  pickNumber(dig1);
  delay(DTime);
  digitalWrite( GND1, HIGH);


}

void pickNumber(int x){
   switch(x){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }

}

void clearLEDs()
{  
  digitalWrite(  2, LOW); // A
  digitalWrite(  3, LOW); // B
  digitalWrite(  4, LOW); // C
  digitalWrite(  5, LOW); // D
  digitalWrite(  6, LOW); // E
  digitalWrite(  7, LOW); // F
  digitalWrite(  8, LOW); // G
}

void one()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void two()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void three()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void four()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void five()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void six()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void seven()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void eight()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void nine()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void zero()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, LOW);

}


