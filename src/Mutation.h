#ifndef Mutation_H
#define Mutation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void mutateInTwoSessions(Session *session1, Session *session2);
Paper *getTruePaperFromListA(LinkedList **listA, LinkedList *listB);
LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList **listB, int targetNum);

LinkedList *getPerfectPaperList(LinkedList *list1, LinkedList *list2, int *currentNum, int targetNum);

void printfPaperList(LinkedList *pList);
void printfPaper(Paper *p);

#endif // Mutation_H
