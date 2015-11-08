#include "unity.h"
#include "ExamStruct.h"

#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "TreeBalance.h"
#include "CompareObjects.h"
#include "RedBlackTreeAdd.h"
#include "CustomAssertions.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node9;


Lecturer lectureList[] 
  = {   
      {.ID = 1001},  {.ID = 1002},  {.ID = 2001},  {.ID = 2002},
      {.ID = 3001},  {.ID = 3002},  {.ID = 4001},  {.ID = 4002},
      {.ID = 5001}
    };

void setUp(void)
{
  resetNode(&node1, &lectureList[0] );
  resetNode(&node2, &lectureList[1] );
  resetNode(&node3, &lectureList[2] );
  resetNode(&node4, &lectureList[3] );
  resetNode(&node5, &lectureList[4] );
  resetNode(&node6, &lectureList[5] );
  resetNode(&node7, &lectureList[6] );
  resetNode(&node8, &lectureList[7] );
  resetNode(&node9, &lectureList[8] );
}

void tearDown(void)
{
}

/**
 *    Root    add10     Root
 *    /	      --->      /
 *  NULL               1
 */
void test_addRedBlackTree_given_RootNull_and_add_node1_to_Node(void){

	Node *root = NULL;
 
  addRedBlackTree(&root,	&node1, compareLecturersID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node1); 
	TEST_ASSERT_EQUAL_PTR(&lectureList[0], node1.data); 
}

/** 2-node case
 *                 add 1
 * root -> 1(b)  -------> Throw ERR_EQUIVALENT_NODE
 */
void test_addRedBlackTree_add_1_to_use_tree_with_only_root_1_should_throw_ERR_EQUIVALENT_NODE(void)
{
  CEXCEPTION_T err;
  Node *root = &node1;

  Try{
    addRedBlackTree(&root,	&node1, compareLecturersID);
    TEST_FAIL_MESSAGE("Expected ERR_EQUIVALENT_NODE to be thrown. But receive none");
  } Catch(err)
    {
      TEST_ASSERT_EQUAL_PTR(&node1, root);
      TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
    }
}


/**
 *    Root    add5    Root
 *    /       --->   	/
 *  8(b)             8(b)
 *                  /
 *                5(b)
 */
void test_addRedBlackTree_add_5_tree_with_root_8(void){


	Node *root = &node8;
	addRedBlackTree(&root,	&node5, compareLecturersID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node8);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node8);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_PTR(&lectureList[4], node5.data); 
  TEST_ASSERT_EQUAL_PTR(&lectureList[7], node8.data); 
}

/**
 * 		Root								Root 								 		Root
 *		 |					   			|													|
 *		V				 add9				V 			flip color			  V
 *	 4(b)	   ------->    4[b]			-------->				4(b)
 *  /		\           		/		\										 /	 \
 * 3[r]	7[r]					3[r]	7[r]							3[b]   7[b]
 *														\												\
 *														9[r]										9[r]
 */
void test_addRedBlackTree_add_9_should_flip_color(void){
	setNode(&node3, NULL  , NULL, 'r');
	setNode(&node7, NULL  , NULL, 'r');
	setNode(&node9, NULL  , NULL, 'r');
	setNode(&node4, &node3, &node7, 'b');

	Node *root = &node4;
	addRedBlackTree(&root,	&node9, compareLecturersID);
  TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node3, &node7, 'b', &node4);
	TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node7);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node9);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_PTR(&lectureList[3], node4.data); 
  TEST_ASSERT_EQUAL_PTR(&lectureList[2], node3.data); 
  TEST_ASSERT_EQUAL_PTR(&lectureList[6], node7.data); 
  TEST_ASSERT_EQUAL_PTR(&lectureList[8], node9.data); 
}
