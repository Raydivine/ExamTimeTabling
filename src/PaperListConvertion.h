#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

void papersListIntoTable(Table *table, LinkedList *pList, int max);


//void papersListIntoSessionList(LinkedList **sList, LinkedList **pList, int max);
//LinkedList *papersListIntoSessionList(LinkedList *pList, int max);


LinkedList *paperListToSessionList(LinkedList *pList, int max);
Session paperListToSession(LinkedList **pLists, int max);
LinkedList *sessionListToPapersLoop(LinkedList *sList);

void reverseLoop(LinkedList **loop);

void paperListIntoTable( Table *table, LinkedList *pList, int population);

void listToLoop(LinkedList **list); // Tester tool  ( this funntion is not used in main program )

#endif // PaperListConvertion_H
