#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void calFitnessScore(Session *session){
  int fitnessScore =0;
  Paper *paperX;
  LinkedList *paperList = session->papers;
  
  while(paperList !=NULL){
    paperX = (Paper*)paperList->data;                                                       //1. TypeClass the paperList->data to paperX
    fitnessScore = fitnessScore + calConflictFromPaperToPaparList(paperX, paperList->next); //2. calculate conflict between paperX and the paperList->next,continue add 
    paperList = paperList->next;
  }
  
  session->fitnessScore =fitnessScore;
}

int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList){
  int conflict =0;
  Paper *paperX;
  LinkedList *programmeList1 = paper->programmes, *programmeList2;

  while(paperList != NULL){
    paperX = (Paper*)paperList->data;                                             //1. TypeClass the paperList->data to paperX
    programmeList2 = paperX->programmes;                                          //2. take out programmeList from paperX's 
    conflict = conflict + isListsHaveSameElement(programmeList1, programmeList2); //3. check is the 2 list have same element,continue add 
    paperList = paperList->next;
  }
  
  return conflict;
}

