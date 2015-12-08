#include "LinkedList.h"
#include <string.h>
#include <malloc.h>

LinkedList *linkListNew(void *data){
  LinkedList *link = malloc( sizeof(LinkedList) );
  link->data = data;
  link->next = NULL;

  return link;
}

void clearLinkList(LinkedList **link){
  LinkedList *current = *link, *nexts;
  
  while (current != NULL) {
    nexts = current->next; 
    free(current); 
    current = nexts; 
  }
  *link = NULL;
}

int isDataInList(LinkedList *list, void *data){

  while(list != NULL){
    if(list->data == data)
      return 1;
    else  list = list->next;  
  }
  return 0;
}

int isListsHaveSameElement(LinkedList *list1, LinkedList *list2){

  while(list1 != NULL){
    if( isDataInList(list2, list1->data) )
      return 1;
    else  list1 = list1->next;  
  }
  return 0;
}

int getLengthOfList(LinkedList *list){
  int i = 0;
  
  while(list != NULL){
    i++;
    list = list->next;
  }
  return i;
}