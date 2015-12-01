#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setPaper(Paper *target ,char *paperCode);
void setVenue(Venue *target, char *name, int venueCode, int seatNum);
void setProgramme(Programme *target ,char *programmeName, int numStudent);
void addProgrammeToPaper(Paper *target, Programme *programme);

Session createSession();
void addPaperToSession(Session *target, Paper *paper);
void addPapersToSession(Session *target, LinkedList *papers);

Table createTable();
void addSessionToTable(Table *target, Session *session);

//The below is redundant function, created as a tool for testing purpose
Session createSessionWithConflict(int num);
void setPaperWithPopulation(Paper *target ,char *paperCode, int num);

#endif // SetElements_H
