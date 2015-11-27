#include "Mutation.h"
#include "ExamStruct.h"
#include "CalConflict.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <stdio.h>

void mutateInTwoSessions(Session *session1, Session *session2){
  LinkedList *list1 = session1->papers, *list2 = session2->papers;
  Paper *p;
  
 
  
}

//True : no conflict to List2
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


LinkedList *getTruePapersFromListB(LinkedList *listA, LinkedList **listB, int targetNum){
  LinkedList *list = *listB, *papers = NULL;
  Paper *t;

  while( list !=NULL) {
    t = (Paper*)list->data;                                        
    
    if( calConflictFromPaperToPaparList(t, listA) == 0 ){
      removeDataFromList(listB, t);
      addDataToHead(&papers, &t);
      return papers;    
    }
    list = list->next;
  }
  
  return NULL;
}

int isTheAdditionWillCauseOverFlow(int *currentNum, int addNum, int targetNum){
  if(targetNum == 0)
    return 0;
  
  int sum = *currentNum + addNum;
  int flowRatio = (sum - targetNum)*100 / targetNum;
  
  if( flowRatio<20 ){
    *currentNum = *currentNum + addNum;
    return 1;
  }
  return 0;
}