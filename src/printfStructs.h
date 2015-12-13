#ifndef printfStructs_H
#define printfStructs_H
#include "ExamStruct.h"
#include "LinkedList.h"

void printfTableWithPaperOnly(Table *table);
void printfTable(Table table);
void printfSessionList(LinkedList *sList);
void printfPaperList(LinkedList *pList);
void printfPaperListOnly(LinkedList *pList);
void printfPaperLoop(LinkedList *pLoop);
void printfProgrammeList(LinkedList *proList);
void printfPaper(Paper *p);

#endif // printfStructs_H
