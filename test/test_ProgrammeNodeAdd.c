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
*    But this project has to add same value to the tree,
*    so the addRedBlackTree() is changed, the same value will add to the left
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
