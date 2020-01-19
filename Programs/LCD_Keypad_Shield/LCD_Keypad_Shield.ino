#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //Angabe der erforderlichen Pins


#define LASER_MIN 22
#define ALL_LASER (36 - 22 + 1)


/*
 * 10 Kabel
 * 6 kabel von digital 4 - 9
 * 1 GND      SCHWARZ
 * 1 5V       ROT
 * 1 A0       GELB
 * 1 AREF     WEIß
 * 
 * 
 * Laser durchmesser 6mm
 * 
 * 
 * Digital Pin 22 - 53
 */

 //         Laser[][0] = pin
 //         Laser[][1] = Status (1 = ON | 0 = OFF)
int Laser[ALL_LASER][2] = {{}};
 
// erstellen einiger Variablen
int Taster = 0;
int Analogwert = 0;
#define Tasterrechts 0
#define Tasteroben 1
#define Tasterunten 2
#define Tasterlinks 3
#define Tasterselect 4
#define KeinTaster 5

#define ProgramMax 3


// Der Index ist der Programm Punkt
// Der Wert 0 ist false(OFF), 1 ist true(ON), 2 ist nicht verfügbar
int Programs[] = {0, 0, 2};
int Program = 0;

// Der Index ist der Menu Punkt
// 
String CustomMenu[] = {"LED   ", "Timing"};

String LEDMenu[] = {"All Laser   ", "Singel Laser"};

int Timing = 0;

boolean SelectStatus = false;


 
// Ab hier wird ein neuer Programmblock mit dem Namen "Tasterstatus" erstellt. Hier wird ausschließlich ausschließlich geprüft, welcher Taster gedrückt ist.
/*int Tasterstatus()
{
Analogwert = analogRead(A0); // Auslesen der Taster am Analogen Pin A0.
if (Analogwert > 1000) return KeinTaster;
if (Analogwert < 50) return Tasterrechts;
if (Analogwert < 195) return Tasteroben;
if (Analogwert < 380) return Tasterunten;
if (Analogwert < 555) return Tasterlinks;
if (Analogwert < 790) return Tasterselect;
 
return KeinTaster; // Ausgabe wenn kein Taster gedrückt wurde.
}*/


// Tasten werden durch interrupt ausgelesen


