#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setProgramme(Programme *target ,char *programmeName, int numStudent);
void setPaper(Paper *target ,char *paperCode);
void setVenue(Venue *target, char *name, int venueCode, int seatNum);
void addProgrammeToPaper(Paper *target, Programme *programme);
void addPaperToSession(Session *target, Paper *paper);
void addPaperToSessionTail(Session *target, Paper *paper);
void addPapersToSession(Session *target, LinkedList *papers);
void addSessionToTable(Table *target, Session *session);
Session createSession();
Table createTable();

//---------------------Tester tool function-----------------
void setPaperTakersNum(Paper *target ,char *paperCode, int num);

#endif // SetElements_H
