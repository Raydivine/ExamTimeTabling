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

void addProgrammeToPaper(Paper *target, Programme *programme){
  addDataToHead(&(target->programmes), programme);
  target->takersNum = target->takersNum + programme->studentNum;
}

Session createSession(){
  Session session;
  
  session.fitnessScore = 0;
  session.population = 0;
  session.papers = NULL;
  return session;
}

void addPaperToSession(Session *target, Paper *paper){
  addDataToHead(&(target->papers), paper);
  target->population = target->population + paper->takersNum;
}
