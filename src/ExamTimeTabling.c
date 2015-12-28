#include "ExamTimeTabling.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "CreatePopulation.h"
#include "Mutation.h"
#include "Crossover.h"
#include "Random.h"
#include <stdio.h>
#include <malloc.h>

const int numberOfSample = 10;
const int try = 10;

void examTimeTabling(Paper *papers[], int sizePapers, int sizeSession){
  int times = 0, bestScore; 
  Table *population[numberOfSample];
  
  initPopulation( population, papers, numberOfSample, sizePapers, sizeSession);

  while( times != try){ 
    bestScore = population[0]->fitnessScore;
  
        
    mutateTable( population[random(numberOfSample)] );
    Paper *p = papers[random(sizePapers)];
    //crossoverHandler( population, p , numberOfSample, sizeSession);
    sortInFitnessScore( population, numberOfSample);
    
    // if( population[0]->fitnessScore < bestScore)
      // times = 0;
     // times++;
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