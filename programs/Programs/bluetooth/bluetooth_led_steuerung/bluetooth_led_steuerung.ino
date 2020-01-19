


// Der Index ist der Programm Punkt
// Der Wert 0 ist false(OFF), 1 ist true(ON), 2 ist nicht verfügbar

// List x.0
String  Lx_0[] = {"Congiguration 1", "Configuration 2", "Customize"};

// List 1.x

// List 2.x


// List 3.x
String L3_x[] = {"LED", "Timing"};


// List 3.1.x
String L3_1_x[] = {"AllLED", "wichLED"};

// List 3.2.x


// Liste der Menü Namen
String menuNams[] = {"Hauptmenü", "Congiguration 1", "Configuration 2", "Customize", "LED", "AllLED", "whichLED", "Timing"};

// Liste der Mengen an vorhandenen unter Punkten
int sumUnderMenu[] = {3, 0, 0, 2, 2, 0, 0, 0};

int actualyMenuIndex = 0;
int overMenuIndex = 0;
String overMenuName = "Hauptmenü";


// Derzeitiger Filler
// WIrd Später ersetzt durch eine Bluetooth Eingabe oder einer Analogne Eingabe
boolean SelectStatus = false;



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  if(SelectStatus
    switch(actualyMenuIndex)
      case 0:
      // Prüfung ob man am Letzten Menü Punkt angelangt ist
      if(overMenuIndex + sumUnderMenu[overMenuIndex] <= actualyMenuIndex) {
        
      }
  
      case 1:
      case 2:
      case 3:
  
      default:
        break;

}
