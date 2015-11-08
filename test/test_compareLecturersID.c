#include "unity.h"
#include "CompareObjects.h"
#include "ExamStruct.h"
#include "Node.h"
#include "InitNode.h"

Node node1, node2, node3, node4;

Lecturer lecturerList[] 
  = {   
      {.ID = 1},  {.ID = 2},  {.ID = 3},  {.ID = 3},  
    };


void setUp(void)
{
  resetNode(&node1, &lecturerList[0]); // lecturer1
  resetNode(&node2, &lecturerList[1]); // lecturer2
  resetNode(&node3, &lecturerList[2]); // lecturer3
  resetNode(&node4, &lecturerList[3]); // lecturer3
}

void tearDown(void)
{
}

void test_compareLecturersID_given_lecturer2_compare_lecturer3_should_return_1_becuz_lecturer3_ID_is_bigger(void){

  int ans = compareLecturersID(node2.data, node3.data);
  TEST_ASSERT_EQUAL(1,ans);
}

void test_compareLecturersID_given_lecturer2_compare_lecturer1_should_return_minus1_becuz_lecturer1_ID_is_smaller(void){

  int ans = compareLecturersID(node2.data, node1.data);
  TEST_ASSERT_EQUAL(-1,ans);
}

void test_compareLecturersID_given_lecturer3_compare_lecturer4_should_return_0_becuz_their_ID_are_same(void){

 int ans = compareLecturersID(node3.data, node4.data);
 TEST_ASSERT_EQUAL(0,ans);
}

