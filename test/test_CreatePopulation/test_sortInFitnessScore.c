#include "unity.h"
#include "CreatePopulation.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "SetElements.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "PaperListConvertion.h"
#include "Random.h"
#include "printfStructs.h"


void setUp(void){}

void tearDown(void){}


/**
*   void sortInFitnessScore( Table *population[])
*
*   Sort the poplation array in order of fitnessScore, the sorting aolgorithm is insertion sort
*
*/

void test_sortInFitnessScore_given_1_2_3_should_not_sort(void){
  Table t1,t2,t3;
  t1.fitnessScore = 1;
  t2.fitnessScore = 2;
  t3.fitnessScore = 3;
  
  Table *arr[3] = { &t1, &t2, &t3};
   
  sortInFitnessScore( arr, 3);
  TEST_ASSERT_EQUAL(1, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(2, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL(3, arr[2]->fitnessScore); 
}
  

void test_sortInFitnessScore_given_0_0_0_should_not_sort(void){
  Table t1,t2,t3;
  t1.fitnessScore = 0;
  t2.fitnessScore = 0;
  t3.fitnessScore = 0;
  
  Table *arr[3] = { &t1, &t2, &t3};
   
  sortInFitnessScore( arr, 3);
  TEST_ASSERT_EQUAL(0, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(0, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL(0, arr[2]->fitnessScore); 
}

void test_sortInFitnessScore_given_5_1_7_should_sort_to_1_5_7(void){
  Table t1,t2,t3;
  t1.fitnessScore = 5;
  t2.fitnessScore = 1;
  t3.fitnessScore = 7;
  
  Table *arr[3] = { &t1, &t2, &t3};
   
  sortInFitnessScore( arr, 3);
  TEST_ASSERT_EQUAL(1, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(5, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL(7, arr[2]->fitnessScore); 
}

void test_sortInFitnessScore_given_neg5_neg1_neg7_should_sort_to_neg7_neg5_neg1(void){
  Table t1,t2,t3;
  t1.fitnessScore = -5;
  t2.fitnessScore = -1;
  t3.fitnessScore = -7;
  
  Table *arr[3] = { &t1, &t2, &t3};
   
  sortInFitnessScore( arr, 3);
  TEST_ASSERT_EQUAL(-7, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(-5, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL(-1, arr[2]->fitnessScore); 
}

void test_sortInFitnessScore_given_neg5_neg7_3_should_sort_to_neg7_neg5_3(void){
  Table t1,t2,t3;
  t1.fitnessScore = -5;
  t2.fitnessScore = -7;
  t3.fitnessScore = 3;
  
  Table *arr[3] = { &t1, &t2, &t3};
   
  sortInFitnessScore( arr, 3);
  TEST_ASSERT_EQUAL(-7, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(-5, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL( 3, arr[2]->fitnessScore); 
}


void test_sortInFitnessScore_given_9_2_5_1_7_should_sort_to_1_2_5_7_9(void){
  Table t1,t2,t3,t4,t5;
  t1.fitnessScore = 9;
  t2.fitnessScore = 2;
  t3.fitnessScore = 5;
  t4.fitnessScore = 1;
  t5.fitnessScore = 7;
  
  Table *arr[5] = { &t1, &t2, &t3, &t4, &t5};
   
  sortInFitnessScore( arr, 5);
  TEST_ASSERT_EQUAL(1, arr[0]->fitnessScore);
  TEST_ASSERT_EQUAL(2, arr[1]->fitnessScore);
  TEST_ASSERT_EQUAL(5, arr[2]->fitnessScore); 
  TEST_ASSERT_EQUAL(7, arr[3]->fitnessScore); 
  TEST_ASSERT_EQUAL(9, arr[4]->fitnessScore); 
}
