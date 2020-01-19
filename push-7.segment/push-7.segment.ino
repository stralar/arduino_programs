void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);//D1
  pinMode(3, OUTPUT);//A
  pinMode(4, OUTPUT);//B
  pinMode(5, OUTPUT);//C
  pinMode(6, OUTPUT);//D
  pinMode(7, OUTPUT);//E
  pinMode(8, OUTPUT);//F
  //pinMode(9, OUTPUT);//G
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  static int count = 13;
  if(count == 9){count = 13;}

 int push1 = digitalRead(9);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  //digitalWrite(8, HIGH);

  while(push1 == 1)
  {
    digitalWrite(count, HIGH);
    delay(500);

    count -= 1;
    push1 = digitalRead(9);
  }





  delay(1);
}
