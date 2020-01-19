#include "Arduino.h"
#include "LED.h"

// Set the program mode
void LED::setMode(int _mode) {
  actualMode = _mode;
}

// Set the first timer that is for the delay
void LED::setTimer1(int _time) {
  time_Delay1 = _time;
}

// Set the second timer that is not implement
void LED::setTimer2(int _time){
  time_Delay2 = _time;
}

// Execute the Program in dependence from mode
void LED::doIt() {
  switch(actualMode)
  {
    case 0:
      doNothing();
      break;
    case 1:
      doRandom();
      break;
    case 2:
      doBlink();
      break;
    default:
      doNothing();
  }
  delay(time_Delay1);
}

// Set true if a multiplexer is in use
// actuall not used because so solution
void LED::setMultiPlexer(boolean _state) {
  
}

// give true back if a multiPlexer exist
boolean LED::existMultiPlexer() {
  return multiPlexer;
}

// PRIVATE
// execute the normal ledArray states
void LED::doNothing()
{
  for(int i = 0; i < nLED; i++)
  {
    digitalWrite(ledArray[i], ledON_OFF[i]);
  }
}

// PRIVATE
// execute the a Random ON/OFF settings
void LED::doRandom() {
  int rnd = random(0, nLED);
  if(ledON_OFF[rnd]) {
    digitalWrite(ledArray[rnd], !digitalRead(ledArray[rnd]));
  }
}

// PRIVATE
// execute inverse state of the LEDs ON = OFF | OFF = ON
void LED::doBlink() {
  
}


