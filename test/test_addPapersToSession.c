#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Session s;

#define S_HEAD  s.papers
#define S_HEAD1 s.papers->next
#define S_HEAD2 s.papers->next->next
#define S_HEAD3 s.papers->next->next->next
#define S_HEAD4 s.papers->next->next->next->next
#define S_HEAD5 s.papers->next->next->next->next->next
#define S_HEAD6 s.papers->next->next->next->next->next->next
#define S_HEAD7 s.papers->next->next->next->next->next->next->next

void setUp(void){
  
  s = createSession();
  addPaperToSession(&s, &p1);
  addPaperToSession(&s, &p2);
  addPaperToSession(&s, &p3);
}

void tearDown(void){
  clearLinkList(&(s.papers));
}


void test_addPapersToSession_given_add_list_NULL_should_mantain(void){
  
  LinkedList *list = NULL;

  addPapersToSession(&s, list);
  TEST_ASSERT_EQUAL_PTR(&p3, S_HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p1, S_HEAD2->data);
  TEST_ASSERT_NULL(S_HEAD3);

  clearLinkList(&list);
}

void test_addPapersToSession_given_add_list_with_p4_should_have_session_p4_p3_p2_p1(void){
  
  LinkedList *list = linkListNew(&p4);

  addPapersToSession(&s, list);
  TEST_ASSERT_EQUAL_PTR(&p4, S_HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR(&p1, S_HEAD3->data);
  TEST_ASSERT_NULL(S_HEAD4);

  clearLinkList(&list);
}

void test_addPapersToSession_given_add_list_with_p4_p5_p6_should_have_session_p6_p5_p4_p3_p2_p1(void){
  
  LinkedList *list = linkListNew(&p6);
  addDataToHead(&list, &p5);
  addDataToHead(&list, &p4);

  addPapersToSession(&s, list);
  TEST_ASSERT_EQUAL_PTR(&p6, S_HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S_HEAD3->data);
  TEST_ASSERT_EQUAL_PTR(&p2, S_HEAD4->data);
  TEST_ASSERT_EQUAL_PTR(&p1, S_HEAD5->data);
  TEST_ASSERT_NULL(S_HEAD6);

  clearLinkList(&list);
}

void test_addPapersToSession_given_session_NULL_list_with_p4_p5_p6_should_have_session_p6_p5_p4(void){
  
  s.papers = NULL;
  LinkedList *list = linkListNew(&p6);
  addDataToHead(&list, &p5);
  addDataToHead(&list, &p4);

  addPapersToSession(&s, list);
  TEST_ASSERT_EQUAL_PTR(&p6, S_HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S_HEAD2->data);
  TEST_ASSERT_NULL(S_HEAD3);

  clearLinkList(&list);
}


