#ifndef LinkedListRemove_H
#define LinkedListRemove_H
#include "LinkedList.h"

void removeDatasFromList(LinkedList **list, LinkedList *jumpList);
void removeDataFromList(LinkedList **list, void *removeData);
void removeHead(LinkedList **list);
LinkedList *returnHead(LinkedList **list);


#endif // LinkedListReomve_H
