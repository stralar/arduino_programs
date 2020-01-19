
int button1 = 2;

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int led8 = 10;
int led9 = 11;
int led10 = 12;
int led11 = 13;

int led_min= 3;
int led_max = 11;

int button1status = 1;


int time_ON_sec = 500;                   //1000 = 1 Sekunde
int time_OFF_sec = 100;
int time_random = 30;




void setup() {
  // put your setup code here, to run once:
    pinMode(button1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);

    while(!Serial);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(button1, HIGH);


  if(digitalRead(button1) == LOW) {
    while(digitalRead(button1) == LOW) {}    
    
    button1status += 1;
    Serial.println(button1status); 
    delay(500);
  }  

    switch(button1status){
    case 1:         
          laser_control(HIGH);
     break;   
          
    case 2:
          laser_party();
     break;
     
    case 3:
          laser_random();
     break;
     
    case 4:          
        laser_control(LOW);
     break;
     
    default:
     break;   
        
  }
  if(button1status == 4){
    button1status = 0;
  }

}
void led_ON(int led_pin){
    digitalWrite(led_pin, HIGH);
}

void led_OFF(int led_pin){
    digitalWrite(led_pin, LOW);  
}

void laser_control(int led_state){
    if(led_state == HIGH){
   
      for(int i = led_min; i <= led_max; i++ ){
       led_ON(i);
      }
    }else{
      for(int i = led_min; i <= led_max; i++ ){
       led_OFF(i);
      }
    }
}


void laser_party(){
    laser_control(HIGH);
    delay(time_ON_sec);
    laser_control(LOW);
    delay(time_OFF_sec);

}

void laser_random(){
    int laser_random_nbr = random(led_min, led_max);
    Serial.println(laser_random_nbr);
    digitalWrite(laser_random_nbr, HIGH);
    delay(time_random);
    digitalWrite(laser_random_nbr, LOW);
    delay(time_random);
}

