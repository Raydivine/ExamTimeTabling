#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void calFitnessScore(Table *table){
  
}

int calConflict(LinkedList *paperList){
  int conflict =0;
  Paper *p;
 
  while( paperList !=NULL) {
    p = (Paper*)paperList->data;                                               //1. TypeClass the paperList->data to p
    conflict = conflict + calConflictFromPaperToPaparList(p, paperList->next); //2. calculate conflict between paperX and the paperList->next,continue add 
    paperList = paperList->next;
  }
  return conflict;
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

