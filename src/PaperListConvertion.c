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
  tail->next = head;
  return head;
}

void reverseLoop(LinkedList **loop){
  
}

// tester tool : convert the list to loop
void listToLoop(LinkedList **list){
  LinkedList *head = *list, *tail = head->next;
  
  while( tail->next != NULL)
    tail = tail->next; 
  
  tail->next = head;
}