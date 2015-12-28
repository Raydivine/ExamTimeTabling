#include "ExamTimeTabling.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "CreatePopulation.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Random.h"
#include <stdio.h>

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




void crossoverHandler(Table *population[], Paper *target, int sizePopulation, int sizeSession){
  int a,b;
  
  do{
     a = random(sizePopulation);
     b = random(sizePopulation);
  }while(a == b);

  Table *child = crossoverTwoTable( population[a], population[b], target, sizeSession);
  
  if( child->fitnessScore < population[sizePopulation]->fitnessScore )
    population[sizePopulation] = child;
}