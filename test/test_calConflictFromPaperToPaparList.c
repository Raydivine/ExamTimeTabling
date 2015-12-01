#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4;
Programme c1,c2,c3,c4,c5,c6,c7,c8;

LinkedList *paperList;

void setUp(void){
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  

 /**
 *                                 PaperList
 * Papers                  :   p1              p2              p3
 * programmes taking       : c1,c2            c3,c4          c5,c6
*/

  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c3);
  addProgrammeToPaper(&p2, &c4);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c5);
  addProgrammeToPaper(&p3, &c6);
  
  paperList = linkListNew(&p1);
  addDataToHead(&paperList, &p2);
  addDataToHead(&paperList, &p3);
}

void tearDown(void){
  clearLinkList(&(p1.programmes));
  clearLinkList(&(p2.programmes));
  clearLinkList(&(p3.programmes));
  clearLinkList(&paperList);
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c7,c8    |       c1,c2            c3,c4          c5,c6
 *
 *                               (no conflict)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c7_c8_which_no_confict_with_paperList_should_get0(void){
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c7);
  addProgrammeToPaper(&p4, &c8);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(0, ans);
  
  clearLinkList(&(p4.programmes));
}


/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c1,c8    |       c1,c2            c3,c4          c5,c6
 *                            -               -
 *                               (1 conflict)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c8_have_1_confict_with_paperList_should_get1(void){
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c1);
  addProgrammeToPaper(&p4, &c8);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(1, ans);
  
  clearLinkList(&(p4.programmes));
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4     |          p1              p2              p3
 * programmes taking       :  c1,c2    |       c1,c2            c3,c4          c5,c6
 *                            -  -             -   -
 *                               (1 conflict, however there is 2 same programmes, but they are same paper)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_have_1_confict_with_paperList_should_get1(void){
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c1);
  addProgrammeToPaper(&p4, &c2);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(1, ans);
  
  clearLinkList(&(p4.programmes));
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4        |          p1              p2              p3
 * programmes taking       :  c1,c2,c3    |       c1,c2            c3,c4          c5,c6
 *                            -  -  -             -   -            -
 *                               (2 conflict, p4 conflict with p1 and p2)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_c3_have_2_confict_with_paperList_should_get2(void){
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c1);
  addProgrammeToPaper(&p4, &c2);
  addProgrammeToPaper(&p4, &c3);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(2, ans);
  
  clearLinkList(&(p4.programmes));
}

/**
 *                             Paper            PaperList
 * Papers                  :    p4          |          p1              p2              p3
 * programmes taking       :  c1,c2,c3,c5   |       c1,c2            c3,c4          c5,c6
 *                            -  -  -   -           -   -            -              -
 *                               (3 conflict, p4 conflict with p1,p2 and p3)
*/
void test_calConflictFromPaperToPaparList_given_p4_takers_are_c1_c2_c3_c5_have_3_confict_with_paperList_should_get3(void){
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c1);
  addProgrammeToPaper(&p4, &c2);
  addProgrammeToPaper(&p4, &c3);
  addProgrammeToPaper(&p4, &c5);
  
  int ans = calConflictFromPaperToPaparList( &p4, paperList);
  TEST_ASSERT_EQUAL(3, ans);
   
  clearLinkList(&(p4.programmes));
}
