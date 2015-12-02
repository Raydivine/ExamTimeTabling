#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population);
Table buildChildTable(Table tableA, Table tableB, LinkedList *parrent);
int isElementsNotInChild(LinkedList *sList, LinkedList *pList);

#endif // Crossover_H
