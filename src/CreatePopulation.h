#ifndef CreatePopulation_H
#define CreatePopulation_H
#include "ExamStruct.h"
#include "LinkedList.h"

Table *getPopulation(Paper *papersArr[], int totalPapers, int maxPeopleInSession, int populationNum);
LinkedList *convertArrayToLinkedList(Paper *papersArr[], int size);
void shuffleArray( Paper *papersArr[], int size);


#endif // CreatePopulation_H
