#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setPaper(Paper *target ,char *code, LinkedList **programmes);
void setProgramme(Programme *target ,char *name, int studentNum);
void setVenue(Venue *target, char *blockName, int code, int seats);




#endif // SetElements_H
