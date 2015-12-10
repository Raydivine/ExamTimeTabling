#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include <stdio.h>
#include <assert.h>

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
  if( *loop == NULL)
    return;
  LinkedList *head = *loop, *curr = head->next, *pre = head, *nxt;
  
  while(curr != head){ 
    nxt = curr->next; 
    curr->next = pre; 
    pre = curr; 
    curr = nxt; 
  } 
  nxt = curr->next;     // the while loop point curr to head, then head do last reverse
  curr->next = pre; 
  pre = curr; 
  curr = nxt; 
}

void papersListIntoTable(Table *table, LinkedList *pList, int max){

  Session s = takeSessionFromPaperList(&pList, max);
  addSessionToTable( table, &s);
  
  if( pList != NULL)
    papersListIntoTable( table, pList, max);
}

Session takeSessionFromPaperList(LinkedList **pLists, int max){
  Session s = createSession();
  LinkedList *pList = *pLists;
  Paper *p;
  
  while( s.population < max && pList!=NULL){
    p = (Paper*)pList->data;
    assert((p->takersNum) <= max);
    
    if( (s.population + p->takersNum) <= max)
      addPaperToSession(&s, p);
    else break;
    pList = pList->next;
  }
  *pLists = pList;
  
  return s;
}

// tester tool : convert the list to loop   ( this funntion is not used in main program )
void listToLoop(LinkedList **list){

  LinkedList *head = *list, *tail = head->next;
  
  while( tail->next != NULL)
    tail = tail->next; 
  tail->next = head;
}