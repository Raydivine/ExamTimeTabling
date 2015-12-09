#include "unity.h"
#include "Crossover.h"
#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"

#define HEAD  child
#define HEAD1 child->next
#define HEAD2 child->next->next
#define HEAD3 child->next->next->next
#define HEAD4 child->next->next->next->next
#define HEAD5 child->next->next->next->next->next
#define HEAD6 child->next->next->next->next->next->next
#define HEAD7 child->next->next->next->next->next->next->next
#define HEAD8 child->next->next->next->next->next->next->next->next
#define HEAD9 child->next->next->next->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *pListA, *pListB, *child;

void setUp(void){
  child = NULL;
  
  setPaper(&p1 ,"p1");
  setPaper(&p2 ,"p2");
  setPaper(&p3 ,"p3");
  setPaper(&p4 ,"p4");
  setPaper(&p5 ,"p5");
  setPaper(&p6 ,"p6");
  setPaper(&p7 ,"p7");
  setPaper(&p8 ,"p8");
  setPaper(&p9 ,"p9");
  setPaper(&p10, "p10");
  
  pListA = linkListNew(&p8);
  addDataToHead( &pListA, &p7);
  addDataToHead( &pListA, &p6);
  addDataToHead( &pListA, &p5);
  addDataToHead( &pListA, &p4);
  addDataToHead( &pListA, &p3);
  addDataToHead( &pListA, &p2);
  addDataToHead( &pListA, &p1);
  listToLoop(&pListA);
  
/**  pListA is shared structure for all test 
 *  
 *  pListA : 1    2   3   4   5   6   7   8
*/ 
}

void tearDown(void){
  clearLinkLoop(&pListA);
  clearLinkLoop(&pListB);
}

/**  LinkedList *buildChildList(void *mid, LinkedList *listA, LinkedList *listB)
  *
  *  this function will build a child list by using "Greedy Subtour Crossover" concept
  *  listA and listB are the 2 chromosome , they are Looped linkedlist, 
  *  mid is the middle point to do crossover, 
  *  
  *  The 2 chromosome has done preset before pass in to this function
  *  1. Their head already point to the mid, which is the starting point to do crossover
  *  2. listA is reversed by using reverseLoop(), so its direction will go to left,  while listB is go to right
  *
  *  Input condition:
  *  the head of listA and listB has pointed mid, 
  *  mid also has to be the head of them 
  *
  *
*/


/**                
  *  pListA : p1   p2   p3   p4   p5   p6   p7   p8
  *
  *              
  *  pListB : p1   p2   p3   p4   p5   p6   p7   p8
  *              break
  *
  *
  *--- ---------OUTPUT------------
  *
  * child :  p2   p1    p3   p4   p5   p6   p7   p8
*/
void test_buildChildTable_given_the_listAlistB_are_same_order_should_break_at_plistB_p2(void){
  pListB = linkListNew(&p8);
  addDataToHead( &pListB, &p7);
  addDataToHead( &pListB, &p6);
  addDataToHead( &pListB, &p5);
  addDataToHead( &pListB, &p4);
  addDataToHead( &pListB, &p3);
  addDataToHead( &pListB, &p2);
  addDataToHead( &pListB, &p1);
  listToLoop(&pListB);
  
  child = buildChildList( &p1, pListA->next, pListB->next);   // because head of listA,B are p1, so just point to the next
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD7->data);
  TEST_ASSERT_NULL(HEAD8);
  
  clearLinkList(&child);
}