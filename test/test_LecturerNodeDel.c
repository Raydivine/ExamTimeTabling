#include "unity.h"
#include "CompareObjects.h"
#include "ExamStruct.h"

#include "Node.h"
#include "InitNode.h"
#include "Rotations.h"
#include "CaseSelect.h"
#include "CaseHandle.h"
#include "TreeBalance.h"
#include "TreeChecking.h"
#include "RedBlackTreeDel.h"
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
 *      Root
 *        |     remove2
 *       v     ------> Throw ERR_NODE_UNAVAIBLE
 *      1[b]
 */
void test_delRedBlackTree_given_remove_2_from_should_throw_error(void){
  CEXCEPTION_T err;
  setNode(&node1, NULL	, NULL, 'b');
  setNode(&node2, NULL	, NULL, 'b');

  Node *root = &node1;
  Try{
    delRedBlackTree( &root, &node2, compareLecturersID);
    TEST_FAIL_MESSAGE("Expected ERR_NODE_UNAVAIBLE");
  }Catch(err){
    TEST_ASSERT_EQUAL_MESSAGE(ERR_NODE_UNAVAIBLE, err, "Expected ERR_NODE_UNAVAIBLE");
  }
}

/**
 *      Root                Root
 *        |                  |
 *       v      remove1     v
 *      1[b]   ------>      NULL
 */
void test_delRedBlackTree_given_remove_1_from_with_root_1(void){
  setNode(&node1, NULL, NULL, 'b');
  Node *root = &node1, *node;

  node = delRedBlackTree( &root, &node1, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(node , &node1);
  TEST_ASSERT_NULL(root);
}

/**
 *            Root                Root
 *            |                    |
 *            v                    v
 *          2(b)                 2(b)
 *         /         ---->
 *       1(r)       remove 1
 */
void test_delRedBlackTree_remove_1_from_tree_with_root_2(void) {
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node2, &node1, NULL, 'b');
  Node *root, *node;
  root = &node2;

  node = delRedBlackTree(&root, &node1, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(&node1, node);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node2);
}

/**2-node case
 *            Root                    Root
 *            |                       |
 *            v                       v
 *          1(b)                     1(b)
 *              \         ---->
 *               5(r)   remove 5
 */
