#include "SetElements.h"
#include "ExamStruct.h"

void setVenue(Venue *target, char *blockName, int code, int seats){
  target->blockName = blockName;
  target->code = code;
  target->seats = seats;
}

void setPaper(Paper *target ,char *code, int hour, int lecturerID){
  target->code = code;
  target->hour = hour;
  target->lecturerID = lecturerID;
}

void setProgramme(Programme *target ,char *name, int studentNum, Paper subjects[]){
  target->name = name;
  target->studentNum = studentNum;
  target->subjects = subjects;
}