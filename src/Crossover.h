#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"
#include "LinkedList.h"

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population);
int isElementsNotInChild(LinkedList *sList, LinkedList *pList);
Table buildChildTable(LinkedList *sListA, LinkedList *sListB, LinkedList **parrent);
void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent);

void addRemainToChild(Table *child, LinkedList *remain, int population);
Session useRemainBuildSession(LinkedList **remain, int num);

#endif // Crossover_H
