#include "unity.h"
#include "CompareObjects.h"
#include "ExamStruct.h"
#include "Node.h"
#include "InitNode.h"

Programme programmeList[] 
 = {
      { .name= "FS1"  , .studentNum = 10},
      { .name= "FS2"  , .studentNum = 20},
      { .name= "FS3"  , .studentNum = 30},
      { .name= "PR1"  , .studentNum = 30},
   };
   
Node node1, node2, node3, node4;  

void setUp(void)
{
  resetNode(&node1, &programmeList[0] ); //programme1
  resetNode(&node2, &programmeList[1] ); //programme2
  resetNode(&node3, &programmeList[2] ); //programme3
  resetNode(&node4, &programmeList[3] ); //programme4
}

void tearDown(void)
{
}

/**   compareStudentsNumber(nodeA, nodeB), 
*     
*     if (nodeB.studentNum is > nodeA.studentNum )
*         return 1;
*     else
*         return -1;
*/

void test_compareStudentsNumber_given_programme2_compare_programme3_should_return_1_becuz_programme3_studentNum_is_bigger(void){

  int ans = compareStudentsNumber(node2.data, node3.data);
  TEST_ASSERT_EQUAL(1,ans);
}

void test_compareStudentsNumber_given_programme2_compare_programme1_should_return_minus1_becuz_programme1_studentNum_is_smaller(void){

  int ans = compareStudentsNumber(node2.data, node1.data);
  TEST_ASSERT_EQUAL(-1,ans);
}

void test_compareStudentsNumber_given_programme3_compare_programme4_should_return_minus1_However_they_are_equal(void){

 int ans = compareStudentsNumber(node3.data, node4.data);
 TEST_ASSERT_EQUAL(-1,ans);
}

