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
  LinkedList *papers = NULL;
  
  return papers;
}

