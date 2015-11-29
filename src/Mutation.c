#include "Mutation.h"
#include "ExamStruct.h"
#include "CalConflict.h"
#include "RatioChecking.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <stdio.h>

void mutateInTwoSessions(Session *session1, Session *session2){
  LinkedList *listA = session1->papers, *listB = session2->papers, *p2s;
  Paper *p1;
  
  while( listA !=NULL) {
    p1 = (Paper*)listA->data;                                        
    if( calConflictFromPaperToPaparList(p1, listB) == 0 ){
      p2s = getTruePapersFromListB( listA, &listB, p1->takersNum );
      break;
    }
    listA = listA->next;
  }
  
  removeDataFromList( &(session1->papers), p1); 
  session2->papers = listB;
  
  
 
  
}


//True : no conflict to ListA
LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList **listB, int targetNum){
  LinkedList *list = *listB, *papers = NULL;
  Paper *t;
  int currentNum = 0;
  
  while( list != NULL){
    t = (Paper*)list->data;     
    if( calConflictFromPaperToPaparList(t, listA) == 0)           // 1. check is 't' no conflict to listA
      if( isSumUnderFlow( &currentNum, t->takersNum, targetNum) ) // 2. check is currentNum + t->takersNum , is underFlow to takersNum, if true then only add  
        addDataToHead(&papers, t);                                // 3. Passed 1,2, then only add 't' to papers
    list = list->next;
  }

  if( isRatioWithin20Percent(currentNum, targetNum) ){            // 4. check is the currentNum within 20% ratio of takersNum
    removeDatasFromList( listB, papers);                          // 5. remove taken Paers in listB
    return papers;                                                // 6. return truePapers
  }
  return NULL; 
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




//  printf("currentNum : %d\n", currentNum);