void test_delRedBlackTree_remove_5_from_tree_with_root_1(void) {
  setNode(&node5, NULL, NULL, 'r');
  setNode(&node1, NULL, &node5, 'b');
  Node *root, *node;
  root = &node1;

  node = delRedBlackTree(&root, &node5, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(&node5, node);
  TEST_ASSERT_EQUAL_PTR(root, &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
}

/**
 *      Root                Root
 *        |                  |
 *       v      remove4      v
 *      5[b]   ------>      5[b]
 *     /   \                  \
 *  4[b]    9[b]              9[b]
 */
void test_delRedBlackTree_given_remove_4_from_with_root_5(void){
  setNode(&node4, NULL,   NULL, 'b');
  setNode(&node9, NULL,   NULL, 'b');
  setNode(&node5, &node4, &node9, 'b');
  Node *root = &node5, *node;

  node = delRedBlackTree(&root, &node4, compareLecturersID);
  TEST_ASSERT_NOT_NULL(root);
  TEST_ASSERT_EQUAL(root, &node5);
  TEST_ASSERT_EQUAL(node5.right, &node9);
  TEST_ASSERT_NULL(node5.left);
  TEST_ASSERT_EQUAL_PTR(node , &node4);
}

/**
 *            Root                        Root
 *            |                           |
 *            v                           v
 *          2(b)                        2(b)
 *         /    \         ---->         /
 *      1(r)     3(r)   remove 3      1(r)
 */
void test_delRedBlackTree_remove_3_from_tree_with_root_2_and_two_child(void) {
  setNode(&node1, NULL, NULL, 'r');
  setNode(&node3, NULL, NULL, 'r');
  setNode(&node2, &node1, &node3, 'b');
  Node *root, *node;
  root = &node2;

  node = delRedBlackTree(&root, &node3, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(&node3, node);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, NULL, 'b', &node2);
}

/**
 *            Root                              Root
 *            |                                   |
 *            v                                   v
 *          2(b)                                5(b)
 *         /    \           ---->             /     \
 *      1(b)     5(r)     remove 1        2(b)       6(b)
 *              /    \                       \
 *          3(b)      6(b)                    3(r)
 */
void test_delRedBlackTreexx_remove_1_rotateLeft_and_flip_color_with_3_parents_and_2_childs(void) {
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node6, NULL, NULL, 'b');
  setNode(&node5, &node3, &node6, 'r');
  setNode(&node2, &node1, &node5, 'b');
  Node *root, *node;
  root = &node2;
  
  node = delRedBlackTree(&root, &node1, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(&node1, node);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, &node3, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node6);
}

/**
 *               Root                               Root
 *                |                                  |
 *                v                                  v
 *              5(b)                               2(b)
 *            /    \           ---->             /     \
 *          2(r)    8(b)     remove 8        1(b)       5(b)
 *        /    \                                      /
 *    1(b)      3(b)                              3(r)
 */
void test_delRedBlackTreexx_remove_8_rotateRight_and_flip_color_with_3_parents_and_2_childs(void) {
  setNode(&node1, NULL, NULL, 'b');
  setNode(&node3, NULL, NULL, 'b');
  setNode(&node2, &node1, &node3, 'r');
  setNode(&node8, NULL, NULL, 'b');
  setNode(&node5, &node2, &node8, 'b');
  Node *root, *node;
  root = &node5;

  node = delRedBlackTree(&root, &node8, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(&node8, node);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
  TEST_ASSERT_EQUAL_NODE(&node1, &node5, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(&node3, NULL, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node3);
}

// CASE 1(b) Full
/**        Root                     Root                  Root
 *           |                        |                     |
 *          v                         v                     v
 *         4(r)                     4(r)                  7(r)
 *        /    \      remove 3    //    \     rotate      /   \
 *      3(b)  9(b)  ---------->       9(b)  ---------> 4(b)   9(b)
 *           /                       /
 *         7[r]                     7[r]
 */
void test_delRedBlackTree_remove_3_from_tree_should_rotate_and_and_new_root_should_change_to_b_color(void){
  setNode(&node3 , NULL  , NULL   , 'b');
  setNode(&node7 , NULL  , NULL   , 'r');
  setNode(&node9 , &node7, NULL   , 'b');
  setNode(&node4 , &node3, &node9 , 'r');
  Node *root = &node4, *node;

  node = delRedBlackTree(&root, &node3, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(node, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node7);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(&node4, &node9, 'b', &node7);
}

// CASE 1(c)  Full
/**        Root                     Root                    Root
 *           |                        |                       |
 *          v                         v                       v
 *         4(r)                     4(r)                    3(b)
 *        /    \      remove 9     /    \\        rotate    /   \
 *      3(b)  9(b)  ---------->  3(b)       --------->   2(b)   4(b)
 *      /                       /
 *     2[r]                    2[r]
 */
void test_delRedBlackTree_remove_9_from_tree_should_rotate_and_and_new_root_should_change_to_b_color(void){
  setNode(&node2 , NULL  , NULL   , 'r');
  setNode(&node3 , &node2, NULL   , 'b');
  setNode(&node9 , NULL  , NULL   , 'b');
  setNode(&node4 , &node3, &node9 , 'r');
  Node *root = &node4, *node;

  node = delRedBlackTree(&root, &node9, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(node, &node9);
  TEST_ASSERT_EQUAL_PTR(root, &node3);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node4);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node2);
}

/**        Root                     Root                    Root
 *           |                        |                       |
 *          v                         v                       v
 *         5(r)                     5(r)                    4(b)
 *        /    \      remove 9     /    \\        rotate    /   \
 *      3(b)  9(b)  ---------->  3(b)       --------->   3(b)   5(b)
 *        \                        \
 *        4[r]                    4[r]
 */
void test_delRedBlackTree_remove_9_from_tree_should_letf_right_rotate_and_and_new_root_should_change_to_b_color(void){
  setNode(&node4 , NULL  , NULL   , 'r');
  setNode(&node3 , NULL  , &node4 , 'b');
  setNode(&node9 , NULL  , NULL   , 'b');
  setNode(&node5 , &node3, &node9 , 'r');
  Node *root = &node5, *node;

  node = delRedBlackTree(&root, &node9, compareLecturersID);
  TEST_ASSERT_EQUAL_PTR(node, &node9);
  TEST_ASSERT_EQUAL_PTR(root, &node4);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL  , NULL  , 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node3, &node5, 'b', &node4);
}
