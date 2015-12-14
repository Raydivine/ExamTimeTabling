#ifndef CreatePopulation_H
#define CreatePopulation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void setPopulation( Table table[], Paper papers[], int size, int maxPeopleInSession, int populationNum);
void shuffleArray( Paper *papersArr[], int size);
LinkedList *convertArrayToLinkedList(Paper *papersArr[], int size);


#endif // CreatePopulation_H
