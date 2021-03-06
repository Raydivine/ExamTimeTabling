#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

LinkedList *sessionListToPapersLoop(LinkedList *sList);
Session *takeSessionFromPaperList(LinkedList **pLists, int max);
Table *buildTable(LinkedList *pList, int max);
void reverseLoop(LinkedList **loop);

// Tester tool  ( this funntion is not used in main program )
void listToLoop(LinkedList **list); 

#endif // PaperListConvertion_H
