#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2;

void setUp(void)
{
  p1.takersNum = 100;
  p2.takersNum = 200;
}

void tearDown(void){}

/**
*    struct Session{
*     int fitnessScore;       = 0
*     int population;         = 0
*     LinkedList *papers;     = NULL
*    }
*/
void test_createSession_should_create_the_session_with_0_fitnessScore_0_population_empty_papers(void){

  Session session = createSession();
  TEST_ASSERT_EQUAL(0, session.fitnessScore);
  TEST_ASSERT_EQUAL(0, session.population);
  TEST_ASSERT_NULL(session.papers);
}


void test_addPaperToSession_given_session_add_p1_should_have_population_equal_100(void){
  
  Session session = createSession();

  addPaperToSession(&session, &p1);
  TEST_ASSERT_EQUAL(100, session.population);
  TEST_ASSERT_EQUAL_PTR(&p1, session.papers->data);
  TEST_ASSERT_NULL(session.papers->next);
}

void test_addPaperToSession_given_session_add_p1_p2_should_have_population_equal_300(void){
  
  Session session = createSession();

  addPaperToSession(&session, &p1);
  addPaperToSession(&session, &p2);
  TEST_ASSERT_EQUAL(300, session.population);
  TEST_ASSERT_EQUAL_PTR(&p2, session.papers->data);
  TEST_ASSERT_EQUAL_PTR(&p1, session.papers->next->data);
  TEST_ASSERT_NULL(session.papers->next->next);
}



