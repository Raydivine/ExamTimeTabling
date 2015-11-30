#include "unity.h"
#include "CalConflict.h"
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
  addProgrammeToPaper(&p1, &c2);
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p4, &c4);
  addProgrammeToPaper(&p4, &c5);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  addProgrammeToPaper(&p6, &c6);
  addProgrammeToPaper(&p6, &c7);
  addProgrammeToPaper(&p7, &c7);
  addProgrammeToPaper(&p7, &c8);
  addProgrammeToPaper(&p8, &c8);
  addProgrammeToPaper(&p8, &c1);
  
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
  
/** The Table show below
  *
  *               s1           |          s2         |         s3          |        s4
  *           p1,       p2    |     p3,      p4     |    p5,       p6     |     p7,      p8
  *         c1,c2     c2,c3  |   c3,c4     c4,c5   |   c5,c6     c6,c7   |    c7,c8      c8,c1
  *
  *  The 4 sessions have conflict, and s1 contact s2, s2 contact s3 , s4 contanct s1
  *
  *
*/
}

void tearDown(void){
  
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_ALL_SESSION;
}

/**   void mutateTable(Table *table)
*
*     This function will use mutateTable(LinkedList **sessionList)
*
*     The mutate way will be like that
*
*       S1            S2            S3          S4          S5
*      list2-------------------------------------------------
*                     list3----------------------------------    
*                                   list4-------------------- 
*                                              list5---------
*         
*      list 1 till list 5 will be input to  mutateTable(LinkedList **sessionList),
*      so all the sesion will mutate to others
*
*     Due to table is large combination strucutre, it is very hard to ensure the result,
*     So the tests below is just printOut the input and output structure, to oberserve is the structure become better 
*         
*     Notice : Un "X" to see the print input and output structure 
*/  

void test_mutateTable_given_s1_at_head_should_mutate(void){
  Table table = createTable();
  addSessionToTable(&table, &s4);
  addSessionToTable(&table, &s3);
  addSessionToTable(&table, &s2);
  addSessionToTable(&table, &s1);
  
  printf("--------------testing mutateTable()----------------\n\n ");
  printf(" mutateSesionList test1\n");
  
  printf("  input :   ");
  printfTable(table);
  
  mutateTable(&table);
  
  printf("  output:   ");
  printfTable(table);
  printf("\n");
  
  clearLinkList(&table.sessions); 
}

void test_mutateTable_given_s2_at_head_should_mutate(void){
  Table table = createTable();
  addSessionToTable(&table, &s4);
  addSessionToTable(&table, &s3);
  addSessionToTable(&table, &s1);
  addSessionToTable(&table, &s2);
  
  printf("  mutateSesionList test2\n");
  printf("  input :   ");
  printfTable(table);
  
  mutateTable(&table);
  
  printf("  output:   ");
  printfTable(table);
  printf("\n");

  clearLinkList(&table.sessions); 
}

void test_mutateTable_given_s3_at_head_should_mutate(void){
  Table table = createTable();
  addSessionToTable(&table, &s4);
  addSessionToTable(&table, &s1);
  addSessionToTable(&table, &s2);
  addSessionToTable(&table, &s3);
  
  printf("  mutateSesionList test3\n");
  printf("  input :   ");
  printfTable(table);
  
  mutateTable(&table);
  
  printf("  output:   ");
  printfTable(table);
  printf("\n");
  
  clearLinkList(&table.sessions); 
}


void test_mutateTable_given_s4_at_head_should_mutate(void){
  Table table = createTable();
  addSessionToTable(&table, &s1);
  addSessionToTable(&table, &s3);
  addSessionToTable(&table, &s2);
  addSessionToTable(&table, &s4);
  
  printf("  mutateSesionList test4\n");
  printf("  input :   ");
  printfTable(table);
  
  mutateTable(&table);
  
  printf("  output:   ");
  printfTable(table);
  printf("\n");
  
  clearLinkList(&table.sessions); 
}
