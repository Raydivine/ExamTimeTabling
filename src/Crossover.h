#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"
#include "LinkedList.h"

Table crossoverTwoTable( Table tableA, Table tableB, Paper *target, int population);
//void crossoverTwoTable(Table *child, Table tableA, Table tableB, Paper *target, int population);
LinkedList *buildChildList(void *mid, LinkedList *pListA, LinkedList *pListB);

#endif // Crossover_H
