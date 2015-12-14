#include "CreatePopulation.h"
#include "ExamStruct.h"
#include "PaperListConvertion.h"
#include "Random.h"
#include "printfStructs.h"
#include <stdio.h>

LinkedList *convertArrayToLinkedList(Paper *papersArr[], int size){
  int i;
  LinkedList *paperList = NULL;
  
  for( i = 0 ; i < size ; i++)
    addDataToHead( &paperList, papersArr[i]);
  
  return paperList;
}

void shuffleArray( Paper *papersArr[], int size){ 
  int i,x; 
  Paper *temp; 
  for( i=0 ; i < size ; i++){    
    x = random(size); 
    temp = papersArr[x]; 
    papersArr[x] = papersArr[i]; 
    papersArr[i] = temp; 
  } 
} 
