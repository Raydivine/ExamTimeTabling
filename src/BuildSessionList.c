#include "BuildSessionList.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>


LinkedList *buildSessionListFromPaperList(LinkedList *pList, int population){
  Paper *p;
  LinkedList *sList = NULL;
  
  while( pList != NULL){
    p = (Paper*)pList->data;
    
    
    pList = pList->next;
  }
  return sList;
}

Session *buildSessionWithinPopulation(LinkedList *pList, int population){
  
  
}