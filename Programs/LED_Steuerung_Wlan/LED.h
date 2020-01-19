#ifndef LED_h
#define LED_h

#include "Arduino.h"

class LED{
  public:
  // Construktor for Array of LEDs
    LED(byte* _ledArray, boolean* _ledON_OFF, int _nLED);
  // Set LED on
    void setLEDOn(int selectedLED);
  // Set LED off
    void setLEDOff(int selectedLED);
  // Check LED status if ON return true | else false
    boolean isLEDOn(int selectedLED);
  // Set LED status for Random true
    void setLEDRandomOn(int selectedLED);
  // Set LED status for Random false
    void setLEDRandomOff(int selectedLED);
  // Check LED Random status if Random ON return true | else false
    boolean isLEDRandomOn(int selectedLED);
  // give ledArray back
    byte* getLED();
  // give ledON_OFF Array back
    byte* getLEDON_OFF();

//###########################
// The Execution
  // Set the program mode
    void setMode(int _mode);
  // Set the first timer that is for the delay
    void setTimer1(int _time);
  // Set the second timer that is not implement
    void setTimer2(int _time);
  // Execute the Program in dependence from mode
    void doIt();
  // Set true if a multiplexer is in use
  // actuall not used because so solution
    void setMultiPlexer(boolean _state);
  // give true back if a multiPlexer exist
    boolean existMultiPlexer();

    

  private:
    byte* ledArray;
    boolean* ledON_OFF;
    //byte* ledRandom;
    int startLED;
    int endLED;
    int nLED; 
    
  // Initialisation from the LEDs, set all off
    void initialisation();
  // Search in ledArray after the given int
  // byte* searchLED(int selectedLED);

//###########################
// The Execution

    int time_Delay1 = 50;
    int time_Delay2 = -1;
    int actualMode = 0;
    boolean multiPlexer = false;
    int randomCount = 1; 

  // execute the normal ledArray states
    void doNothing();
  // execute the a Random ON/OFF settings
    void doRandom();
  // execute inverse state of the LEDs ON = OFF | OFF = ON
    void doBlink();
};
#endif

