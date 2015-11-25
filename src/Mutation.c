#include "Mutation.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <stdio.h>

void mutateInTwoSessions(Session *session1, Session *session2){
  LinkedList *list1 = session1->papers, *list2 = session2->papers;
  Paper *p;
  
 
  
}

//True : no conflict to List2
Paper *getTruePaperFromListA(LinkedList **listA, LinkedList **listB){
  Paper *p;
  LinkedList *list1 = *listA, *list2 = *listA, *head = list1, *temp;
  
  while( list1 !=NULL) {
    p = (Paper*)list1->data;                                        
    
    if( calConflictFromPaperToPaparList(p, list2) == 0 ){
      removeDataFromList(&head, p);
      break;
    }
    list1 = list1->next;
  }
  
  *listA = head;
  return p;
}
