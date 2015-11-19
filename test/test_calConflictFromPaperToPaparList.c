#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4;
Programme c1,c2,c3,c4,c5,c6,c7,c8;

LinkedList *takersP1, *takersP2, *takersP3;
LinkedList *paperList;

void setUp(void){
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  
  takersP1 = linkListNew(&c1);
  addDataToHead(&takersP1, &c2);
  setPaper(&p1, "p1", takersP1);
  
  takersP2 = linkListNew(&c3);
  addDataToHead(&takersP2, &c4);
  setPaper(&p2, "p2", takersP2);
  
  takersP3 = linkListNew(&c4);
  addDataToHead(&takersP3, &c5);
  setPaper(&p3, "p3", takersP3);
  
  paperList = linkListNew(&p1);
  addDataToHead(&paperList, &p2);
  addDataToHead(&paperList, &p3);
  
 /**
 *                                 PaperList
 * Papers                  :   p1              p2              p3
 * programmes taking       : c1,c2            c3,c4          c5,c6
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
  
  LinkedList *takersP4 = linkListNew(&c7);
  addDataToHead(&takersP4, &c8);
  setPaper(&p4, "p4", takersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(0, ans);
  
  clearLinkList(&takersP4);
}


/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c1,c8    |       c1,c2            c3,c4          c5,c6
 *                            -               -
 *                               (1 conflict)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c8_have_1_confict_with_paperList_should_get1(void){
  
  LinkedList *takersP4 = linkListNew(&c1);
  addDataToHead(&takersP4, &c8);
  setPaper(&p4, "p4", takersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(1, ans);

  clearLinkList(&takersP4);
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c1,c2    |       c1,c2            c3,c4          c5,c6
 *                            -  -             -   -
 *                               (1 conflict, however there is 2 same programmes, but they are same paper)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_have_1_confict_with_paperList_should_get1(void){
  
  LinkedList *takersP4 = linkListNew(&c1);
  addDataToHead(&takersP4, &c2);
  setPaper(&p4, "p4", takersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(1, ans);
   
  clearLinkList(&takersP4);
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4        |          p1              p2              p3
 * programmes taking       :  c1,c2,c3    |       c1,c2            c3,c4          c5,c6
 *                            -  -  -             -   -            -
 *                               (2 conflict, p4 conflict with p1 and p2)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_c3_have_2_confict_with_paperList_should_get2(void){
  
  LinkedList *takersP4 = linkListNew(&c1);
  addDataToHead(&takersP4, &c2);
  addDataToHead(&takersP4, &c3);
  setPaper(&p4, "p4", takersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(2, ans);
   
  clearLinkList(&takersP4);
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4          |          p1              p2              p3
 * programmes taking       :  c1,c2,c3,c5   |       c1,c2            c3,c4          c5,c6
 *                            -  -  -   -           -   -            -              -
 *                               (3 conflict, p4 conflict with p1,p2 and p3)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_c3_c5_have_3_confict_with_paperList_should_get3(void){
  
  LinkedList *takersP4 = linkListNew(&c1);
  addDataToHead(&takersP4, &c2);
  addDataToHead(&takersP4, &c3);
  addDataToHead(&takersP4, &c5);
  setPaper(&p4, "p4", takersP4);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(3, ans);
   
  clearLinkList(&takersP4);
}
