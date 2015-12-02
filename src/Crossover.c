#include "Crossover.h"
#include "LinkedList.h"
#include "printfStructs.h"
#include <stdio.h>

Table crossoverTwoTable(Table tableA, Table tableB, LinkedList *parrent, int population){
  
}

Table buildChildTable(Table tableA, Table tableB, LinkedList *parrent){
  
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