void setup()
{
  lcd.begin(16, 2); // Starten der Programmbibliothek.
  lcd.setCursor(0,0); // Angabe des Cursorstartpunktes oben links.
  lcd.print("Strothman-Laser"); // Ausgabe des Textes "Nachricht".


  for(int i = 0; i < ALL_LASER; i++) {
    int pin = LASER_MIN + i;
    Laser[i][0] = pin;
    Laser[i][1] = 0;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

 
void loop()
{
    //ALLlaserOFF();
  //  delay(5);

    
   if(Programs[0] == 1){
     
     ALLlaserON();
   }
   if(Programs[1] == 1){

    randomALLlaser();
   }   


  //lcd.print(millis()/1000); // Zeigt die Sekunden seit Start des Programms in Sekunden an.
  if(SelectStatus) {        // Falls ein Unterpunkt genommen wurde
   lcd.setCursor(0,0);
    switch(Program) 
    {
      case 0:
      {
        changeStatus();
        break;
      }
      case 1:
      {
        changeStatus();
        break;
      }
      
      case 2:
      {
        customMenu();
        break;
      }
      default:
      {
        break;
      }
    }
  } else {        // HauptMenu

    printMainMenuLayout();

    switch(Program) 
    {
      case 0:
      {
        printMenuName();
        break;
      }
      case 1:
      {
        printMenuName();
        break;
      }
      
      case 2:
      {
        printMenuName("Custom");
        break;
      }
      default:
      {
        break;
      }
    }
  }
  Tasterstatus();

  delay(100);
} //Loop beenden

void Tasterstatus()
{
  while(analogRead(A0) < 1000) {
        Analogwert = analogRead(A0); // Auslesen der Taster am Analogen Pin A0.

        if (Analogwert < 50) {    
          
           Taster = Tasterrechts;
           while(analogRead(A0) < 50)  { }
           break;
        } 
        if (Analogwert < 195) {  
          
           Taster = Tasteroben;
      
           if(Program != 0 && !SelectStatus) {
              Program -= 1;
          }
          while(analogRead(A0) > 50 && analogRead(A0) < 195)  {  }
          break;
        } 
        if (Analogwert < 380) {   
          
            Taster = Tasterunten;
             if(Program != ProgramMax && !SelectStatus) {
                Program += 1;
            }
            while( analogRead(A0) > 195 && analogRead(A0) < 380) {   }
            break;
        } 
        if (Analogwert < 555) {
      
            Taster = Tasterlinks;
                
            SelectStatus = false;
            lcd.setCursor(0,0); // Angabe des Cursorstartpunktes oben links.
            lcd.print("Strothman-Laser"); 
            
            while( analogRead(A0) > 380 && analogRead(A0) < 550) {}
      
            break;
        } 
        if (Analogwert < 790) {  
          
      
          Taster = Tasterselect;  
          SelectStatus = true;
           
          while( analogRead(A0) > 555 && analogRead(A0) < 790) { }
          break;
        } 
          //Taster = KeinTaster; // Ausgabe wenn kein Taster gedrückt wurde.
  }
  delay(Timing);
  
}
// Hier wird der Programmblock "Tasterstatus" abeschlossen.



void printMainMenuLayout(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Strothman-Laser");
    //lcd.setCursor(12,1); // Bewegt den Cursor in Zeile 2 (Line0=Zeile1 und Line1=Zeile2) and die Stelle "12".
    //lcd.print("S");
    //lcd.setCursor(14,1);
   // lcd.print(Program);
    lcd.setCursor(0,1);  
}

void printStatus() {
  
  lcd.setCursor(12,1);
  
  if(Programs[Program] == 0) {
    lcd.print("OFF");
  } 
  if(Programs[Program] == 1) {
    lcd.print("ON");
  }
}

void changeStatus() {
 // lcd.clear();
  if(Programs[Program] == 0) {
    for(int i = 0; i < sizeof(Programs); i++) {
      if(Programs[i] == 1) {
        Programs[i] = 0;
      }
    }
    Programs[Program] = 1;
    
  } else {
    Programs[Program] = 0;
    ALLlaserOFF();
  }
  SelectStatus = false;
}

void customMenu() {
  Taster = KeinTaster;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menu: Custom");
  lcd.setCursor(0,1);
  
  int count = 0;
  lcd.print(CustomMenu[count]);
  
  while(Taster != Tasterlinks) {
    Tasterstatus();
  
    if(Taster == Tasteroben) {
      lcd.setCursor(0,1);
      lcd.print(CustomMenu[count]);

      if(count > 0) {
        count--;
      }
      Taster = KeinTaster;
    }

    if(Taster == Tasterunten) {
      lcd.setCursor(0,1);
      lcd.print(CustomMenu[count]);

      if(count < sizeof(CustomMenu)/sizeof(String) -1) {
         count++;
      } 
      Taster = KeinTaster;
    }
    
    if(Taster == Tasterselect) {
        if(CustomMenu[count] == "LED   ") {
          ledMenu();
        }
        if(CustomMenu[count] == "Timing") {
          setTiming();
        }
    }
  }
}

void ledMenu() {
  Taster = KeinTaster;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menu: LED");
  lcd.setCursor(0,1);
 
  
  int count = 0;
  lcd.print(LEDMenu[count]);
   
  while(Taster != Tasterlinks) {
    Tasterstatus();
  
    if(Taster == Tasteroben) {
      lcd.setCursor(0,1);
      lcd.print(LEDMenu[count]);
      
      if(count > 0) {
        count--;
      }
      Taster = KeinTaster;
    }

    if(Taster == Tasterunten) {
      lcd.setCursor(0,1);
      lcd.print(LEDMenu[count]);
      
      if(count < sizeof(LEDMenu)/sizeof(String) - 1) {
         count++;
      } 
      Taster = KeinTaster;      
    }
    
    if(Taster == Tasterselect) {
      if(LEDMenu[count].equals("All Laser   ")) {
        
      }
      if(LEDMenu[count].equals("Singel Laser")) {
        singelLaser();
      }
    }   
  }
}


void setTiming() {
  Taster = KeinTaster;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menu: Speed");
  lcd.setCursor(0,1);
  
  //int count = 0;
  //lcd.print(CustomMenu[count]);
  
  while(Taster != Tasterlinks) {
    Tasterstatus();
  
    if(Taster == Tasterunten) {
      lcd.setCursor(0,1);
      lcd.print("Speed: ");
      lcd.print(((double)Timing / 1000));
      lcd.print(" sec");

      if(Timing > 0) {
        Timing = Timing - 10;
      }
      Taster = KeinTaster;
    }

    if(Taster == Tasteroben) {
      lcd.setCursor(0,1);
      lcd.print("Speed: ");
      lcd.print(((double)Timing / 1000));
      lcd.print(" sec");

      if(Timing < 1000) {
         Timing = Timing + 10;
      } 
      Taster = KeinTaster;
    }
    
    /*if(Taster == Tasterselect) {
        if(CustomMenu[count] == "LED   ") {
          ledMenu();
        }
        if(CustomMenu[count] == "Timing") {
          setTiming();
        }
    }*/
  }
}
void printMenuName() {
      lcd.print("Menu-");
      lcd.print(Program);
      printStatus();

}

void printMenuName(String MenuName) {
      lcd.print(MenuName);
      lcd.print(Program); 
      printStatus();
}

void randomALLlaser() {
  ALLlaserOFF();
  
  int randomPin = random(ALL_LASER);
  
  Laser[randomPin][1] == 1;
  
  digitalWrite(Laser[randomPin][0], 1);

  randomPin = random(ALL_LASER);
  
  Laser[randomPin][1] == 1;
  
  digitalWrite(Laser[randomPin][0], 1);
  
  //delay(200);
}

void ALLlaserOFF() {
  for(int i = 0; i < ALL_LASER; i++) {
     Laser[i][1] == 0;
     digitalWrite(Laser[i][0] , 0);
  }
}

void ALLlaserON() {
  for(int i = 0; i < ALL_LASER; i++) {
     Laser[i][1] == 1;
     digitalWrite( Laser[i][0] , 1);
  }
}

void singelLaser() {
  Taster = KeinTaster;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Laser     Status");
  lcd.setCursor(0, 1);
  lcd.print("Laser ");

  int count = 0;

  while(Taster != Tasterlinks) {
    Tasterstatus();
  
    if(Taster == Tasteroben) {
      
      lcd.setCursor(6, 1);
      lcd.print("  ");
      lcd.setCursor(6, 1);
      lcd.print(Laser[count][0]);
      
      if(Laser[count][1] == 1) {
        lcd.setCursor(12, 1);
        lcd.print("ON ");
      } else {
        lcd.setCursor(12, 1);
        lcd.print("OFF");
      }
      
      if(count > 0) {
        count--;
      }
      Taster = KeinTaster;
    }

    if(Taster == Tasterunten) {
      
      lcd.setCursor(6, 1);
      lcd.print("  ");
      lcd.setCursor(6, 1);
      lcd.print(Laser[count][0]);
      
      if(Laser[count][1] == 1) {
        lcd.setCursor(12, 1);
        lcd.print("ON ");
      } else {
        lcd.setCursor(12, 1);
        lcd.print("OFF");
      }
      
      if(count < (sizeof(Laser)/sizeof(int))/2 -1) {
         count++;
      } 
      Taster = KeinTaster;
    }
    
    if(Taster == Tasterselect) {
    
      if(Laser[count][1] == 0) {
        Laser[count][1] = 1;
        lcd.setCursor(12, 1);
        lcd.print("   ");
        lcd.setCursor(12, 1);
        lcd.print("ON ");
      } else {
        Laser[count][1] = 0;
        lcd.setCursor(12, 1);
        lcd.print("   ");
        lcd.setCursor(12, 1);
        lcd.print("OFF");
        
      }
      digitalWrite(Laser[count][0], Laser[count][1]);
      Taster = KeinTaster;
    }
    
  }
}

