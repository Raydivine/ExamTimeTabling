#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Session s1,s2,s3;

void setUp(void){}

void tearDown(void){}

/**
  struct Table{
    LinkedList *sessions;  = NULL
    int fitnessScore;      = 0
  };
*/

void test_createTable_should_create_the_table_with_0_fitnessScore_0_empty_papers(void){

  Table t = createTable();
  TEST_ASSERT_EQUAL(0, t.fitnessScore);
  TEST_ASSERT_NULL(t.sessions);
  clearLinkList(&(t.sessions));
}


void test_addSessionToTable_given_table_add_s1_should_add(void){
  
  Table t = createTable();

  addSessionToTable(&t, &s1);
  TEST_ASSERT_EQUAL_PTR(&s1, t.sessions->data);
  TEST_ASSERT_NULL(t.sessions->next);
  clearLinkList(&(t.sessions));
}

void test_addSessionToTable_given_session_add_s1_s2_should_add(void){
  
  Table t = createTable();

  addSessionToTable(&t, &s1);
  addSessionToTable(&t, &s2);
  TEST_ASSERT_EQUAL_PTR(&s2, t.sessions->data);
  TEST_ASSERT_EQUAL_PTR(&s1, t.sessions->next->data);
  TEST_ASSERT_NULL(t.sessions->next->next);
  clearLinkList(&(t.sessions));
}

void test_addSessionToTable_given_session_add_s1_s2_s3_should_add(void){
  
  Table t = createTable();

  addSessionToTable(&t, &s1);
  addSessionToTable(&t, &s2);
  addSessionToTable(&t, &s3);
  TEST_ASSERT_EQUAL_PTR(&s3, t.sessions->data);
  TEST_ASSERT_EQUAL_PTR(&s2, t.sessions->next->data);
  TEST_ASSERT_EQUAL_PTR(&s1, t.sessions->next->next->data);
  TEST_ASSERT_NULL(t.sessions->next->next->next);
  clearLinkList(&(t.sessions));
}



