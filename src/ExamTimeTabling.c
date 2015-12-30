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
const int try = 30;

void examTimeTabling(Paper *papers[], int sizePapers, int sizeSession, int generation, int populationNum){
  int times = 0, bestScore; 
  Table *population[populationNum];
  
  initPopulation( population, papers, populationNum, sizePapers, sizeSession);

  while( times != generation){ 
    bestScore = population[0]->fitnessScore;
    printf("%d\n",bestScore);
        
    mutateTable( population[random(populationNum)] );
    Paper *p = papers[random(sizePapers)];
    crossoverHandler( population, p , populationNum, sizeSession); 
    sortInFitnessScore( population, populationNum);
    
    if( population[0]->fitnessScore < bestScore)
      times = 0;
    else times++;
  }
  printf("\n\n");
  printfTable(population[0]);
}

void crossoverHandler(Table *population[], Paper *target, int sizePopulation, int sizeSession){
  int a,b;
  
  do{
     a = random(sizePopulation);
     b = random(sizePopulation);
  }while(a == b);

  Table *child = crossoverTwoTable( population[a], population[b], target, sizeSession);

  if( child->fitnessScore < population[sizePopulation-1]->fitnessScore ){
    clearLinkList( &(population[sizePopulation-1]->sessions) );
    population[sizePopulation-1] = child;
  }
  else clearLinkList( &(child->sessions) );
}