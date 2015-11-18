#include "SetElements.h"
#include "ExamStruct.h"

void setPaper(Paper *target ,char *code, LinkedList *programmes){
  target->code = code;
  target->programmes = programmes;
}

void setProgramme(Programme *target ,char *name, int studentNum){
  target->name = name;
  target->studentNum = studentNum;
}

void setVenue(Venue *target, char *blockName, int code, int seats){
  target->blockName = blockName;
  target->code = code;
  target->seats = seats;
}