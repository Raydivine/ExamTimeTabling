#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList{
  void *data;
  LinkedList *next;
  int length;
};

LinkedList *linkListNew(void *data); 
void clearLinkList(LinkedList *link); 

#endif // LinkedList_H
