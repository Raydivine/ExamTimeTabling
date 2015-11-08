#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListERR.h"
#include <string.h>
#include <malloc.h>

void addDataToTail(LinkedList **list, void *data){
  LinkedList *current = *list;
  
  if(current == NULL){
    current = linkListNew(data);
    *list = current;
  }
  else{
    while (current->next != NULL){
      current = current->next;
    }
    current->next = linkListNew(data);
  }
}

void addDataToHead(LinkedList **list, void *data){
  LinkedList *current = *list, *newHead;
  
  newHead = linkListNew(data);
  newHead->next = current;
  *list = newHead;
}

void addDataToMid(LinkedList **list, void *data, void *addAfterThis){
  LinkedList *current = *list, *mid, *tail;

  while(current != NULL){ 
    if(current->data == addAfterThis){
      tail = current->next;
      mid = linkListNew(data);
      mid->next = tail;
      current->next = mid;
      return; 
    }
    current = current->next;     
  }
  
  Throw(LL_ERR_DATA_IS_NOT_EXIST);
}