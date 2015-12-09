#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

LinkedList *sessionListToPapersLoop(LinkedList *sList);
void reverseLoop(LinkedList **loop);

void listToLoop(LinkedList **list); // Tester tool  ( this funntion is not used in main program )

#endif // PaperListConvertion_H
