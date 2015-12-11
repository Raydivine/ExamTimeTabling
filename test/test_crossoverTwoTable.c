#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
#include "Crossover.h"

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_SESSION_1_TO_4 clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));
#define CLEAR_SESSION_5_TO_8 clearLinkList(&(s5.papers)); clearLinkList(&(s6.papers)); clearLinkList(&(s7.papers)); clearLinkList(&(s8.papers));


#define S1 child.sessions
#define S2 child.sessions->next
#define S3 child.sessions->next->next
#define S4 child.sessions->next->next->next
#define S5 child.sessions->next->next->next->next
#define S6 child.sessions->next->next->next->next->next
#define S7 child.sessions->next->next->next->next->next->next


// The below define are the paper sequence in session
//  example:  S1_1  = session1's first paper
//  example:  S1_2  = session1's second paper
//  example:  S2_1  = session2's first paper
#define S1_1 ((Session*)S1->data)->papers
#define S1_2 ((Session*)S1->data)->papers->next
#define S1_3 ((Session*)S1->data)->papers->next->next
#define S1_4 ((Session*)S1->data)->papers->next->next->next
#define S1_5 ((Session*)S1->data)->papers->next->next->next->next
#define S1_6 ((Session*)S1->data)->papers->next->next->next->next->next
#define S1_7 ((Session*)S1->data)->papers->next->next->next->next->next->next
#define S1_8 ((Session*)S1->data)->papers->next->next->next->next->next->next->next
#define S1_9 ((Session*)S1->data)->papers->next->next->next->next->next->next->next->next
#define S1_10 ((Session*)S1->data)->papers->next->next->next->next->next->next->next->next->next

#define S2_1 ((Session*)S2->data)->papers
#define S2_2 ((Session*)S2->data)->papers->next
#define S2_3 ((Session*)S2->data)->papers->next->next
#define S2_4 ((Session*)S2->data)->papers->next->next->next
#define S2_5 ((Session*)S2->data)->papers->next->next->next->next
#define S2_6 ((Session*)S2->data)->papers->next->next->next->next->next
#define S2_7 ((Session*)S2->data)->papers->next->next->next->next->next->next

#define S3_1 ((Session*)S3->data)->papers
#define S3_2 ((Session*)S3->data)->papers->next
#define S3_3 ((Session*)S3->data)->papers->next->next
#define S3_4 ((Session*)S3->data)->papers->next->next->next
#define S3_5 ((Session*)S3->data)->papers->next->next->next->next
#define S3_6 ((Session*)S3->data)->papers->next->next->next->next->next
#define S3_7 ((Session*)S3->data)->papers->next->next->next->next->next->next

#define S4_1 ((Session*)S4->data)->papers
#define S4_2 ((Session*)S4->data)->papers->next
#define S4_3 ((Session*)S4->data)->papers->next->next
#define S4_4 ((Session*)S4->data)->papers->next->next->next
#define S4_5 ((Session*)S4->data)->papers->next->next->next->next
#define S4_6 ((Session*)S4->data)->papers->next->next->next->next->next
#define S4_7 ((Session*)S4->data)->papers->next->next->next->next->next->next




Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4,s5,s6,s7,s8;
Table tableA, tableB;
int population;

