#include "unity.h"
#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"

#define CLEAR_ALL_SESSION clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));

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
Session s1,s2,s3,s4;

LinkedList *sList, *pList;

void setUp(void){
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  
  setPaper(&p1 ,"p1");
  setPaper(&p2 ,"p2");
  setPaper(&p3 ,"p3");
  setPaper(&p4 ,"p4");
  setPaper(&p5 ,"p5");
  setPaper(&p6 ,"p6");
  setPaper(&p7 ,"p7");
  setPaper(&p8 ,"p8");
  setPaper(&p9 ,"p9");
  setPaper(&p10, "p10");
  
  sList = NULL;
  pList = NULL;
}

void tearDown(void){
  CLEAR_ALL_SESSION;
  clearLinkList(&sList);
  clearLinkLoop(&pList);
}

/** LinkedList *sessionListToPapersLoop(LinkedList *sList)
  *
  *  convert the sessionList to paperlist ( paper is element of session)
  *  and the paperlist is looped , called as papersLoop.
  *
  *  The purpose to create papersLoop is for crossover
*/


/** 
  *     NULL          
  *     
  *
  *------------OUTPUT------------
  *
  *    NULL
  *
*/
void test_sessionListToPapersLoop_given_NULL_should_create_loop_NULL(void){
  
  sList = NULL;
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NULL(HEAD);
}

/** 
  *     s1          
  *     p1
  *
  *------------OUTPUT------------
  *
  *    p1---->p1
  *
*/
void test_sessionListToPapersLoop_given_one_paper_only_should_create_loop_p1(void){
  addPaperToSession(&s1, &p1);
  sList = linkListNew(&s1);
  
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
}

/** 
  *      s1          
  *     p1p2
  *
  *------------OUTPUT------------
  *
  *    p1p2 --->p1 (loop back to head)
  *
*/
void test_sessionListToPapersLoop_given_2_paper_only_should_create_loop_p1_p2(void){
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s1, &p2);
  sList = linkListNew(&s1);
  
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD3->data);
}

/** 
  *      s1          
  *     p1p2p3
  *
  *------------OUTPUT------------
  *
  *    p1p2p3 --->p1 (loop back to head)
  *
*/
void test_sessionListToPapersLoop_given_3_paper_should_create_loop_p1_p2_p3(void){
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p3);
  sList = linkListNew(&s1);
  
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD3->data);
}

/** 
  *      s1          s2    
  *     p1p2p3    p4p5p6
  *
  *------------OUTPUT------------
  *
  *    p1p2p3p4p5p6 --->p1 (loop back to head)
  *
*/
void test_sessionListToPapersLoop_given_2_session_6_paper_should_create_loop_p1_to_p6(void){
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p3);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p6);
  
  sList = linkListNew(&s1);
  addDataToHead( &sList, &s2);
  
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD6->data);
}

/** 
  *      s1          s2           s3
  *     p1p2p3    p4p5p6        p7p8p9
  *
  *------------OUTPUT------------
  *
  *    p1p2p3p4p5p6p7p8p9 --->p1 (loop back to head)
  *
*/
void test_sessionListToPapersLoop_given_3_session_9_paper_should_create_loop_p1_to_p6(void){
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p3);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p6);
  
  addPaperToSession(&s3, &p7);
  addPaperToSession(&s3, &p8);
  addPaperToSession(&s3, &p9);
  
  sList = linkListNew(&s1);
  addDataToHead( &sList, &s2);
  addDataToHead( &sList, &s3);
  
  pList = sessionListToPapersLoop(sList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD7->data);
  TEST_ASSERT_EQUAL_PTR( &p9, HEAD8->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD9->data);
}