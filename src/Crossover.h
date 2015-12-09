#ifndef Crossover_H
#define Crossover_H
#include "ExamStruct.h"
#include "LinkedList.h"

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population);

LinkedList *buildChildList(void *mid, LinkedList *pListA, LinkedList *pListB);




#endif // Crossover_H
