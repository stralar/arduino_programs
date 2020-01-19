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
byte Taster = 5;
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
char* Menu[][2] = {
      {"Config 1", 0},
      {"Config 2", 1},
      {"Unterconfig 2", 0},
      {"Config 3", 0}};

// Wird noch automatisiert
byte MenuSize = 4;

//String LEDMenu[] = {"All Laser   ", "Singel Laser"};

int Timing = 0;
boolean SelectStatus = false;

// Neu Variablen von neuer Idee
byte parent = -1;           // Speichert den Index des Obermenues
byte current = 0;           // Speichert den Index des aktuellen menues



// Ab hier wird ein neuer Programmblock mit dem Namen "Tasterstatus" erstellt. 
// Hier wird ausschließlich ausschließlich geprüft, welcher Taster gedrückt ist.
byte Tasterstatus()
{
  Analogwert = analogRead(A0); // Auslesen der Taster am Analogen Pin A0.
  if (Analogwert > 1000) return KeinTaster;
  if (Analogwert < 50) return Tasterrechts;
  if (Analogwert < 195) return Tasteroben;
  if (Analogwert < 380) return Tasterunten;
  if (Analogwert < 555) return Tasterlinks;
  if (Analogwert < 790) return Tasterselect;
   
  return KeinTaster; // Ausgabe wenn kein Taster gedrückt wurde.
}

// Tasten werden durch interrupt ausgelesen

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0,0);
  if (parent < 0) {
    lcd.print("Strothman-Laser");
  } else {
    lcd.print((String)Menu[parent][0]);
  }
  lcd.setCursor(0,1);
  lcd.print((String)Menu[current][0]);
}

void setup()
{
  lcd.begin(16, 2); // Starten der Programmbibliothek.
  lcd.clear();
  lcd.setCursor(0,0); // Angabe des Cursorstartpunktes oben links.
  lcd.print("Strothman-Laser"); // Ausgabe des Textes "Nachricht".
  lcd.setCursor(0,1);
  lcd.print((String)Menu[current][0]);


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
  if (Taster != KeinTaster) {
    switch(Taster)
    {
      // Taster nach rechts
      case 0:
        if (Menu[current][1] > 0) {
          parent = current;
          current++;
        }
        updateLCD();
        break;
      // Taster nach oben
      case 1:
       /* if(Menu[current][1] == 0) {
          if (parent > -1) {
            if (Menu[parent][1] - current < Menu[parent][1]) {
              current--;
            } else {
                if (current > 0) {
                  current--;
                }
            }
          }
        } else {
          if ( current - Menu[current][1] - 1 > 0) {
            current = current + Menu[current][1] - 1;
          }
        }*/
        break;
      // Taster nach unten
      case 2: 
       // if(Menu[current][1] == 0) {
          if (parent > -1) {
             current = parent + ((int)Menu[parent][1] -( current - parent + 1 % (int)Menu[parent][1]));
          } else {
             current = (current + (int)Menu[current][1] + 1) % MenuSize;
           }
       // } else {
       //   current = (current + Menu[current][1] + 1) % MenuSize;
       // }
       updateLCD();
        break;
      // Taster nach links
      case 3:
        if (parent > -1) {
          current = parent;
          parent = -1;
        }
        updateLCD();
        break;
      // Taster Select 
      case 4:
        break;
      default:
        break;
        
    }
  }
    //updateLCD();
  Taster = Tasterstatus();
  delay(100);
}

