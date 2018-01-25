#include "kernel.h"




//------------------------------{Timing functions}------------------------------


exeption wait(uint nTicks){
  isr_off(void);
  volatile int first = TRUE;
  SaveContext();
  if(first){
    first = false; 
    

}

