#include "RatioChecking.h"
#include <stdio.h>

int isRatioWithin20Percent(int currentNum, int targetNum){
  if(targetNum == 0)
    return 0;
  
  int ratio = (currentNum - targetNum)*100 / targetNum;
  
  if(ratio<20 && ratio>-20)
    return 1;
  return 0;
}

int isSumUnderFlow(int *currentNum, int addNum, int targetNum){
  if(targetNum == 0)
    return 0;
    
  int sum = *currentNum + addNum;
  int flowRatio = (sum - targetNum)*100 / targetNum;
  
  if( flowRatio<20 ){
    *currentNum = *currentNum + addNum;
    return 1;
  }
  return 0;
}