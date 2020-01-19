#include "Arduino.h"
#include "LED.h"




  // Construkur from LED for Array of LEDs
LED::LED(){
  
}

  
void LED::setLEDArray(byte* _ledArray, int _nLED)
{
    startLED = 0;
    endLED = 0;
    nLED = _nLED; 
    ledArray = _ledArray;

    for(int i = 0; i < nLED; i++) {
      ledON_OFF[i] = true;
    }
    initialisation();
}

  // Set LED on
void LED::setLEDOn(int selectedLED)
{
  if(selectedLED < nLED) {
    (ledON_OFF[selectedLED]) = true;
  }
}
  // Set LED off
void LED::setLEDOff(int selectedLED)
{
  
  if(selectedLED < nLED) {
    (ledON_OFF[selectedLED]) = false;
    
  }
}
  // Check LED status if ON return true | else false
boolean LED::isLEDOn(int selectedLED)
{
  if(selectedLED < nLED) {
    return ledON_OFF[selectedLED];
  }
}
/*
  // Set LED status for Random true
void LED::setLEDRandomOn(int selectedLED)
{
  if(selectedLED < nLED) {
    (ledArray[selectedLED])[2] = true;
  }  
}
  // Set LED status for Random false
void LED::setLEDRandomOff(int selectedLED)
{
  if(selectedLED < nLED) {
    (ledArray[selectedLED])[2] = false;
  }  
}
  // Check LED Random status if Random ON return true | else false
boolean LED::isLEDRandomOn(int selectedLED)
{
  if(selectedLED < nLED) {
    return (ledArray[selectedLED])[2]; 
  } 
}
*/
// Retrun LED Array
byte* LED::getLED() {
  return ledArray;
}

// Return LED ON/OFF Array
boolean* LED::getLEDON_OFF() {
  return ledON_OFF;
}

int* LED::getTimer1() {
  return &time_Delay1;
}

int* LED::getTimer2() {
  return &time_Delay2;
}

  // Initialisation is private
void LED::initialisation()
{
  if(nLED > 0) 
  {   
     for(int i = 0; i < nLED; i++) {
      pinMode(ledArray[i], OUTPUT);
      digitalWrite(ledArray[i], HIGH);
      ledON_OFF[i] = true;
    }
  } 
}


//###########################
// Execution



