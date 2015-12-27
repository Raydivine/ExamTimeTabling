#ifndef CreatePopulation_H
#define CreatePopulation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void initPopulation(Table *population[], Paper *papers[], int sizePopulation, int sizePapers, int sizeSession);
void sortInFitnessScore(Table *arr[], int size);
void clearPopulation(Table *population[], int sizePopulation);
void shuffleArray( Paper *papersArr[], int size);
LinkedList *convertArrayToLinkedList(Paper *papersArr[], int size);

#endif // CreatePopulation_H
