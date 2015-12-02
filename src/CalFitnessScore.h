#ifndef CalFitnessScore_H
#define CalFitnessScore_H
#include "ExamStruct.h"
#include "LinkedList.h"

int calFitnessScore(LinkedList *sessionList);
int calConflict(LinkedList *paperList);
int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList);


#endif // CalFitnessScore_H
