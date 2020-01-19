#ifndef RGB_FUNCTION_h
#define RGB_FUNCTION_h

#include "arduino.h"

class RGB_function 
{
  public:
  RGB_function(int IRCode1, int Program1, int Brightness_R1, int Brightness_G1, int Brightness_B1, float RED_IDLES1, float GREEN_IDLES1, float BLUE_IDLES1,
                int Direction_R1, int Direction_G1, int Direction_B1, int Timer_R1, int Timer_G1, int Timer_B1);

  RGB_function(int IRCode1, int Program1, int Brightness_R1, int Brightness_G1, int Brightness_B1);
  
  RGB_function(int IRCode1, int Program1);   

  getBrightness_R();
  getBrightness_G();
  getBrightness_B();

  getRED_IDLES();
  getGREEN_IDLES();
  getBLUE_IDLES();

  getDirection_R();
  getDirection_G();
  getDirection_B();

  getTimer_R();
  getTimer_G();
  getTimer_B();

  getIRCode();

  getProgram();


  private:

  // Infrared Code für die jeweilige Funktion
  int IRCode;

  // Verschiedene Programme 0 = standard nur leuchten
  int Program;

  
  //   # of loop cycles to wait before changing the brightness level
  float RED_IDLES = 2;
  float GREEN_IDLES = 4;
  float BLUE_IDLES = 6;

  //   brightness level of each color (0..255)
  int Brightness_R;
  int Brightness_G;
  int Brightness_B;

  //   direction of change in brightness level (-1 or +1)
  int Direction_R = 0;
  int Direction_G = 0;
  int Direction_B = 0;

  //   counter of loop cycles left to wait before changing the pin value
  int Timer_R = 0;
  int Timer_G = 0;
  int Timer_B = 0;

  
};

#endif //rgb.h
