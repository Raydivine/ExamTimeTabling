#include "unity.h"
#include "CompareObjects.h"
#include "ExamStruct.h"
#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "TreeBalance.h"
#include "RedBlackTreeAdd.h"
#include "CustomAssertions.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node9;


Lecturer lectureList[] 
  = {   
      {.ID = 1001},  {.ID = 1002},  {.ID = 2001},  {.ID = 2002},
      {.ID = 3001},  {.ID = 3002},  {.ID = 4001},  {.ID = 4002},
      {.ID = 0001}
    };
  

void setUp(void)
{
  resetNode(&node1, &lectureList[0]); // ID = 1001
  resetNode(&node2, &lectureList[1]); // ID = 2002
  resetNode(&node3, &lectureList[2]); // ID = 2001
  resetNode(&node4, &lectureList[3]); // ID = 2002
  resetNode(&node5, &lectureList[4]); // ID = 3001
  resetNode(&node6, &lectureList[5]); // ID = 3002
  resetNode(&node7, &lectureList[6]); // ID = 4001
  resetNode(&node8, &lectureList[7]); // ID = 4002
  resetNode(&node9, &lectureList[8]); // ID = 0001
}

void tearDown(void)
{
}


/**
 *    Root              Root
 *    /	      --->      /
 *  NULL               1001
 */
void test_addRedBlackTree_given_RootNull_and_add_1001_to_Node(void){

	Node *root = NULL;
 
  addRedBlackTree(&root,	&node1, compareLecturersID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node1); 
	TEST_ASSERT_EQUAL_PTR(&lectureList[0], node1.data); 
}


/**
 *    Root    add5    Root
 *    /       --->   	/
 *  10(b)           10(b)
 *                  /
 *                5(r)
 */
void test_addRedBlackTree_add_5_tree_with_root_10(void){
  setNode(&node9, NULL, NULL, 'b');
	setNode(&node5 , NULL, NULL, 'r');

	Node *root = &node5;
	addRedBlackTree(&root,	&node9, compareLecturersID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
	TEST_ASSERT_EQUAL_NODE(&node9, NULL, 'b', &node5);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
  TEST_ASSERT_EQUAL_PTR(&lectureList[4], node5.data); 
  TEST_ASSERT_EQUAL_PTR(&lectureList[8], node9.data); 
}