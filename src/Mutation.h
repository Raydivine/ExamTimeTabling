#ifndef Mutation_H
#define Mutation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void mutateInTwoSessions(Session *session1, Session *session2);
Paper *getTruePaperFromListA(LinkedList **listA, LinkedList *listB);
LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList **listB, int targetNum);
int isTheRatioWithin20Percent(int currentNum, int targetNum);

#endif // Mutation_H
