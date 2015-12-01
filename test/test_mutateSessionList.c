#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"
#include "printfStructs.h"

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_ALL_SESSION clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4;

void setUp(void){
  
  setPaperWithPopulation(&p1, "p1", 50);
  setPaperWithPopulation(&p2, "p2", 50);
  setPaperWithPopulation(&p3, "p3", 50);
  setPaperWithPopulation(&p4, "p4", 50);
  setPaperWithPopulation(&p5, "p5", 50);
  setPaperWithPopulation(&p6, "p6", 50);
  setPaperWithPopulation(&p7, "p7", 50);
  setPaperWithPopulation(&p8, "p8", 50);
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c1);
  addProgrammeToPaper(&p3, &c2);
  addProgrammeToPaper(&p4, &c2);
  addProgrammeToPaper(&p5, &c3);
  addProgrammeToPaper(&p6, &c3);
  addProgrammeToPaper(&p7, &c4);
  addProgrammeToPaper(&p8, &c4);
  
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
/** The share structrure show below
  *
  *       s1          s2         s3          s4
  *     p1,p2       p3,p4       p5,p6      p7,p8
  *     c1,c1       c2,c2       c3,c3      c4,c4
  *
  *  The 4 sessions have conflict, because their papers having same programmes,
  *  so passed the sessionList to the function
  *  The output stucture should reduced conflict
*/
}

void tearDown(void){
  
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_ALL_SESSION;
}

/**   void mutateSessionList(LinkedList **sessionList)
*
*     This function will use mutateTwoSession(Session *session1, Session *session2)
*     Session1 is fixed input for head of sessionList, Session2 will input by every session in (sessionList->next)
*     So the head will do mutateTwoSession() with the rest of element in its tail
*     
*     Due to sessionList is large combination strucutre, it is very hard to ensure the result,
*     So the tests below is just printOut the input and output structure, to oberserve is the structure become better 
*          
*     Notice : Un "X" to see the print input and output structure
*/  

void test_mutateSessionList_given_s1_at_head_should_mutate(void){
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  printf("--------------testing muteSessionList()----------------\n\n ");
  printf(" mutateSesionList test1\n");
  
  printf("  input :   ");
  printfSessionList(list);
  
  mutateSessionList(&list);
  
  printf("  output:   ");
  printfSessionList(list);
  printf("\n");
  
  clearLinkList(&list); 
}

void test_mutateSessionList_given_s2_at_head_should_mutate(void){
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s1);
  addDataToHead(&list, &s2);
  
  printf("  mutateSesionList test2\n");
  printf("  input :   ");
  printfSessionList(list);
  
  mutateSessionList(&list);
  
  printf("  output:   ");
  printfSessionList(list);
  printf("\n");

  clearLinkList(&list); 
}

void test_mutateSessionList_given_s3_at_head_should_mutate(void){
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  addDataToHead(&list, &s3);
  
  printf("  mutateSesionList test3\n");
  printf("  input :   ");
  printfSessionList(list);
  
  mutateSessionList(&list);
  
  printf("  output:   ");
  printfSessionList(list);
  printf("\n");
  
  clearLinkList(&list); 
}


void test_mutateSessionList_given_s4_at_head_should_mutate(void){
  LinkedList *list = linkListNew(&s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  addDataToHead(&list, &s4);
  
  printf("  mutateSesionList test4\n");
  printf("  input :   ");
  printfSessionList(list);
  
  mutateSessionList(&list);
  
  printf("  output:   ");
  printfSessionList(list);
  printf("\n");
  
  clearLinkList(&list); 
}
