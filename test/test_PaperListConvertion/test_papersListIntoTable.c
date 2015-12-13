#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
 
#define S1 table.sessions
#define S2 table.sessions->next
#define S3 table.sessions->next->next
#define S4 table.sessions->next->next->next
#define S5 table.sessions->next->next->next->next
#define S6 table.sessions->next->next->next->next->next
#define S7 table.sessions->next->next->next->next->next->next


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
LinkedList *pList;
Table table;

void setUp(void){
  setPaperTakersNum(&p1, "p1", 50);
  setPaperTakersNum(&p2, "p2", 50);
  setPaperTakersNum(&p3, "p3", 50);
  setPaperTakersNum(&p4, "p4", 50);
  setPaperTakersNum(&p5, "p5", 50);
  setPaperTakersNum(&p6, "p6", 50);
  setPaperTakersNum(&p7, "p7", 50);
  setPaperTakersNum(&p8, "p8", 50);
  setPaperTakersNum(&p9, "p9", 50);
  setPaperTakersNum(&p10, "p10", 50);
  
  // This test sturcture share to all test
  pList = linkListNew(&p10);
  addDataToHead(&pList, &p9);
  addDataToHead(&pList, &p8);
  addDataToHead(&pList, &p7); 
  addDataToHead(&pList, &p6); 
  addDataToHead(&pList, &p5); 
  addDataToHead(&pList, &p4); 
  addDataToHead(&pList, &p3); 
  addDataToHead(&pList, &p2); 
  addDataToHead(&pList, &p1); 
  
  table = createTable();
}

void tearDown(void){
  clearLinkList(&pList);
  clearLinkList(&(table.sessions));
}

/**  void papersListIntoTable(Table *table, LinkedList *pList, int max)
*
*    This put the plist(paperList) to table
*    First, it collect session 1 by 1 from plist, by using  takeSessionFromPaperList()
*    Then, put the session 1 by 1 to the table
* 
*    max : the maximum seat in school (also is the population in a session)
*/ 

/**  plist = NULL 
*/
void test_papersListIntoTable_given_plist_is_NULL_should_create_session_with_nothing(void){
  pList = NULL;
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 50);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NULL(S1_1);
  //printfTable( table);
}

/**  plist = p4,p3,p2,p1
  *
  *  population = 50  (refer to the maximum seat in school, the session can not have student Number exceed this)
  *
  *  Because each paper has 50 person, session only can have 1 paper, should create 4 session
  *
  *----------------output-------------------
  *
  *   Table:  s1  s2  s3  s4
  *           p1  p2  p3  p4
  * 
*/
void test_papersListIntoTable_given_populatoin_is_50_should_create_4_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 50);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NOT_NULL(S4);
  TEST_ASSERT_NULL(S5);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S4_1->data); 
  TEST_ASSERT_NULL(S1_2);
  TEST_ASSERT_NULL(S2_2);
  TEST_ASSERT_NULL(S3_2);
  TEST_ASSERT_NULL(S4_2);
  //printfTable( table);

}

/**  plist = p4,p3,p2,p1
  *
  *  population = 75 
  *
  *  Because each paper has 50 person, if 2 paper(100) is more than its limit
  *  session only can have 1 paper, , so still bild 4 session 
  *
  *----------------output-------------------
  *
  *   Table:  s1  s2  s3  s4
  *           p1  p2  p3  p4
  * 
*/
void test_papersListIntoTable_given_populatoin_is_75_should_create_4_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 50);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NOT_NULL(S4);
  TEST_ASSERT_NULL(S5);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S4_1->data);
  TEST_ASSERT_NULL(S1_2);
  TEST_ASSERT_NULL(S2_2);
  TEST_ASSERT_NULL(S3_2);
  TEST_ASSERT_NULL(S4_2);
  //printfTable( table);
}


/**  plist = p4,p3,p2,p1
  *
  *  population = 100 
  *
  *  each paper has 50 person, 1 session can have 2 paper
  *  so create 2 session
  *
  *----------------output-------------------
  *
  *   Table:    s1      s2      
  *           p1p2    p3p4
  * 
*/
void test_papersListIntoTable_given_populatoin_is_100_should_create_2_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 100);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NULL(S3);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_2->data);
  TEST_ASSERT_NULL(S1_3);
  TEST_ASSERT_NULL(S2_3);
  //printfTable( table);
}

