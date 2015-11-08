#include "unity.h"
#include "ExamStruct.h"

#include "Node.h"
#include "InitNode.h"
#include "TreeBalance.h"
#include "Rotations.h"
#include "RedBlackTreeAdd.h"
#include "CustomAssertions.h"
#include "CompareObjects.h"
#include "ErrorCode.h"
#include "CException.h"


Programme programmeList[] 
 = {
      { .name= "FS1"  , .studentNum = 10},
      { .name= "FS2"  , .studentNum = 20},
      { .name= "FS3"  , .studentNum = 30},
      { .name= "PR1"  , .studentNum = 40},
      { .name= "PR2"  , .studentNum = 40},
      { .name= "PR3"  , .studentNum = 50}
   };
   
Node node1, node2, node3, node4, node5, node6;  

void setUp(void)
{
  resetNode(&node1, &programmeList[0] );
  resetNode(&node2, &programmeList[1] );
  resetNode(&node3, &programmeList[2] );
  resetNode(&node4, &programmeList[3] );
  resetNode(&node5, &programmeList[4] );
  resetNode(&node6, &programmeList[5] );
}

void tearDown(void)
{
}

/**
*    The general addRedBlackTree() is small value to the left,  right value to the right,
*    if the value to add is same as the Node should throw error
*    The programme node's value is the studentNum and different programme may have same studentNum
*    So if the node with same studentNum add to the tree, it will add to the leftChild
*/



/**
 *    Root    add10     Root
 *    /	      --->      /
 *  NULL               10
 */
void test_addRedBlackTree_given_RootNull_and_add_10_to_Node(void){

	Node *root = NULL;
 
  addRedBlackTree(&root,	&node1, compareStudentsNumber);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node1); 
	TEST_ASSERT_EQUAL_PTR(&programmeList[0], node1.data); 
}

/**
 *    Root    add 20                 Root
 *    /	      ------------>           /
 *  30                               30
 *                                  / 
 *                                20  
 *                               
 *                              
 */
void test_addRedBlackTree_given_root_is_30_and_add_20_to_Node(void){

	Node *root = &node3;
 
  addRedBlackTree(&root,	&node2, compareStudentsNumber);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node3); 
  TEST_ASSERT_EQUAL_NODE(&node2, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL , 'b', &node2);
}

/**
 *           Root         add 40               Root             
 *           /	      ------------>             /        
 *          40                                40                    
 *            \                              /  \                  
 *            50                           40    50               
 *                                                                                                                 
 */
void test_addRedBlackTree_given_40_is_in_tree_and_add_40_should_add_to_left(void){

  setNode(&node4 , NULL , &node6  , 'b');


	Node *root = &node4;
  addRedBlackTree(&root,	&node5, compareStudentsNumber);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node4); 
  TEST_ASSERT_EQUAL_NODE(&node5, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
  TEST_ASSERT_EQUAL_PTR(&programmeList[3], node4.data); 
  TEST_ASSERT_EQUAL_PTR(&programmeList[4], node5.data);  
}

/**
 *           Root         add 40               Root                   Root
 *           /	      ------------>             /         ---->        /
 *          40                                40                     40
 *         /  \                              /  \                   / \
 *       30     50                         40    50               30   50
 *      /                                 /                      / \
 *   20                                 30                      20  40
 *  /                                   /                      /
 * 10                                 20                      10
 *                                    /
 *                                  10
 *
 */
void test_addRedBlackTree_given_40_is_in_tree_and_add_40_should_add_to_left_then_rotate(void){

  setNode(&node4 , &node3 , &node6  , 'b');
  setNode(&node3 , &node2 , NULL  , 'b');
  setNode(&node2 , &node1 , NULL  , 'b');

	Node *root = &node4;
 
  addRedBlackTree(&root,	&node5, compareStudentsNumber);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node4); 
  TEST_ASSERT_EQUAL_NODE(&node3, &node6, 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(&node2, &node5, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}
