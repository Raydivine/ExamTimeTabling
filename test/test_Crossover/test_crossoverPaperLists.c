#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
#include "Crossover.h"

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_SESSION_1_TO_4 clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));
#define CLEAR_SESSION_5_TO_8 clearLinkList(&(s5.papers)); clearLinkList(&(s6.papers)); clearLinkList(&(s7.papers)); clearLinkList(&(s8.papers));

#define HEAD  pList
#define HEAD1 pList->next
#define HEAD2 pList->next->next
#define HEAD3 pList->next->next->next
#define HEAD4 pList->next->next->next->next
#define HEAD5 pList->next->next->next->next->next
#define HEAD6 pList->next->next->next->next->next->next
#define HEAD7 pList->next->next->next->next->next->next->next
#define HEAD8 pList->next->next->next->next->next->next->next->next
#define HEAD9 pList->next->next->next->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4,s5,s6,s7,s8;
Table tableA, tableB;

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


/**  LinkedList *crossoverPaperLists( Table tableA, Table tableB, Paper *target)
*    This function return croosovered paperList form tableA and tableB
*  
*
*    ProccessFlow
*    1. Convert tableA and tableB to paperLoopA and paperLoopB 
*       ( paper is the unit element in chromosome, convert to loop is for the convenient of crossover
*         during convertion, the linkedListAdd function is addDataToHead()
*         so the loop actually is reversed order of table's paperList 
*       )
*    2. Reverse paperLoopB
*       ( reversed paperLoopB so its direction go to right, while paperLoopA is go to left due to the convertion)
*    3. Point the head of them to target
*       ( as the starting middle point to do croosover )
*
*    4.  Get the croosovered paperList by pass them to buildChildList()
*    5.  return croosovered paperList
*  
*
* Due to it is a global function, the result is unprediable, so testing is by print out 
*/

/**                       target = p4 
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *              <--------------- X
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *              --> break                          X------- 
  *           
  * 
  * output list  =   p1  p2  p3  p4  p6  p7  (p8 p5)  
  *                                           added mising element from tableA                               
  *
*/
void test_crossoverPaperLists_given_target_is_p4_should_stop_at_tableB_p3(void){ 
  
  LinkedList *pList = crossoverPaperLists( tableA, tableB, &p4);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);
  
  // printfTable(tableA);
  // printfTable(tableB);
  // printfPaperList(pList);
  clearLinkList(&pList); 
}

/**                       target = p1 
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *              X                                       <-
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *                                X   break
  *           
  * 
  * output list  =   p1  p8  (p7  p6  p5  p4  p3 p2)  
  *                            added mising element from tableA                               
  *
*/
void test_crossoverPaperLists_given_target_is_p1_should_stop_at_tableB_p8(void){ 
  
  LinkedList *pList = crossoverPaperLists( tableA, tableB, &p1);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);
  clearLinkList(&pList); 
}

/**                       target = p6 
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *                        break  <----------X                                       
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *              ------>                                   X
  *           
  * 
  * output list  =   p4  p5  p6  p7  p3  (p2  p1   p8)  
  *                                       added mising element from tableA                               
  *
*/
void test_crossoverPaperLists_given_target_is_p6_should_stop_at_tableA_p3(void){ 
  
  LinkedList *pList = crossoverPaperLists( tableA, tableB, &p6);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);
  clearLinkList(&pList); 
}

/**                       target = p5 
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *                   <-----------------X                                       
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *                         X----------->    break                                
  *           
  * 
  * output list  =   p2  p3  p4  p5  p1  p8  (p7   p6)  
  *                                           added mising element from tableA                               
  *
*/
void test_crossoverPaperLists_given_target_is_p5_should_stop_at_tableB_p2(void){ 
  
  LinkedList *pList = crossoverPaperLists( tableA, tableB, &p5);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);
  clearLinkList(&pList); 
}

/**                       target = p2
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *              -----X                            <-------                     
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *             break                          X----------->                              
  *           
  * 
  * output list  =   p7  p8  p1  p2  p4  p6  (p5   p3)  
  *                                           added mising element from tableA                               
  *
*/
void test_crossoverPaperLists_given_target_is_p2_should_stop_at_tableB_p7(void){ 
  
  LinkedList *pList = crossoverPaperLists( tableA, tableB, &p2);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);

  clearLinkList(&pList); 
}