/**  plist = p9,p8,p7,p6,p5,p4,p3,p2,p1
  *
  *  population = 150 
  *
  *  9 paper,  each paper has 50 person, session can have 3 paper
  *  so should build 3 session, each session has 3 paper
  *
  *----------------output-------------------
  *
  *   Table:    s1          s2      s3
  *           p1p2p3    p4p5p6    p7p8p9
  * 
*/
void test_papersListIntoTable_given_9paper_populatoin_is_150_should_create_3_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  addDataToHead(&pList, &p5); 
  addDataToHead(&pList, &p6); 
  addDataToHead(&pList, &p7); 
  addDataToHead(&pList, &p8); 
  addDataToHead(&pList, &p9); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 150);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NULL(S4);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S1_3->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S2_2->data);
  TEST_ASSERT_EQUAL_PTR(&p6, S2_3->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S3_2->data);
  TEST_ASSERT_EQUAL_PTR(&p9, S3_3->data);
  TEST_ASSERT_NULL(S1_4);
  TEST_ASSERT_NULL(S2_4);
  TEST_ASSERT_NULL(S3_4);
  //printfTable( table);
}

/**  plist = p9,p8,p7,p6,p5,p4,p3,p2,p1
  *
  *  population = 200 
  *
  *  9 paper,  each paper has 50 person, session can have 4 paper
  *  so should build 3 session, first and second session have 4 paper, 3rd session has 1 paper 
  *
  *----------------output-------------------
  *
  *   Table:   s1       s2        s3      (The LinkedListAdd function is addDataToHead(), so actually s3 build first, then build s2 and s1)
  *           p1     p2p3p4p5   p6p7p8p9
  * 
*/
void test_papersListIntoTable_given_9paper_populatoin_is_200_should_create_3_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  addDataToHead(&pList, &p5); 
  addDataToHead(&pList, &p6); 
  addDataToHead(&pList, &p7); 
  addDataToHead(&pList, &p8); 
  addDataToHead(&pList, &p9); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 200);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NULL(S4);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S2_2->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_3->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S2_4->data);
  TEST_ASSERT_EQUAL_PTR(&p6, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S3_2->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S3_3->data);
  TEST_ASSERT_EQUAL_PTR(&p9, S3_4->data);
  TEST_ASSERT_NULL(S1_2);
  TEST_ASSERT_NULL(S2_5);
  TEST_ASSERT_NULL(S3_5);
  //printfTable( table);
}

/**  plist = p9,p8,p7,p6,p5,p4,p3,p2,p1
  *
  *  population = 300 
  *
  *  9 paper,  each paper has 50 person, session can have 6 paper
  *  so build 2 session, first session has 6 paper, second session has 3 paper
  *
  *----------------output-------------------
  *
  *   Table:     s1             s2                 
  *            p1p2p3     p4p5p6p7p8p9     (The LinkedListAdd function is addDataToHead(), so actually s2 build first, then build s1)
  * 
*/
void test_papersListIntoTable_given_9paper_populatoin_is_300_should_create_2_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  addDataToHead(&pList, &p5); 
  addDataToHead(&pList, &p6); 
  addDataToHead(&pList, &p7); 
  addDataToHead(&pList, &p8); 
  addDataToHead(&pList, &p9); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 300);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NULL(S3);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S1_3->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S2_2->data);
  TEST_ASSERT_EQUAL_PTR(&p6, S2_3->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S2_4->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S2_5->data);
  TEST_ASSERT_EQUAL_PTR(&p9, S2_6->data);

  TEST_ASSERT_NULL(S2_7);
  TEST_ASSERT_NULL(S1_4);
  //printfTable( table);
}

/**  plist = p9,p8,p7,p6,p5,p4,p3,p2,p1
  *
  *  population = 600
  *
  *  9 paper,  each paper has 50 person, 9*50 = 540
  *  session can have all paper, then for build 1 session wit all element
  *
  *----------------output-------------------
  *
  *   Table:          s1                         
  *            p1p2p3p4p5p6p7p8p9     
  * 
*/
void test_papersListIntoTable_given_9paper_populatoin_is_600_should_create_1_session(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  addDataToHead(&pList, &p5); 
  addDataToHead(&pList, &p6); 
  addDataToHead(&pList, &p7); 
  addDataToHead(&pList, &p8); 
  addDataToHead(&pList, &p9); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 600);
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NULL(S2);
  TEST_ASSERT_EQUAL_PTR(&p1, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S1_3->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S1_4->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S1_5->data);
  TEST_ASSERT_EQUAL_PTR(&p6, S1_6->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S1_7->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S1_8->data);
  TEST_ASSERT_EQUAL_PTR(&p9, S1_9->data);

  TEST_ASSERT_NULL(S1_10);
  //printfTable( table);
}


/**  plist = p4,p3,p2,p1
  *
  *  population = 25  
  *
  *  each paper has 50 person, population has 25, 
  *  means the paper's taker are larger then the total seat in school
  *  this is a violation, to avoid this violation accure,
  *  the assertion is written in sub function of takeSessionFromPaperList()
  *
  *  Because the assertion is used, un "X" this test will cause system error
*/
void xtest_papersListIntoTable_given_populatoin_is_25_should_system_fail_due_to_assertion(void){
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 
  //-------------------------------------------------------------------------------------------

  papersListIntoTable( &table, pList, 50);
}