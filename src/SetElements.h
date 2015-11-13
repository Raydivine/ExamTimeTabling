#ifndef SetElements_H
#define SetElements_H
#include "ExamStruct.h"

void setVenue(Venue *target, char *blockName, int code, int seats);
void setPaper(Paper *target ,char *code, int hour, int lecturerID);
void setProgramme(Programme *target ,char *name, int studentNum);


#endif // SetElements_H
