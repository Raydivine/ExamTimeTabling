#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

void paperListToSessionList(LinkedList **sList, LinkedList *pList, int max);
LinkedList *sessionListToPapersLoop(LinkedList *sList);
Session takeSessionFromPaperList(LinkedList **pLists, int max);
void papersListIntoTable(Table *table, LinkedList *pList, int max);
void reverseLoop(LinkedList **loop);
void listToLoop(LinkedList **list); // Tester tool  ( this funntion is not used in main program )

#endif // PaperListConvertion_H
