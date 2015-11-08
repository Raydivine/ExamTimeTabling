#ifndef LinkedListAdd_H
#define LinkedListAdd_H
#include "LinkedList.h"

void addDataToTail(LinkedList **list, void *data);
void addDataToHead(LinkedList **list, void *data);
void addDataToMid (LinkedList **list, void *data, void *addAfterThis);

#endif // LinkedListAdd_H
