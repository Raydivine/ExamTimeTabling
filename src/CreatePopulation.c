#include "CreatePopulation.h"
#include "ExamStruct.h"
#include "PaperListConvertion.h"
#include "Random.h"
#include "printfStructs.h"
#include <stdio.h>

void initPopulation(Table *population[], Paper *papers[], int sizePopulation, int sizePapers, int sizeSession){
  int i;
  
  for( i = 0; i < sizePopulation; i++){
    shuffleArray( papers, sizePapers);
    LinkedList *pList = convertArrayToLinkedList( papers, sizePapers);
    population[i]= buildTable( pList,  sizeSession);
  }
  
  sortInFitnessScore( population, sizePopulation);
  
}

void sortInFitnessScore( Table *arr[], int size){
  Table *t;
  int i, d;
  
  for (i=1 ; i<= size-1; i++){
    d = i;
 
    while ( d > 0 && arr[d]->fitnessScore < arr[d-1]->fitnessScore){
      t = arr[d];
      arr[d] = arr[d-1];
      arr[d-1] = t;

      d--;
    }
  }
}

void clearPopulation(Table *population[], int sizePopulation){
  int i;
  
  for( i=0 ; i<sizePopulation; i++)
    clearLinkList( &(population[i]->sessions) );
}


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
