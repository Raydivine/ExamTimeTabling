#include "Crossover.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include <stdio.h>

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population){
  
}

Table buildChildTable(LinkedList *sListA, LinkedList *sListB, LinkedList **parrent){
  Table child = createTable();
  Session *current = (Session*)sListA->data;
  
  while( isElementsNotInChild( child.sessions, current->papers) ){
    addToChildAndRemoveInParrent(current, &child, parrent);
    sListA = sListA->next;
    current = (Session*)sListB->data;
       
    if( isElementsNotInChild( child.sessions, current->papers) ){
      addToChildAndRemoveInParrent(current, &child, parrent);
      sListB = sListB->next;
      current = (Session*)sListA->data;
    } else break;
  }
  
  return child;
}

int isElementsNotInChild(LinkedList *sList, LinkedList *pList){
  Session *s;
  
  while(sList != NULL){
    s = (Session*)sList->data;                                              
    if( isListsHaveSameElement(s->papers, pList) )
      return 0;
    sList = sList->next;
  }
  return 1;
}


void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent){
  addSessionToTable(child, s);
  removeDatasFromList(parrent, s->papers);
}

void addRemainToChild(Table *child, LinkedList *remains, int population){
  
}