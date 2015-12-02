#ifndef BuildSessionList_H
#define BuildSessionList_H
#include "ExamStruct.h"
#include "LinkedList.h"

LinkedList *buildSessionListFromPaperList(LinkedList *pList, int population);
Session *buildSessionWithinPopulation(LinkedList *pList, int population);

#endif // BuildSessionList_H
