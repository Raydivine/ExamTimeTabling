#include "SetElements.h"
#include "ExamStruct.h"
#include "CalFitnessScore.h"
#include <stdio.h>
#include <malloc.h>


void addPaperToSessionTail(Session *target, Paper *paper){
  addDataToTail(&(target->papers), paper);
  target->size = target->size + paper->takersNum;
}

void addPaperToSession(Session *target, Paper *paper){
  addDataToHead(&(target->papers), paper);
  target->size = target->size + paper->takersNum;
}

void addPapersToSession(Session *target, LinkedList *papers){
  Paper *p;
  
  while( papers != NULL){
    p = (Paper*)papers->data; 
    addPaperToSession(target, p);
    papers = papers->next;
  }
}

Session *createDynamicSession(){
  Session *s = malloc(sizeof(Session));
  
  s->size = 0;
  s->papers = NULL;
  return s;
}

Table *createDynamicTable(){
  Table *t = malloc(sizeof(Table));
  
  t->fitnessScore = 0;
  t->sessions = NULL;
  return t;
}


/***************THE BELOW FUNCTION ONLY USE IN TEST CODE***************
  *************************FOR FAKING A STRUCUTURE*********************/

void setProgramme(Programme *target ,char *programmeName, int numStudent){
  target->name = programmeName;
  target->studentNum = numStudent;
}

void setPaper(Paper *target ,char *paperCode){
  target->code = paperCode;
  target->takersNum = 0;
  target->programmes = NULL;
}

void setPaperTakersNum(Paper *target ,char *paperCode, int num){
  target->code = paperCode;
  target->takersNum = num;
  target->programmes = NULL;
}

void addProgrammeToPaper(Paper *target, Programme *programme){
  addDataToHead(&(target->programmes), programme);
  target->takersNum = target->takersNum + programme->studentNum;
}

void addSessionToTable(Table *target, Session *session){
  addDataToHead(&(target->sessions), session);
}

Session createSession(){
  Session session;
  
  session.size = 0;
  session.papers = NULL;
  return session;
}

Table createTable(){
  Table table;
  
  table.fitnessScore = 0;
  table.sessions = NULL;
  return table;
}

