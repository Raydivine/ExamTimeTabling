#include "ExamStruct.h"
#include "Crossover.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
#include <stdio.h>

Table crossoverTwoTable(Table tableA, Table tableB, Paper *target, int population){
  Table child = createTable();
  LinkedList *loopA, *loopB, *childList;
  loopA = sessionListToPapersLoop( tableA.sessions);
  loopB = sessionListToPapersLoop( tableB.sessions);

  while(loopA->data != target)
    loopA = loopA->next;
  while(loopB->data != target)
    loopB = loopB->next;
  
  reverseLoop(&loopA);
  childList = buildChildList( target, loopA->next, loopB->next);    //loopA and loopB already pointed to target, so pass "next"
  papersListIntoTable( &child, childList, population);
  
  //printfTable(child);
  //printfTableWithPaperOnly( &child);

  //printfTable(*childP);
  return child;
}

/*
void crossoverTwoTable(Table *child, Table tableA, Table tableB, Paper *target, int population){
  LinkedList *loopA, *loopB, *childList;
  loopA = sessionListToPapersLoop( tableA.sessions);
  loopB = sessionListToPapersLoop( tableB.sessions);
  
  while(loopA->data != target)
    loopA = loopA->next;
  while(loopB->data != target)
    loopB = loopB->next;
  
  reverseLoop(&loopA);
  childList = buildChildList( target, loopA->next, loopB->next);    //loopA and loopB already pointed to target, so pass "next"
  papersListIntoTable( child, childList, population);
 // printfTable(*child);

}*/

LinkedList *buildChildList(void *mid, LinkedList *listA, LinkedList *listB){
  LinkedList *child = linkListNew(mid);
  
  while( isDataNotInList(child,listA->data) ){      // Doing crossover from listA and listB
    addDataToHead( &child, listA->data);            // add to left
    listA = listA->next;
    
    if( isDataNotInList(child,listB->data) ){
      addDataToTail( &child, listB->data);          // add to right
      listB = listB->next;
    }else break;
  }
  
  while( listA->data != mid ){                    // add the mising element to the tail 
    if( isDataNotInList(child,listA->data) )
      addDataToTail( &child, listA->data);
    listA = listA->next;
  }
  return child;
}