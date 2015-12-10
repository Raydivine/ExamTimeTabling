#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
 
#define S1 sList->data
#define S2 sList->next->data
#define S3 sList->next->next->data
#define S4 sList->next->next->next->data
#define S5 sList->next->next->next->next->data
#define S6 sList->next->next->next->next->next->data
#define S7 sList->next->next->next->next->next->next->data

#define S1_P1 S1
#define S1_P2 S1->next
#define S1_P3 S1->next->next
#define S1_P4 S1->next->next->next
#define S1_P5 S1->next->next->next->next
#define S1_P6 S1->next->next->next->next->next
#define S1_P7 S1->next->next->next->next->next->next

#define S2_P1 S2
#define S2_P2 S2->next
#define S2_P3 S2->next->next
#define S2_P4 S2->next->next->next
#define S2_P5 S2->next->next->next->next
#define S2_P6 S2->next->next->next->next->next
#define S2_P7 S2->next->next->next->next->next->next

#define S3_P1 S3
#define S3_P2 S3->next
#define S3_P3 S3->next->next
#define S3_P4 S3->next->next->next
#define S3_P5 S3->next->next->next->next
#define S3_P6 S3->next->next->next->next->next
#define S3_P7 S3->next->next->next->next->next->next

#define S4_P1 S4
#define S4_P2 S4->next
#define S4_P3 S4->next->next
#define S4_P4 S4->next->next->next
#define S4_P5 S4->next->next->next->next
#define S4_P6 S4->next->next->next->next->next
#define S4_P7 S4->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *pList, *sList;


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
}

void tearDown(void){
  clearLinkList(&pList);
  clearLinkList(&sList);
}

/**  LinkedList *paperListToSessionList(LinkedList *pList, int max)
*
*    This function convert the paperList to sessionList
*    pList is the list of paper
*    max is the maximum seat in school
*    while the populatoin in each session can not more than the max
*    (population : number of student do exam in same session)
*
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


void test_papersListIntoTable_should_create_4_session(void){
  sList = NULL;
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 

  //-------------------------------------------------------------------------------------------
  Table table = createTable();
  papersListIntoTable( &table, pList, 50);
  sList = table.sessions;
  TEST_ASSERT_NOT_NULL(sList);
  TEST_ASSERT_NOT_NULL(sList->next);
  TEST_ASSERT_NOT_NULL(sList->next->next);
  TEST_ASSERT_NOT_NULL(sList->next->next->next);
  TEST_ASSERT_NULL(sList->next->next->next->next);
  
  
//  TEST_ASSERT_EQUAL_PTR(&p1, S1_P1->data);
  
  printfTable( table);
}