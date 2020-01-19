/*
 * 
 * @version 0.1
 * @author Lars Stratmann
 * 
 * Program:
 * 0 Normal
 * 1 ON/OFF
 * 2 Flash
 * 3 Dynamisch 1
 * 
 * 
 */
#include "arduino.h"
#include "RGB_function.h"

RGB_function::RGB_function(int IRCode1, int Program1, int Brightness_R1, int Brightness_G1, int Brightness_B1, float RED_IDLES1, float GREEN_IDLES1, float BLUE_IDLES1,
                int Direction_R1, int Direction_G1, int Direction_B1, int Timer_R1, int Timer_G1, int Timer_B1)
  {
     //   # of loop cycles to wait before changing the brightness level
    RED_IDLES = RED_IDLES1;
    GREEN_IDLES = GREEN_IDLES1;
    BLUE_IDLES = BLUE_IDLES1;
  
    //   brightness level of each color (0..255)
    Brightness_R = Brightness_R1;
    Brightness_G = Brightness_G1;
    Brightness_B = Brightness_B1;
  
    //   direction of change in brightness level (-1 or +1)
    Direction_R = Direction_R1;
    Direction_G = Direction_G1;
    Direction_B = Direction_B1;
  
    //   counter of loop cycles left to wait before changing the pin value
    Timer_R = Timer_R1;
    Timer_G = Timer_G1;
    Timer_B = Timer_B1;

    IRCode = IRCode1;
    Program = Program1;
  }

RGB_function::RGB_function(int IRCode1, int Program1, int Brightness_R1, int Brightness_G1, int Brightness_B1)

{
    Brightness_R = Brightness_R1;
    Brightness_G = Brightness_G1;
    Brightness_B = Brightness_B1;
    
    IRCode = IRCode1;
    Program = Program1;
}


RGB_function::RGB_function(int IRCode1, int Program1)
  {
     IRCode = IRCode1;
     Program = Program1;
  }

RGB_function::getIRCode()
  {
    return IRCode;
  }

RGB_function::getProgram()
  {
    return Program;
  }

RGB_function::getBrightness_R()
  {
    return Brightness_R;
  }

RGB_function::getBrightness_G()
  {
    return Brightness_G;
  }

RGB_function::getBrightness_B()
  {
    return Brightness_B;
  }

RGB_function::getRED_IDLES()
  {
    return RED_IDLES;
  }
RGB_function::getGREEN_IDLES()
  {
    return GREEN_IDLES;
  }

RGB_function::getBLUE_IDLES()
  {
    return BLUE_IDLES;
  }

RGB_function::getDirection_R()
  {
    return Direction_R;
  }
  
RGB_function::getDirection_G()
  {
    return Direction_G;
  }
RGB_function::getDirection_B()
  {
    return Direction_B;
  }
  
RGB_function::getTimer_R()
  {
    return Timer_R;
  }
  
RGB_function::getTimer_G()
  {
    return Timer_G;
  }
  
RGB_function::getTimer_B()
  {
    return Timer_B;
  }

  



