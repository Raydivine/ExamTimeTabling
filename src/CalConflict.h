#ifndef CalConflict_H
#define CalConflict_H
#include "ExamStruct.h"
#include "LinkedList.h"

void calConflictInSession(Session *session);
int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList);


#endif // CalConflict_H
