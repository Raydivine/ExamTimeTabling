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
//  clearLinkLoop(&pList);
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





/** 
  *          
  *     p1p2
  *
  *------------OUTPUT------------
  *
  *    p1p2 ( output is still p1p2, becase only got 2 element, their next is each other)
  *
*/
void test_reverseLoop_given_p1p2_should_still_form_p1p2(void){

  pList = linkListNew(&p2);
  addDataToHead( &pList, &p1);

  
  listToLoop(&pList);
  
  
 // reverseLoop(&pList);
  TEST_ASSERT_NOT_NULL(HEAD);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_NOT_NULL(HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
}

