#ifndef Mutation_H
#define Mutation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void mutateTable(Table *table);
void mutateSessionList(LinkedList **sessionList);
void mutateTwoSession(Session *session1, Session *session2);
LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList *listB, int targetNum);
LinkedList *getPerfectPaperList(LinkedList *list1, LinkedList *list2, int *currentNum, int targetNum);


#endif // Mutation_H
