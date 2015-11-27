#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void calConflictInSession(Session *session){
  int score =0;
  Paper *p;
  LinkedList *list = session->papers;
  
  while( list !=NULL) {
    p = (Paper*)list->data;                                         //1. TypeClass the paperList->data to p
    score = score + calConflictFromPaperToPaparList(p, list->next); //2. calculate conflict between paperX and the paperList->next,continue add 
    list = list->next;
  }
  
  session->conflict = score;
}

int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList){
  int conflict =0;
  Paper *p;
  LinkedList *programmeList1 = paper->programmes, *programmeList2;

  while(paperList != NULL){
    p = (Paper*)paperList->data;                                                  //1. TypeClass the paperList->data to p
    programmeList2 = p->programmes;                                               //2. take out programmeList from p's 
    conflict = conflict + isListsHaveSameElement(programmeList1, programmeList2); //3. check is the 2 list have same element,continue add 
    paperList = paperList->next;
  }
  
  return conflict;
}

