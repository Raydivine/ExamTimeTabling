#include "RatioChecking.h"
#include <stdio.h>

int isTheRatioWithin20Percent(int currentNum, int targetNum){
  if(targetNum == 0)
    return 0;
  
  int ratio = (currentNum - targetNum)*100 / targetNum;
  
  if(ratio<20 && ratio>-20)
    return 1;
  return 0;
}