#include <LedControl.h>
  LedControl lc = LedControl(2,4,3,1);


 /* int muster3[][] = {0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,0,
                    0,1,0,0,0,0,0,0,
                    0,0,1,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0};
                    */

void setup() {
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)


  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int muster[] = {7,6,5,4,3,2,1,0};
  int muster2[] = {0,1,2,3,4,5,6,7};
  int muster3[8][8] = {0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    1,0,0,0,0,1,0,0,
                    0,1,0,0,1,0,1,0,
                    0,0,1,1,0,0,0,1,
                    0,0,1,0,0,0,0,1,
                    1,1,0,1,1,0,1,0,
                    1,1,0,0,1,1,0,0};
  int row = 7;

  for(int i=0;i <= row; i += 1)
  {
    lc.setLed(0,i,muster[i],true);
     
    lc.setLed(0,muster2[i],i,true);
      
   delay(60);

    lc.setLed(0,muster2[i],i,false);

    lc.setLed(0,i,muster[i],false);
  }

/*
  for(int row=0; row <= 7; row+=1){
    for(int col=0; col <= 7; col+=1){
      if(muster3[col][row] == 1){
         lc.setLed(0,col,row,true);
      }
      delay(60);
       lc.setLed(0,col,row,false);

    }
  }
*/
  
  delay(1);

}
