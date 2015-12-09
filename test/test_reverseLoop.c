#include "unity.h"
#include "PaperListConvertion.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"

#define HEAD  pList
#define HEAD1 pList->next
#define HEAD2 pList->next->next
#define HEAD3 pList->next->next->next
#define HEAD4 pList->next->next->next->next
#define HEAD5 pList->next->next->next->next->next
#define HEAD6 pList->next->next->next->next->next->next
#define HEAD7 pList->next->next->next->next->next->next->next
#define HEAD8 pList->next->next->next->next->next->next->next->next
#define HEAD9 pList->next->next->next->next->next->next->next->next->next


Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *pList;

void setUp(void){
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
}

void tearDown(void){
  clearLinkLoop(&pList);
}

/** void reverseLoop(LinkedList **loop)
  *
  *  loop is a linkedlist of looped, this function will reverse the loop,
  *  
  *  The purpose reverse the loop is for crossover,
  *  1st loop go to left direction
  *  2nd loop go to right direction
  *
  * This function will be call in crossover() to reverse the first loop,
  * so the first loop can go to left direction
  * 
*/


void test_reverseLoop_given_null_should_just_return(void){
  pList = NULL;

  reverseLoop(&pList);
  TEST_ASSERT_NULL(HEAD);
}

void test_reverseLoop_given_p1_only_should_do_nothing(void){
  pList = linkListNew(&p1);
  pList->next = pList;

  reverseLoop(&pList);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
}



/**           
  *     p1p2
  *
  *------------OUTPUT------------
  *
  *    p1p2 ( output is still p1p2, becase only got 2 element, their next is each other)
*/
void test_reverseLoop_given_p1p2_should_still_form_p1p2(void){
  pList = linkListNew(&p2);
  addDataToHead( &pList, &p1);
  listToLoop(&pList);
  
  reverseLoop(&pList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_NOT_NULL(HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD3->data);
}

/**           
  *  p3--->p1p2p3-->p1     ( the previous node of p1 is p3)
  *
  *------------OUTPUT------------
  *
  *    p1p3p2-->p1  ( The head still is p1, and p1 point to its previous node, the loop is reversed)
*/
void test_reverseLoop_given_p1p2p3_should_still_form_p1p3p2(void){

  pList = linkListNew(&p3);
  addDataToHead( &pList, &p2);
  addDataToHead( &pList, &p1);
  listToLoop(&pList);
  
  reverseLoop(&pList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD2->data);
  TEST_ASSERT_NOT_NULL(HEAD3);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD5->data);
}


/**           
  *     p1p2p3p4-->p1
  *
  *------------OUTPUT------------
  *
  *    p1p4p3p2-->p1  
*/
void test_reverseLoop_given_p1p2p3p4_should_form_p1p4p3p2(void){

  pList = linkListNew(&p4);
  addDataToHead( &pList, &p3);
  addDataToHead( &pList, &p2);
  addDataToHead( &pList, &p1);
  listToLoop(&pList);
  
  reverseLoop(&pList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD3->data);
  
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD7->data);
}


/**           
  *     p1p2p3p4p5p6p7p8-->p1
  *
  *------------OUTPUT------------
  *
  *    p1p8p7p6p5p4p3p2-->p1  
*/
void test_reverseLoop_given_p1p2p3p4p5p6p7p8_should_form_p1p8p7p6p5p4p3p2(void){

  pList = linkListNew(&p8);
  addDataToHead( &pList, &p7);
  addDataToHead( &pList, &p6);
  addDataToHead( &pList, &p5);
  addDataToHead( &pList, &p4);
  addDataToHead( &pList, &p3);
  addDataToHead( &pList, &p2);
  addDataToHead( &pList, &p1);
  listToLoop(&pList);
  
  reverseLoop(&pList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p8, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p7, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p6, HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p5, HEAD4->data);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD5->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD6->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD7->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD8->data);
}