#ifndef PaperListConvertion_H
#define PaperListConvertion_H
#include "ExamStruct.h"
#include "LinkedList.h"

LinkedList *sessionListToPapersLoop(LinkedList *sList);
void reverseLoop(LinkedList **loop);

void listToLoop(LinkedList **list); // Tester tool

#endif // PaperListConvertion_H
