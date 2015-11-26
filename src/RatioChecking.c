#include "RatioChecking.h"

int isTheRatioWithin20Percent(int currentNum, int targetNum){
  int ratio = 0;
  
  if(currentNum ==0 || targetNum == 0)
    return 0;
  
  ratio = (currentNum-targetNum)/targetNum * 100;
  
  if( ratio <20 || ratio >-20) 
    return 1;
  return 0;

  
}