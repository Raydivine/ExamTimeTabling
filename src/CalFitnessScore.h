#ifndef CalFitnessScore_H
#define CalFitnessScore_H
#include "ExamStruct.h"
#include "LinkedList.h"

void calFitnessScore(Table *table);
void calConflictInSession(Session *session);
int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList);


#endif // CalFitnessScore_H
