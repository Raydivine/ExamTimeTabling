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

#define S1_1 ((Session*)S1->data)->papers
#define S1_2 ((Session*)S1->data)->papers->next
#define S1_3 ((Session*)S1->data)->papers->next->next
#define S1_4 ((Session*)S1->data)->papers->next->next->next
#define S1_5 ((Session*)S1->data)->papers->next->next->next->next
#define S1_6 ((Session*)S1->data)->papers->next->next->next->next->next
#define S1_7 ((Session*)S1->data)->papers->next->next->next->next->next->next

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
*    max : the maximum seat in school
*/ 

/**  plist = p4,p3,p2,p1
  *
  *  population = 50 
  *
  *  Because each paper has 50 person, so should build 4 session 
  *
  *----------------output-------------------
  *
  *   Table:  s1  s2  s3  s4
  *           p1  p2  p3  p4
  * 
*/


void test_papersListIntoTable_should_given_populatoin_is_50_should_create_4_session(void){
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
  //printfTable( table);
}

/**  plist = p4,p3,p2,p1
  *
  *  population = 100 
  *
  *  Because each paper has 50 person, so should build 2 session 
  *
  *----------------output-------------------
  *
  *   Table:    s1    s2  
  *           p1p2   p3p4
  * 
*/
void test_papersListIntoTable_should_given_populatoin_is_100_should_create_4_session(void){
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
  //printfTable( table);
}