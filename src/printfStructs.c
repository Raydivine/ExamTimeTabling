#include "printfStructs.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include <stdio.h>

void printfPopulationFitnessScore(Table *population[], int size){
  int i;
  
  for( i=0 ; i < size ; i++)
    printf("FitnessScore: %d\n", population[i]->fitnessScore);
}

void printfPopulation(Table *population[], int size){
  int i;
  
  for( i=0 ; i < size ; i++)
    printfTable( population[i]);
  
}


void printfTable(Table *table){
  printfSessionList(table->sessions);
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


void printfTablePointer(Table *table){
  printfSessionList(table->sessions);
  printf("\n");
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
  printf("\n");
}



void printfPaperListOnly(LinkedList *pList){
  Paper *p;
  
  while( pList !=NULL) {
    p = (Paper*)pList->data;                                        
    printf("%s",p->code);
    pList = pList->next;
  }
}

void printfPaper(Paper *p){
   
  if( p !=NULL)                                  
    printf("Paper: %s\n",p->code);
  else 
    printf("it is NULL\n");
}