#include "printfStructs.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void printfTable(Table table){
  printfSessionList(table.sessions);
}

void printfSessionList(LinkedList *sList){
  Session *s;
  
  while( sList != NULL){
    s = (Session*)sList->data;
    printfPaperList(s->papers);
    sList = sList ->next;
  }
  printf("\n");
}

void printfPaperList(LinkedList *pList){  
  Paper *p;
  
  while( pList !=NULL) {
    p = (Paper*)pList->data;                                        
    printf("%s",p->code);
    printfProgrammeList(p->programmes);
    pList = pList->next;
  }
  printf("|");
}

void printfProgrammeList(LinkedList *proList){
  Programme *pro;
  printf("(");
  
  while( proList !=NULL) {
    pro = (Programme*)proList->data;                                        
    printf("%s",pro->name);
    proList = proList->next;
  }
  printf(")");
}

void printfPaper(Paper *p){
   
  if( p !=NULL)                                  
    printf("Paper: %s\n",p->code);
  else 
    printf("it is NULL\n");
}