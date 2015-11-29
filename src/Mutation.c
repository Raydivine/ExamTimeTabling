#include "Mutation.h"
#include "ExamStruct.h"
#include "CalConflict.h"
#include "RatioChecking.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <stdio.h>

void mutateInTwoSessions(Session *session1, Session *session2){
  LinkedList *listA = session1->papers, *listB = session2->papers, *t2;
  Paper *t1;
  //   printf("ink\n");
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












Paper *getTruePaperFromListA(LinkedList **listA, LinkedList *listB){
  Paper *p;
  LinkedList *list = *listA;
  
  while( list !=NULL) {
    p = (Paper*)list->data;                                        
    if( calConflictFromPaperToPaparList(p, listB) == 0 ){
      removeDataFromList(listA, p);
      return p; 
    }
    list = list->next;
  }
  
  return NULL;
}

void printfPaperList(LinkedList *pList){
  
  Paper *p;
  
  while( pList !=NULL) {
    p = (Paper*)pList->data;                                        
    printf(" %s\t",p->code);
    pList = pList->next;
  }
  printf("\n");
}


void printfPaper(Paper *p){
   
  if( p !=NULL)                                  
    printf("Paper: %s\n",p->code);
  else 
    printf("it is NULL\n");
}