#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4,p5,p6;
Programme c1,c2,c3,c4,c5,c6;

Session session;

void setUp(void)
{
  LinkedList *testersP1 = linkListNew(&c1);
  addDataToHead(&testersP1, &c2);
  setPaper(&p1, "p1", &testersP1);
  
  LinkedList *testersP2 = linkListNew(&c2);
  addDataToHead(&testersP2, &c3);
  setPaper(&p2, "p2", &testersP2);
  
  LinkedList *testersP3 = linkListNew(&c3);
  addDataToHead(&testersP3, &c4);
  setPaper(&p3, "p3", &testersP3);
  
  LinkedList *testersP4 = linkListNew(&c4);
  addDataToHead(&testersP4, &c5);
  setPaper(&p4, "p4", &testersP4);
  
  LinkedList *testersP5 = linkListNew(&c5);
  addDataToHead(&testersP5, &c6);
  setPaper(&p5, "p5", &testersP5);
  
  LinkedList *testersP6 = linkListNew(&c6);
  addDataToHead(&testersP6, &c1);
  setPaper(&p6, "p6", &testersP6);
  
}

void tearDown(void){}

void test_isPapersHaveSameProgramme_given_p1_p3_which_no_same_Programme_should_return0(void)
{
	int ans = isPapersHaveSameProgramme(&p1, &p2);
  TEST_ASSERT_EQUAL(0, ans);
}

void test_isPapersHaveSameProgramme_given_p1_p2_which_have_same_Programme_should_return1(void)
{
	int ans = isPapersHaveSameProgramme(&p1, &p2);
  TEST_ASSERT_EQUAL(1, ans);
}

