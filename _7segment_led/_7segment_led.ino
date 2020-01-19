void setup() {
  pinMode(2, OUTPUT);//D1
  pinMode(3, OUTPUT);//A
  pinMode(4, OUTPUT);//B
  pinMode(5, OUTPUT);//C
  pinMode(6, OUTPUT);//D
  pinMode(7, OUTPUT);//E
  pinMode(8, OUTPUT);//F
  pinMode(9, OUTPUT);//G
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  static int count = 1;
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  //digitalWrite(8, HIGH);

  if(count == 1)
 {
  digitalWrite(10, LOW);
  digitalWrite(13, HIGH);
  count += 1;
  delay(100);
 }
 if(count == 2)
 {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  count += 1;
  delay(100);
 }
 if(count == 3 )
 {
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  count += 1;
  delay(100);
 }
if(count == 4)
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  count -= 3;
  delay(100);
}

delay(1);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);

  

}
