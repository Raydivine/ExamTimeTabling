#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "printfStructs.h"
#include <stdio.h>

LinkedList *sessionListToPapersLoop(LinkedList *sList){
  if( sList == NULL)
    return;

  LinkedList *head = NULL, *tail;
  Session *s = (Session*)sList->data;
  addListToHead( &head, s->papers);
  sList = sList->next; 
  
  tail = head; 
  while( tail->next!=NULL)
    tail = tail->next;    
  
  while( sList != NULL){
    s = (Session*)sList->data;
    addListToHead( &head, s->papers);
    sList = sList->next;
  }  
 // printfPaperList(head);
  
  tail->next = head;
  return head;
}