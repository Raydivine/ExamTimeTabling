#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setVenue(Venue *target, char *blockName, int code, int seats);
void setProgramme(Programme *target ,char *name, int studentNum);
void setPaper(Paper *target ,char *code);
void addProgrammeToPaper(Paper *target, Programme *programme);
Session createSession();
void addPaperToSession(Session *target, Paper *paper);


#endif // SetElements_H
