#ifndef CalFitnessScore_H
#define CalFitnessScore_H
#include "ExamStruct.h"
#include "LinkedList.h"


int calFitnessScore(LinkedList *sList);
int calConflict(LinkedList *pList);
int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList);


#endif // CalFitnessScore_H
