#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
 
#define HEAD  sList
#define HEAD1 sList->next
#define HEAD2 sList->next->next
#define HEAD3 sList->next->next->next
#define HEAD4 sList->next->next->next->next
#define HEAD5 sList->next->next->next->next->next
#define HEAD6 sList->next->next->next->next->next->next

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
  *   sList:  s1  s2  s3  s4
  *           p1  p2  p3  p4
  * 
*/


void test_paperListToSessionList_should_create_4_session(void){
  sList = NULL;
  pList = linkListNew(&p1);
  addDataToHead(&pList, &p2);
  addDataToHead(&pList, &p3);
  addDataToHead(&pList, &p4); 

  //-------------------------------------------------------------------------------------------
   
  papersListIntoSessionList( &sList, &pList, 50);
  TEST_ASSERT_NOT_NULL( HEAD);
  TEST_ASSERT_NOT_NULL( HEAD1);
  TEST_ASSERT_NOT_NULL( HEAD2);
  TEST_ASSERT_NOT_NULL( HEAD3);
  TEST_ASSERT_NOT_NULL( HEAD4);

  
  // Session  *s = (Session*)HEAD->data;
  // printfPaperList(s->papers);
  
  // s = (Session*)HEAD1->data;
  // printfPaperList(s->papers);
  
//  s = (Session*)HEAD2->data;
//  printfPaperList(s->papers);
  
  // s = (Session*)HEAD3->data;
  // printfPaperList(s->papers);
  
 // printfSessionList( sList);
}