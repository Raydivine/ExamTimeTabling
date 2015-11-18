#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4;
Programme c1,c2,c3,c4,c5,c6,c7,c8;

LinkedList *paperList;

void setUp(void)
{
  LinkedList *testersP1 = linkListNew(&c1);
  addDataToHead(&testersP1, &c2);
  setPaper(&p1, "p1", &testersP1);
  
  LinkedList *testersP2 = linkListNew(&c3);
  addDataToHead(&testersP2, &c4);
  setPaper(&p2, "p2", &testersP2);
  
  LinkedList *testersP3 = linkListNew(&c4);
  addDataToHead(&testersP3, &c5);
  setPaper(&p3, "p3", &testersP3);
  
  LinkedList *paperList = linkListNew(&p1);
  addDataToHead(&paperList, &p2);
  addDataToHead(&paperList, &p3);
  
  /**
  *                               PaperList
  * Papers                  :    p1              p2              p3
  * programmes taking       :  c1,c2            c3,c4          c5,c6
  *
  */
}

void tearDown(void){}

/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c7,c8    |       c1,c2            c3,c4          c5,c6
 *
 *                               (no conflict)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c7_c8_which_no_confict_with_paperList_should_get0(void){
  LinkedList *testersP4 = linkListNew(&c7);
  addDataToHead(&testersP4, &c8);
  setPaper(&p4, "p4", &testersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(0, ans);
  
  clearLinkList(&testersP4);
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c1,c2    |       c1,c2            c3,c4          c5,c6
 *
 *                               (no conflict)
*/
// void xtest_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c8_which_have_1_confict_with_paperList_should_get1(void){
  // LinkedList *testersP4 = linkListNew(&c1);
  // addDataToHead(&testersP4, &c2);
  // setPaper(&p4, "p4", &testersP4);
  
  // int conflict = calConflictFromPaperToPaparList( &p4, paperList);
  // TEXT_ASSERT_EQUAL(1, conflict);
  
// }