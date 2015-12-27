#ifndef CreatePopulation_H
#define CreatePopulation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void initPopulation( Table *population[], int totalPapers, int maxPeopleInSession, int populationNum);
void sortInFitnessScore( Table arr[], int size);

LinkedList *convertArrayToLinkedList(Paper *papersArr[], int size);
void shuffleArray( Paper *papersArr[], int size);


#endif // CreatePopulation_H
