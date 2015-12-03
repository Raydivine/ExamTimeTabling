#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population);
Table buildChildTable(LinkedList *sListA, LinkedList *sListB, LinkedList **parrent);
void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent);
int isElementsNotInChild(LinkedList *sList, LinkedList *pList);
void addRemainToChild(Table *child, LinkedList *remain, int population);
Session useRemainBuildSession(LinkedList **remain, int num);

#endif // Crossover_H
