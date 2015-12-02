#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"
 
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
Session s,s1;
LinkedList *plist;
Table child;

void setUp(void){
  
  s = createSession();
  s1 = createSession();

  child = createTable();
  
  plist = linkListNew(&p4);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);
}

void tearDown(void){
  clearLinkList(&plist);
  clearLinkList(&(s.papers));
  clearLinkList(&(s1.papers));
  clearLinkList(&(child.sessions));
}

/**  void addToChildAndRemoveInParrent(Session *s, Table *child, LinkedList **parrent)
*
*    add sessions tp child, remove session's papers in parrent, which parrent is the paperList contain all papers
*
*/ 

/**  parrent = p1,p2,p3,p4
  *
  * child = NULL 
  *
  *     s        
  *     p1         
  *            
  *----------------output-------------------
  *
  * child = s, 
  *
  * paperList = p2,p3,p4
*/
void test_addToChildAndRemoveInParrent_given_s_has_p1_should_add_and_remove(void){
  addPaperToSession(&s, &p1);

  addToChildAndRemoveInParrent(&s, &child, &plist);

  TEST_ASSERT_EQUAL_PTR( &s, HEAD->data);
  TEST_ASSERT_NULL(HEAD1);
  
  TEST_ASSERT_EQUAL_PTR(&p2, LIST->data);
  TEST_ASSERT_EQUAL_PTR(&p3, LIST1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, LIST2->data);
  TEST_ASSERT_NULL(LIST3);  
}

/**  parrent = p1,p2,p3,p4
  *
  * child = s1 
  *
  *     s        
  *     p1         
  *            
  *----------------output-------------------
  *
  * child = s, s1, 
  *
  * paperList = p3,p4
*/
void test_addToChildAndRemoveInParrent_given_s_has_p1_p2_should_add_and_remove(void){
  
  addSessionToTable(&child, &s1);
  addPaperToSession(&s, &p1);
  addPaperToSession(&s, &p2);

  addToChildAndRemoveInParrent(&s, &child, &plist);

  TEST_ASSERT_EQUAL_PTR( &s, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &s1, HEAD1->data);
  TEST_ASSERT_NULL(HEAD2);

  TEST_ASSERT_EQUAL_PTR(&p3, LIST->data);
  TEST_ASSERT_EQUAL_PTR(&p4, LIST1->data);
  TEST_ASSERT_NULL(LIST2);  
}

/**  parrent = p1,p2,p3,p4
  *
  * child = s1 
  *
  *         s        
  *     p1,p2,p3,p4         
  *            
  *----------------output-------------------
  *
  * child = s, s1, 
  *
  * paperList = NULL
*/
void test_addToChildAndRemoveInParrent_given_s_has_p1_p2_should_add_and_plist_become_NULL(void){
  
  addSessionToTable(&child, &s1);
  addPaperToSession(&s, &p1);
  addPaperToSession(&s, &p2);
  addPaperToSession(&s, &p3);
  addPaperToSession(&s, &p4);

  addToChildAndRemoveInParrent(&s, &child, &plist);

  TEST_ASSERT_EQUAL_PTR( &s, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &s1, HEAD1->data);
  TEST_ASSERT_NULL(HEAD2);

  TEST_ASSERT_NULL(LIST);  
}