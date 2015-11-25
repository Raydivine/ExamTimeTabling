#include "SetElements.h"
#include "ExamStruct.h"
#include <stdio.h>

void setVenue(Venue *target, char *blockName, int code, int seats){
  target->blockName = blockName;
  target->code = code;
  target->seats = seats;
}

void setProgramme(Programme *target ,char *name, int studentNum){
  target->name = name;
  target->studentNum = studentNum;
}

void setPaper(Paper *target ,char *code){
  target->code = code;
  target->takersNum = 0;
  target->programmes = NULL;
}

void addProgrammeToPaper(Paper *target, Programme *programmes){
  addDataToHead(&(target->programmes), programmes);
  target->takersNum = target->takersNum + programmes->studentNum;
}

