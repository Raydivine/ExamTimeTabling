#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

LinkedList *sessionListToPapersLoop(LinkedList *sList);
Session takeSessionFromPaperList(LinkedList **pLists, int max);
void papersListIntoTable(Table *table, LinkedList *pList, int max);
void papersListIntoTable1(Table *table, LinkedList *pList, int max);
void paperListIntoSessionList(LinkedList **sList, LinkedList **pList, int max);
void reverseLoop(LinkedList **loop);
void paperListToSessionList(LinkedList **sList, LinkedList *pList, int max);

// Tester tool  ( this funntion is not used in main program )
void listToLoop(LinkedList **list); 

#endif // PaperListConvertion_H
