#include "ExamStruct.h"
#include "Crossover.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include <assert.h>
#include <stdio.h>

#define MAX_SESSIONS 100

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

void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent){
  addSessionToTable(child, s);
  removeDatasFromList(parrent, s->papers);
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

void addRemainToChild(Table *child, LinkedList *remain, int population){
   int arrSize = getLengthOfList(remain);
   Session s[population];
   int i = 0;

   while( remain !=NULL){
     s[i] = useRemainBuildSession(&remain , population ); // 1. using array to store the coming element, to prevent overWrite
     addSessionToTable( child, &s[i]);                    // 2. add the session to child, which stored in array
     i++;                                                  
  }
}

Session useRemainBuildSession(LinkedList **remain, int num){
  Session s = createSession();
  LinkedList *pList = *remain;
  Paper *p;
   
  while( s.population < num && pList!=NULL){
    p = (Paper*)pList->data;
    assert((p->takersNum) <= num);
    
    if( (s.population + p->takersNum) <= num)
      addPaperToSession(&s, p);
    else break;
    pList = pList->next;
  }
  *remain = pList;
  
  return s;
}