void setUp(void){
  population = 100; // The population is initialize as 100,  as default value
  
  setProgramme(&c1,"c1", 0);
  setProgramme(&c2,"c2", 0);
  setProgramme(&c3,"c3", 0);
  setProgramme(&c4,"c4", 0);
  setProgramme(&c5,"c5", 0);
  setProgramme(&c6,"c6", 0);
  setProgramme(&c7,"c7", 0);
  setProgramme(&c8,"c8", 0);
  setProgramme(&c9,"c9", 0);
  setProgramme(&c10,"c10", 0);
  
  setPaperTakersNum(&p1, "p1", 50);
  setPaperTakersNum(&p2, "p2", 50);
  setPaperTakersNum(&p3, "p3", 50);
  setPaperTakersNum(&p4, "p4", 50);
  setPaperTakersNum(&p5, "p5", 50);
  setPaperTakersNum(&p6, "p6", 50);
  setPaperTakersNum(&p7, "p7", 50);
  setPaperTakersNum(&p8, "p8", 50);
  
  addProgrammeToPaper(&p1, &c2);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c3);
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p4, &c5);
  addProgrammeToPaper(&p4, &c4);
  addProgrammeToPaper(&p5, &c6);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p6, &c7);
  addProgrammeToPaper(&p6, &c6);
  addProgrammeToPaper(&p7, &c8);
  addProgrammeToPaper(&p7, &c7); 
  addProgrammeToPaper(&p8, &c1);
  addProgrammeToPaper(&p8, &c8);
  
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  s5 = createSession();
  s6 = createSession();
  s7 = createSession();
  s8 = createSession();
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  addPaperToSession(&s5, &p3);
  addPaperToSession(&s5, &p7);
  addPaperToSession(&s6, &p1);
  addPaperToSession(&s6, &p5);
  addPaperToSession(&s7, &p2);
  addPaperToSession(&s7, &p8);
  addPaperToSession(&s8, &p6);
  addPaperToSession(&s8, &p4);
  
  tableA = createTable();
  addSessionToTable(&tableA, &s4);
  addSessionToTable(&tableA, &s3);
  addSessionToTable(&tableA, &s2);
  addSessionToTable(&tableA, &s1);
  
  tableB = createTable();
  addSessionToTable(&tableB, &s8);
  addSessionToTable(&tableB, &s7);
  addSessionToTable(&tableB, &s6);
  addSessionToTable(&tableB, &s5);

/** Table A
  *
  *               s1           |          s2         |         s3          |        s4
  *           p1,       p2    |     p3,      p4     |    p5,       p6     |     p7,      p8
  *         c1,c2     c2,c3  |   c3,c4     c4,c5   |   c5,c6     c6,c7   |    c7,c8      c8,c1
  *
  * -------------------------------------------------------------------------------------------
  * Table B
  *
  *               s5           |          s6         |         s7          |        s8
  *           p7,        p3   |     p5,      p1     |    p8,       p2     |     p4,      p6
  *         c7,c8       c3,c4 |   c5,c6    c1,c2    |   c8,c1    c2,c3   |    c4,c5      c6,c7
  *
  * 
  * The 2 table share to all test
*/
}

void tearDown(void){
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_SESSION_1_TO_4;
  CLEAR_SESSION_5_TO_8;
  clearLinkList(&tableA.sessions); 
  clearLinkList(&tableB.sessions); 
}


/**  Table crossoverTwoTable(Table tableA, Table tableB, Paper *target, int population)
*
*    This function will build a child from tableA and tableB
*    a) target is the choosen point while doing crossover between tableA and tableB
*    b) population is the total student in session , while this number is depend on the total seat in school
*
*    ProccessFlow
*    1. Convert tableA and tableB to paperLoopA and paperLoopB 
*       ( paper is the unit element in chromosome, convert to loop is for the convenient of crossover)
*    2. Point the head of them to target
*       ( as the starting middle point to do croosover )
*    3. Reverse paperLoopA
*       ( reversed paperLoopA so its direction go to left, while paperLoopB go to right)
*    4.  Pass paperLoopA and paperLoopB to buildChildList()
*       ( this will return a croosover child list)  
*    5.  Convert the child list to child table
*  
*
* Due to it is a global function, the result is unprediable, so testing is by print out 
*/

void test_crossoverTwoTable_given_target_is_p4_should_crossover(void){
  Table child = createTable();
  
  // printf("tableA :\n ");
  // printfTable(tableA);
  // printf("tableB :\n ");
  // printfTable(tableB);
  // printf("Chosse %s as point to do croosover\n", p4.code);
  
  crossoverTwoTable( &child, tableA, tableB, &p4, population);
  // LinkedList *sList = child.sessions;
  // Session *s = (Session*)sList->data;
  // LinkedList *pList = s->papers;
  // printfPaperList(pList);
  
  
 // Paper *p = (Paper*)S1_1->data;
 // TEST_ASSERT_EQUAL_PTR(&p3, S1_1->data);
//  TEST_ASSERT_EQUAL_PTR(&p1, S2_1->data);

  //printf("child :\n ");
  printfTable(child);
 //   clearLinkList(&child.sessions); 
}
