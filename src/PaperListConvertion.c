#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "printfStructs.h"
#include <stdio.h>

LinkedList *sessionListToPapersLoop(LinkedList *sList){
  LinkedList *pLoop = NULL, *tail;
  Session *s;
  
  if( sList != NULL){
    s = (Session*)sList->data;
    addListToHead( &pLoop, s->papers);
    sList = sList->next;
  }

  tail = pLoop; 
  while( tail->next!=NULL)
     tail = tail->next;
   
  
  while( sList != NULL){
    s = (Session*)sList->data;
    addListToHead( &pLoop, s->papers);
    sList = sList->next;
  }  
  tail->next = pLoop;
  return pLoop;
}