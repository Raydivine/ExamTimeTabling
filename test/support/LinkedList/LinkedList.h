#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList{
  void *data;
  LinkedList *next;
};

LinkedList *linkListNew(void *data); 
void clearLinkList(LinkedList **link); 
void clearLinkLoop(LinkedList **loop);  // loop : LinkedList loop
int isDataInList(LinkedList *list, void *data);
int isListsHaveSameElement(LinkedList *list1, LinkedList *list2);
int getLengthOfList(LinkedList *list);

#endif // LinkedList_H
