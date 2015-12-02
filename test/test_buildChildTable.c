#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"
 
#define CLEAR_ALL_SESSION1 clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));
#define CLEAR_ALL_SESSION2 clearLinkList(&(s5.papers)); clearLinkList(&(s6.papers)); clearLinkList(&(s7.papers)); clearLinkList(&(s8.papers));

#define HEAD  child.sessions
#define HEAD1 child.sessions->next
#define HEAD2 child.sessions->next->next
#define HEAD3 child.sessions->next->next->next
#define HEAD4 child.sessions->next->next->next->next
#define HEAD5 child.sessions->next->next->next->next->next
#define HEAD6 child.sessions->next->next->next->next->next->next


#define LIST  plist
#define LIST1 plist->next
#define LIST2 plist->next->next
#define LIST3 plist->next->next->next
#define LIST4 plist->next->next->next->next
#define LIST5 plist->next->next->next->next->next
#define LIST6 plist->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Session s1,s2,s3,s4,s5,s6,s7,s8;
LinkedList *plist, *sListA, *sListB;
Table child;

void setUp(void){
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  
  s5 = createSession();
  s6 = createSession();
  s7 = createSession();
  s8 = createSession();
}

void tearDown(void){

  CLEAR_ALL_SESSION1;
  CLEAR_ALL_SESSION2;
  clearLinkList(&plist);
  clearLinkList(&sListA);
  clearLinkList(&sListB);
  clearLinkList(&(child.sessions));
}

/**  Table buildChildTable(Table tableA, Table tableB, LinkedList *parrent)
*
*    taking the non-repeating elements(papers) from tableA,B to child , owns hit the repeated element then stop,
*    while the element is taken , then remove it in parrent. which parrent is paperList contain all the elements.
*
*/ 

/**  parrent = p1,p2,p3,p4
  * slistA
  *     s1      s2      s3    s4      
  *     p1      p2      p3    p4    
  *            
  * sListB                   
  *     s5      s6      s7    s8 
  *     p1      p2      p3    p4 
  *
  *
  *s5 has repeat element to s1, so stop at s5 
  *----------------output-------------------
  *
  * child = s1, 
  *
  * paperList = p2,p3,p4
*/
void test_buildChildTable_should_build_child_with_s1_only(void){
  
  plist = linkListNew(&p4);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);
  
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p2);
  addPaperToSession(&s3, &p3);
  addPaperToSession(&s4, &p4);

  addPaperToSession(&s5, &p1);
  addPaperToSession(&s6, &p2);
  addPaperToSession(&s7, &p3);
  addPaperToSession(&s8, &p4);  
  
  sListA = linkListNew(&s4);
  addDataToHead(&sListA, &s3);
  addDataToHead(&sListA, &s2);
  addDataToHead(&sListA, &s1);
  
  sListB = linkListNew(&s8);
  addDataToHead(&sListB, &s7);
  addDataToHead(&sListB, &s6);
  addDataToHead(&sListB, &s5);
  
  //-------------------------------------------------------------------------------------------
  child = buildChildTable(sListA, sListB, &plist);
  TEST_ASSERT_EQUAL_PTR( &s1, HEAD->data);
  TEST_ASSERT_NULL(HEAD1);
  
  TEST_ASSERT_EQUAL_PTR(&p2, LIST->data);
  TEST_ASSERT_EQUAL_PTR(&p3, LIST1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, LIST2->data);
  TEST_ASSERT_NULL(LIST3);  
}