#include "ExamTimeTabling.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "CreatePopulation.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Random.h"

const int numberOfSample = 10;
const int try = 30;


void examTimeTabling(Paper *papers[], int sizePapers, int sizeSession){
  int times = 0;
  Table *population[numberOfSample];
  
  initPopulation( population, papers, numberOfSample, sizePapers, sizeSession);
  //printfPopulation(population, numberOfSample);
  
  while( times != try){
    mutateTable( population[random(numberOfSample)] );
    
    
    times++;
  }
}




void crossoverHandler(Table *population[], Paper *target, int numberOfSample, int sizeSession){
  int A = random(numberOfSample), B;
  
  while(B == A)
    B = random(numberOfSample);
  
  Table *tabA = population[A];
  Table *tabB = population[B];
  
  //Table *child = crossoverTwoTable( tabA, tabB, target, sizeSession);
}