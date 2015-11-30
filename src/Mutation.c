#include "Mutation.h"
#include "ExamStruct.h"
#include "CalConflict.h"
#include "RatioChecking.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <stdio.h>
#include "printfStructs.h"

void mutateTable(Table *table){
  LinkedList *sList = table->sessions;
  
  while(sList->next->next != NULL){
    mutateSessionList(&sList);
    sList = sList ->next;
  }
}


void mutateSessionList(LinkedList **sessionList){
  LinkedList *sList = *sessionList, *list = sList->next;
  Session *head = (Session*)sList->data, *tail;
  
  while(list!= NULL){
    tail = (Session*)list->data;
    mutateTwoSession( head, tail);
    list = list->next;
  }
}

void mutateTwoSession(Session *session1, Session *session2){
  LinkedList *listA = session1->papers, *listB = session2->papers, *t2;
  Paper *t1;

  while( listA !=NULL) {
    t1 = (Paper*)listA->data; 
    if(calConflictFromPaperToPaparList(t1, listB) == 0){
      t2 = getTruePapersFromListB( session1->papers, session2->papers, t1->takersNum);
  
      if(t2 != NULL){
        removeDataFromList( &(session1->papers), t1);
        removeDatasFromList( &(session2->papers), t2);
        addPapersToSession(session1, t2);
        addPaperToSession(session2, t1);
        return;
      }
    }
    listA = listA->next;
  }
}

LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList *listB, int targetNum){
  int currentNum = 0;

  LinkedList *papers = getPerfectPaperList( listA, listB, &currentNum, targetNum);

  if( isRatioWithin20Percent(currentNum, targetNum))
    return papers;  
  return NULL;                                              
}

LinkedList *getPerfectPaperList(LinkedList *list1, LinkedList *list2, int *currentNum, int targetNum){
  Paper *t;
  LinkedList *perfect = NULL;
  
  while( list2 != NULL){
    t = (Paper*)list2->data;     
    if( calConflictFromPaperToPaparList(t, list1) == 0)             // 1. check is 't' no conflict to list1
      if( calConflictFromPaperToPaparList(t, perfect) == 0)         // 2. check  is 't' no conflict to perfect
        if( isSumUnderFlow( currentNum, t->takersNum, targetNum) )  // 3. check is (currentNum + t->takersNum), is underFlow to takersNum 
          addDataToHead(&perfect, t);                               
    list2 = list2->next;
  }
  return perfect;
}


