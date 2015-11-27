#include "unity.h"
#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "Mutation.h"

void setUp(void){}

void tearDown(void){}


/** int isTheAdditionWillCauseOverFlow(int *currentNum, int addNum, int targetNum)
*
*   This function determine is (currentNum + addNum) will cause overflow compare to targetNum
*   The flow ratio is should not greater 20% of targetNum
*************************************************************************************************************
*   int sum = currentNum + addNum
*   int flowRatio =  (sum - targetNum)/targetNum * 100% 
*
*   if(flowRatio) < 20 , return 1 and perfrom addition (currentNum = currentNum + addNum);
*   else return 0
*/ 

void test_isTheAdditionWillCauseOverFlow_given_currentNum_0_addNum_10__targetNum_100_should_return_1_and_perform_addition(void){
  
  int currentNum = 0;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 10 , 100);
  TEST_ASSERT_EQUAL(1, ans);
  TEST_ASSERT_EQUAL(10, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_targetNum_0_should_return_0_because_will_cause_exception(void){
  
  int currentNum = 0;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 10 , 0);
  TEST_ASSERT_EQUAL(0, ans);
  TEST_ASSERT_EQUAL(0, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_currentNum_90_addNum_10_targetNum_100_should_return_1(void){
  
  int currentNum = 90;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 10 , 100);
  TEST_ASSERT_EQUAL(1, ans);
  TEST_ASSERT_EQUAL(100, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_currentNum_100_addNum_0_targetNum_100_should_return_1(void){
  
  int currentNum = 100;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 0 , 100);
  TEST_ASSERT_EQUAL(1, ans);
  TEST_ASSERT_EQUAL(100, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_currentNum_100_addNum_19_targetNum_100_should_return_1(void){
  
  int currentNum = 100;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 19 , 100);
  TEST_ASSERT_EQUAL(1, ans);
  TEST_ASSERT_EQUAL(119, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_currentNum_100_addNum_20_targetNum_100_should_return_0_and_remain_currentNum(void){
  
  int currentNum = 100;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 20 , 100);
  TEST_ASSERT_EQUAL(0, ans);
  TEST_ASSERT_EQUAL(100, currentNum);
}

void test_isTheAdditionWillCauseOverFlow_given_currentNum_100_addNum_50_targetNum_100_should_return_0_and_remain_currentNum(void){
  
  int currentNum = 100;
  
  int ans = isTheAdditionWillCauseOverFlow( &currentNum, 50 , 100);
  TEST_ASSERT_EQUAL(0, ans);
  TEST_ASSERT_EQUAL(100, currentNum);
}


