#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Programme c1,c2,c3,c4,c5,c6,c7;

void setUp(void)
{
//void setProgramme(Programme *target ,char *programmeName, int numStudent)
  setProgramme(&c1 ,"c1", 30);
  setProgramme(&c2 ,"c2", 50);
  setProgramme(&c3 ,"c3", 60);
}

void tearDown(void){}

/**
*     struct Paper{
          char *code;               = A
          int takersNum;            = 0
          LinkedList *programmes;   = NULL
      };
*/
void test_setPaper_should_set_the_code_and_0_takers_and_empty_programmes(void){
  Paper paperA;
  
  setPaper(&paperA ,"A");
  TEST_ASSERT_EQUAL(0, paperA.takersNum);
  TEST_ASSERT_NULL(paperA.programmes);
}

void test_addProgrammeToPaper_given_paperA_add_c1_should_have_takers_equal_30(void){
  Paper paperA;
  setPaper(&paperA ,"A");

  addProgrammeToPaper(&paperA, &c1);
  TEST_ASSERT_EQUAL(30, paperA.takersNum);
  TEST_ASSERT_EQUAL_PTR(&c1, paperA.programmes->data);
  TEST_ASSERT_NULL(paperA.programmes->next);
  clearLinkList(&(paperA.programmes));
}

/**
*
*   30+50 = 80
*/
void test_addProgrammeToPaper_given_paperA_add_c1_C2_should_have_takers_equal_80(void){
  Paper paperA;
  setPaper(&paperA ,"A");

  addProgrammeToPaper(&paperA, &c1);
  addProgrammeToPaper(&paperA, &c2);
  TEST_ASSERT_EQUAL(80, paperA.takersNum);
  TEST_ASSERT_EQUAL_PTR(&c2, paperA.programmes->data);
  TEST_ASSERT_EQUAL_PTR(&c1, paperA.programmes->next->data);
  TEST_ASSERT_NULL(paperA.programmes->next->next);
  clearLinkList(&(paperA.programmes));
}

/**
*
*   30+50+60= 140
*/
void test_addProgrammeToPaper_given_paperA_add_c1_c2_c3_should_have_takers_equal_140(void){
  Paper paperA;
  setPaper(&paperA ,"A");

  addProgrammeToPaper(&paperA, &c1);
  addProgrammeToPaper(&paperA, &c2);
  addProgrammeToPaper(&paperA, &c3);
  TEST_ASSERT_EQUAL( 140, paperA.takersNum);
  TEST_ASSERT_EQUAL_PTR(&c3, paperA.programmes->data);
  TEST_ASSERT_EQUAL_PTR(&c2, paperA.programmes->next->data);
  TEST_ASSERT_EQUAL_PTR(&c1, paperA.programmes->next->next->data);
  TEST_ASSERT_NULL(paperA.programmes->next->next->next);
  clearLinkList(&(paperA.programmes));
}


