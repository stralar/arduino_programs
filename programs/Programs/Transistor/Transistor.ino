void setup() {
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
    





  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(13, HIGH);

  delay(50);
  digitalWrite(13, LOW);
  delay(50);
  digitalWrite(3, HIGH);
  delay(50);
  digitalWrite(3, LOW);*/

  /*int zahl = random(4, 13);
  digitalWrite(zahl, HIGH);
  delay(60);
  digitalWrite(zahl, LOW);
*/

  
  for(int i = 2; i <= 13; i++){
    digitalWrite(i, HIGH);
    //digitalWrite(i+1, HIGH);
    //digitalWrite(i+2, HIGH);

    delay(70);
    //digitalWrite(i, LOW);
    //digitalWrite(i+1, LOW);
  // digitalWrite(i+2, LOW);
  }
 

}
