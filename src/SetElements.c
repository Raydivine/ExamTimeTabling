#include "SetElements.h"
#include "ExamStruct.h"
#include "CalFitnessScore.h"
#include <stdio.h>

void setProgramme(Programme *target ,char *programmeName, int numStudent){
  target->name = programmeName;
  target->studentNum = numStudent;
}

void setPaper(Paper *target ,char *paperCode){
  target->code = paperCode;
  target->takersNum = 0;
  target->programmes = NULL;
}

void addProgrammeToPaper(Paper *target, Programme *programme){
  addDataToHead(&(target->programmes), programme);
  target->takersNum = target->takersNum + programme->studentNum;
}

Session createSession(){
  Session session;
  
  session.population = 0;
  session.papers = NULL;
  return session;
}

void addPaperToSession(Session *target, Paper *paper){
  addDataToHead(&(target->papers), paper);
  target->population = target->population + paper->takersNum;
}

void addPapersToSession(Session *target, LinkedList *papers){
  Paper *p;
  
  while( papers != NULL){
    p = (Paper*)papers->data; 
    addPaperToSession(target, p);
    papers = papers->next;
  }
}

Table createTable(){
  Table table;
  
  table.fitnessScore = 0;
  table.sessions = NULL;
  return table;
}

void addSessionToTable(Table *target, Session *session){
  addDataToHead(&(target->sessions), session);
}

void setVenue(Venue *target, char *name, int venueCode, int seatNum){
  target->blockName = name;
  target->code = venueCode;
  target->seats = seatNum;
}


// The below functions are redundant , created for tester as tools for testing purpose
void setPaperTakersNum(Paper *target ,char *paperCode, int num){
  target->code = paperCode;
  target->takersNum = num;
  target->programmes = NULL;
}




