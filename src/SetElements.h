#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void addPaperToSession(Session *target, Paper *paper);
void addPapersToSession(Session *target, LinkedList *papers);
void addPaperToSessionTail(Session *target, Paper *paper);
Session *createDynamicSession();
Table *createDynamicTable();

/***************THE BELOW FUNCTION ONLY USE IN TEST CODE***************
  *************************FOR FAKING A STRUCUTURE*********************/

void setProgramme(Programme *target ,char *programmeName, int numStudent);
void setPaper(Paper *target ,char *paperCode);
void setPaperTakersNum(Paper *target ,char *paperCode, int num);
void addProgrammeToPaper(Paper *target, Programme *programme);
void addSessionToTable(Table *target, Session *session);
Session createSession();
Table createTable();


#endif // SetElements_H
