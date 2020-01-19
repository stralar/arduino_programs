int soundSensorPin = 2;
int soundSensorVal = HIGH;
boolean bAlarm = false;


unsigned long lastSoundSensorTime;
unsigned long countTime;

 int soundAlarmMin = 13;    //Minimum des Counters
 int soundAlarmMax = 17;    //Maximum des Counters

void setup() {
  // put your setup code here, to run once:

   Serial.begin(9600);
    pinMode(soundSensorPin, INPUT); 
    pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
          digitalWrite(13, HIGH);


  soundSensorVal = digitalRead(soundSensorPin);

    if(soundSensorVal == LOW) {
      lastSoundSensorTime = millis();
      delay(250);
      Serial.println("Sound");
      //digitalWrite(ledPin, LOW); 
      }

      delay(100);

}
