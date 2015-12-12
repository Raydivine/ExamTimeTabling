#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3;

void setUp(void)
{
  p1.takersNum = 100;
  p2.takersNum = 200;
  p3.takersNum = 300;
}

void tearDown(void){}

/**
*    struct Session{
*     int fitnessScore;       = 0
*     int population;         = 0
*     LinkedList *papers;     = NULL
*    }
*/
void test_createSession_should_create_the_session_with_0_conflict_0_population_empty_papers(void){

  Session s = createSession();
  TEST_ASSERT_EQUAL(0, s.size);
  TEST_ASSERT_NULL(s.papers);
  clearLinkList(&(s.papers));
}


void test_addPaperToSessionTail_given_session_add_p1_should_have_population_equal_100(void){
  
  Session s = createSession();

  addPaperToSessionTail(&s, &p1);
  TEST_ASSERT_EQUAL(100, s.size);
  TEST_ASSERT_EQUAL_PTR(&p1, s.papers->data);
  TEST_ASSERT_NULL(s.papers->next);
  clearLinkList(&(s.papers));
}

void test_addPaperToSessionTail_given_session_add_p1_p2_should_have_population_equal_300(void){
  
  Session s = createSession();

  addPaperToSessionTail(&s, &p1);
  addPaperToSessionTail(&s, &p2);
  TEST_ASSERT_EQUAL(300, s.size);
  TEST_ASSERT_EQUAL_PTR(&p1, s.papers->data);
  TEST_ASSERT_EQUAL_PTR(&p2, s.papers->next->data);
  TEST_ASSERT_NULL(s.papers->next->next);
  clearLinkList(&(s.papers));
}

void test_addPaperToSessionTail_given_session_add_p1_p2_p3_should_have_population_equal_600(void){
  
  Session s = createSession();

  addPaperToSessionTail(&s, &p1);
  addPaperToSessionTail(&s, &p2);
  addPaperToSessionTail(&s, &p3);
  TEST_ASSERT_EQUAL(600, s.size);
  TEST_ASSERT_EQUAL_PTR(&p1, s.papers->data);
  TEST_ASSERT_EQUAL_PTR(&p2, s.papers->next->data);
  TEST_ASSERT_EQUAL_PTR(&p3, s.papers->next->next->data);
  TEST_ASSERT_NULL(s.papers->next->next->next);
  clearLinkList(&(s.papers));
}



