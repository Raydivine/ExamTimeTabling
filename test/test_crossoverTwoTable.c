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

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4,s5,s6,s7,s8;
Table tableA, tableB, child;

void setUp(void){
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
  addSessionToTable(&tableB, &s4);
  addSessionToTable(&tableB, &s3);
  addSessionToTable(&tableB, &s2);
  addSessionToTable(&tableB, &s1);
  
  child = createTable();
  
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
  clearLinkList(&child.sessions); 
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
*
*/

void test_crossoverTwoTable_given_target_is_p4_should_crossover(void){
	TEST_IGNORE_MESSAGE("Implement me!");
}
