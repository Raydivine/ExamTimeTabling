#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void calFitnessScore(Session *session){
  int fitnessScore =0;
  
  
  session->fitnessScore =0;
}


void printProgrammeList( LinkedList **programmeList){
  LinkedList *list1 = *programmeList;
  while( list1 != NULL){
    printf("%p\n",list1->data);
    list1 = list1->next;
  }
}


int calConflictFromPaperToPaparList(Paper *paper, LinkedList *paperList){
  int conflict =0;
  Paper *paperX;
  LinkedList *programmeList1 = paper->programmes, *programmeList2;

  while(paperList != NULL){
    paperX = (Paper*)paperList->data;
    programmeList2 = paperX->programmes;
    conflict = conflict + isListsHaveSameElement(programmeList1, programmeList2);
    paperList = paperList->next;
  }
  
  return conflict;
}

