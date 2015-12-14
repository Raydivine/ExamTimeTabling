#ifndef CreatePopulation_H
#define CreatePopulation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void setPopulation( Table table[], Paper papers[], int papersNum, int maxPeopleInSession, int populationNum);
void shuffleArray( Paper papers[], int size);
LinkedList *convertArrayToLinkedList(Paper *papersArr[], int papersNum);


#endif // CreatePopulation_H
