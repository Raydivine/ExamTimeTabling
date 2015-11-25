#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setVenue(Venue *target, char *name, int venueCode, int seatNum);
void setProgramme(Programme *target ,char *programmeName, int numStudent);
void setPaper(Paper *target ,char *paperCode);
void addProgrammeToPaper(Paper *target, Programme *programme);
Session createSession();
void addPaperToSession(Session *target, Paper *paper);


#endif // SetElements_H
