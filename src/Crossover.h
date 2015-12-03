#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population);
Table buildChildTable(LinkedList *sListA, LinkedList *sListB, LinkedList **parrent);
void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent);
void addRemainToChild(Table *child, LinkedList *remains, int population);
int isElementsNotInChild(LinkedList *sList, LinkedList *pList);

#endif // Crossover_H
