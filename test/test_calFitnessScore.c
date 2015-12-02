#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Session s1,s2,s3,s4,s5,s6;

void setUp(void){
  s1 = createSessionWithConflict(1);
  s2 = createSessionWithConflict(2);
  s3 = createSessionWithConflict(3);
  s4 = createSessionWithConflict(4);
  s5 = createSessionWithConflict(5);
  s6 = createSessionWithConflict(6);
}
void tearDown(void){}

void test_calFitnessScore_given_sessions_NULL_should_get0(void){
	LinkedList *sList = NULL;
  
  int ans = calFitnessScore(sList);
  TEST_ASSERT_EQUAL(0,ans);
  
  clearLinkList(&sList); 
}

void test_calFitnessScore_given_sessions_s1_should_get1(void){
	LinkedList *sList = linkListNew(&s1);
  
  int ans = calFitnessScore(sList);
  TEST_ASSERT_EQUAL(1,ans);
  
  clearLinkList(&sList); 
}

void test_calFitnessScore_given_sessions_s1s2s3_should_get6(void){
	LinkedList *sList = linkListNew(&s1);
  addDataToHead(&sList, &s2);
  addDataToHead(&sList, &s3);
  
  int ans = calFitnessScore(sList);
  TEST_ASSERT_EQUAL(6,ans);
  
  clearLinkList(&sList); 
}

void test_calFitnessScore_given_sessions_s1s2s3s4s5s6_should_get6(void){
	LinkedList *sList = linkListNew(&s1);
  addDataToHead(&sList, &s2);
  addDataToHead(&sList, &s3);
  addDataToHead(&sList, &s4);
  addDataToHead(&sList, &s5);
  addDataToHead(&sList, &s6);
  
  int ans = calFitnessScore(sList);
  TEST_ASSERT_EQUAL(21,ans);
  
  clearLinkList(&sList); 
}