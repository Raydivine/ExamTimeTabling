#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setProgramme(Programme *target ,char *programmeName, int numStudent);
void setPaper(Paper *target ,char *paperCode);
void addProgrammeToPaper(Paper *target, Programme *programme);
void addPaperToSession(Session *target, Paper *paper);
void addPapersToSession(Session *target, LinkedList *papers);
void addPaperToSessionTail(Session *target, Paper *paper);
void addSessionToTable(Table *target, Session *session);

Session *createDynamicSession();
Table *createDynamicTable();

//---------------------Tester tool function-----------------
void setPaperTakersNum(Paper *target ,char *paperCode, int num);

Session createSession();
Table createTable();


#endif // SetElements_H
