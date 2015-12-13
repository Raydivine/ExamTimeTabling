#include "printfStructs.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void printfTable(Table table){
  printfSessionList(table.sessions);
}

void printfTableWithPaperOnly(Table *table){
  LinkedList *sList = table->sessions;
  Session *s;
  
  while( sList != NULL){
    s = (Session*)sList->data;
    printfPaperListOnly(s->papers);
    sList = sList ->next;
  }
  printf("\n");
  
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

void printfPaperLoop(LinkedList *pLoop){
  LinkedList *head = pLoop;
  Paper *p = (Paper*)pLoop->data;                                        
  printf("%s",p->code);
  pLoop = pLoop->next;
  
  while( pLoop != head) {
    p = (Paper*)pLoop->data;                                        
    printf("%s",p->code);
    pLoop = pLoop->next;
  }
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

void printfPaperListOnly(LinkedList *pList){
  Paper *p;
  
  while( pList !=NULL) {
    p = (Paper*)pList->data;                                        
    printf("%s",p->code);
    pList = pList->next;
  }
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