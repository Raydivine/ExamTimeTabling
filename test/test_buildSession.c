#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"


#define HEAD  s.papers
#define HEAD1 s.papers->next
#define HEAD2 s.papers->next->next
#define HEAD3 s.papers->next->next->next
#define HEAD4 s.papers->next->next->next->next
#define HEAD5 s.papers->next->next->next->next->next
#define HEAD6 s.papers->next->next->next->next->next->next
#define HEAD7 s.papers->next->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7;
Programme c1,c2,c3,c4,c5,c6,c7;

void setUp(void)
{
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  

/**
 *                                 PaperList
 * Papers                  :   p1              p2              p3           p4          p5        p6              p7
 * programmes taking       : c1,c2            c2,c3          c3,c4        c4,c5        c7       c2,c3,c4       c1,c5,c4,c7
*/
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c4);
  addProgrammeToPaper(&p4, &c5);
  
  setPaper(&p5 ,"p5");
  addProgrammeToPaper(&p5, &c7);
  
  setPaper(&p6 ,"p6");
  addProgrammeToPaper(&p6, &c2);
  addProgrammeToPaper(&p6, &c3);
  addProgrammeToPaper(&p6, &c4);
  
  setPaper(&p7 ,"p7");
  addProgrammeToPaper(&p7, &c1);
  addProgrammeToPaper(&p7, &c5);
  addProgrammeToPaper(&p7, &c4);
  addProgrammeToPaper(&p7, &c7);
}

void tearDown(void){
  clearLinkList(&(p1.programmes));
  clearLinkList(&(p2.programmes));
  clearLinkList(&(p3.programmes)); 
  clearLinkList(&(p4.programmes)); 
  clearLinkList(&(p5.programmes)); 
  clearLinkList(&(p6.programmes)); 
  clearLinkList(&(p7.programmes)); 
}

/** void  buildSession(Session *session)
*
*   This function will calculate the conflict number in a session,
*   the round to calculate , is euqal ( number papers - 1 )
*
*   Example:
* Papers                  :   p1              p2              p3           p4          p5        p6              p7
* programmes taking       : c1,c2            c2,c3          c3,c4        c4,c5        c7       c2,c3,c4       c1,c5,c4,c7
*                          round 1 --------------------------------------------------------------------------------------
*                                            round 2 --------------------------------------------------------------------
*                                                           round 3 -----------------------------------------------------
*                                                                       round 4 -----------------------------------------
*                                                                                   round 5 -----------------------------
*                                                                                             round 6 -------------------
*
*  So every paper will compare to others to check is it conflict
*  
*/

/**
 *                                 session
 * Papers                  :   p1              p3            p5 
 * programmes taking       : c1,c2            c3,c4         c7      
*/
void test_buildSession_given_session_has_papers_p1_p3_p5_which_does_not_cause_conflict_in_programmes_should_build_with_conflict_0(void){
	LinkedList *plist =  linkListNew(&p5);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p1);

  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(0,s.conflict);
  TEST_ASSERT_EQUAL_PTR(&p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, HEAD2->data);
  TEST_ASSERT_NULL(HEAD3);
  
 // clearLinkList(&plist); 
  

   TEST_ASSERT_EQUAL_PTR(&p1, HEAD->data);
  TEST_ASSERT_EQUAL_PTR(&p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, HEAD2->data);
    TEST_ASSERT_NULL(HEAD3);
}

/**
 *                                 session
 * Papers                  :   p1              p2              p5
 * programmes taking       : c1,c2            c2,c3            c7
 *                           round 1           -
 *                            ( 1 conflict, p1 conflict with p2)
*/
void xtest_buildSession_given_session_has_papers_p1_p2_p5_which_cause_1conflict_in_programmes_should_build_with_conflict_1(void){
	LinkedList *plist =  linkListNew(&p5);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);

  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(1,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}

/**
 *                                           session
 * Papers                             :   p1              p2              p3
 * programmes taking                  : c1,c2            c2,c3         c3,c4
 *   p1 conflict with 1 paper           round 1           -
 *   p2 conflict with 1 paper                            round 2        -
 *                                                    ( 1+1 = 2 )
*/
void xtest_buildSession_given_session_has_papers_p1_p2_p3_which_cause_2conflict_in_programmes_should_build_with_conflict__2(void){
	LinkedList *plist =  linkListNew(&p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);
 
  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(2,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}

/**
 *                                                        session
 * Papers                             :     p1              p2              p3          p4            
 * programmes taking                  :    c1,c2           c2,c3         c3,c4         c4,c5         
 *   p1 conflict with 1 paper              round 1          -                                        
 *   p2 conflict with 1 paper                              round 2        -                         
 *   p3 conflict with 1 paper                                            round 3        -                   
 *                                                ( 1+1+1 = 3 )
*/
void xtest_buildSession_given_session_has_papers_p1_p2_p3_p4_which_cause_3conflict_in_programmes_should_build_with_conflict_3(void){
	LinkedList *plist =  linkListNew(&p4);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);

  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(3,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}

/**
 *                                            session
 * Papers                     :   p1              p2              p3          p4            p6
 * programmes taking          : c1,c2            c2,c3         c3,c4         c4,c5         c2,c3,c4
 *   p1 conflict with 2 paper    round 1         -                                         -
 *   p2 conflict with 2 paper                   round 2        -                           - 
 *   p3 conflict with 2 paper                                  round 3       -                -  -
 *   p4 conflict with 1 paper                                                round 4             -                    
 *                            ( 2+2+2+1 = 7 )
*/
void xtest_buildSession_given_session_has_papers_p1_p2_p3_p4_p6_which_cause_7conflict_in_programmes_should_build_with_conflict_7(void){
	LinkedList *plist =  linkListNew(&p6);
  addDataToHead(&plist, &p4);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);

  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(7,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}

/**
* Papers                     :   p1              p2              p3           p4          p5        p6              p7
* programmes taking          : c1,c2            c2,c3          c3,c4        c4,c5        c7       c2,c3,c4       c1,c5,c4,c7
*   p1 conflict with 3 paper   round 1          -                                                 -              -
*   p2 conflict with 2 paper                   round 2         -                                  -  -
*   p3 conflict with 3 paper                                   round 3      -                         - -             -  -
*   p4 conflict with 2 paper                                                round 4                      -           -  -
*   p5 conflict with 1 paper                                                            round 5                            -
*   p6 conflict with 1 paper                                                                       round 6              -
*
*        (3+2+3+2+1+1 = 12 )
*/   
void xtest_buildSession_given_session_has_papers_p1_p2_p3_p4_p6_p5_p7_which_cause_12conflict_in_programmes_should_build_with_conflict_12(void){
	LinkedList *plist =  linkListNew(&p7);
  addDataToHead(&plist, &p6);
  addDataToHead(&plist, &p5);
  addDataToHead(&plist, &p4);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p1);

  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(12,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}

void xtest_buildSession_given_session_has_papers_p7_p6_p5_p4_p3_p2_p1_even_the_order_is_reverse_also_should_build_with_conflict_12(void){
	LinkedList *plist =  linkListNew(&p1);   // reversed order
  addDataToHead(&plist, &p2);
  addDataToHead(&plist, &p3);
  addDataToHead(&plist, &p4);
  addDataToHead(&plist, &p5);
  addDataToHead(&plist, &p6);
  addDataToHead(&plist, &p7);

  
  Session s = buildSession(&plist);
  TEST_ASSERT_EQUAL(12,s.conflict);
  
  clearLinkList(&plist); 
  clearLinkList(&(s.papers));
}