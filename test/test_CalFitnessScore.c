#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4,p5,p6;
Programme c1,c2,c3,c4,c5,c6,c7;

Session session;

void setUp(void)
{
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  
  LinkedList *takersP1 = linkListNew(&c1);
  addDataToHead(&takersP1, &c2);
  setPaper(&p1, "p1", takersP1);
  
  LinkedList *takersP2 = linkListNew(&c2);
  addDataToHead(&takersP2, &c3);
  setPaper(&p2, "p2", takersP2);
  
  LinkedList *takersP3 = linkListNew(&c3);
  addDataToHead(&takersP3, &c4);
  setPaper(&p3, "p3", takersP3);
  
  LinkedList *takersP4 = linkListNew(&c4);
  addDataToHead(&takersP4, &c5);
  setPaper(&p4, "p4", takersP4);
  
  LinkedList *takersP5 = linkListNew(&c7);
  setPaper(&p4, "p4", takersP4);
  
  LinkedList *takersP6 = linkListNew(&c2);
  addDataToHead(&takersP6, &c3);
  addDataToHead(&takersP6, &c4);
  setPaper(&p6, "p6", takersP6);
  

/**
 *                                 PaperList
 * Papers                  :   p1              p2              p3           p4          p5        p6
 * programmes taking       : c1,c2            c2,c3          c3,c4        c4,c5        c7       c2,c3,c4
*/
}

void tearDown(void){}

/**
 *                                 session
 * Papers                  :   p1              p3            p5 
 * programmes taking       : c1,c2            c3,c4         c7      
*/
void test_calFitnessScore_given_session_has_papers_p1_p3_p5_which_does_not_cause_conflict_in_programmes_should_get_0(void)
{
	LinkedList *papers = linkListNew(&p1);
  addDataToHead(&papers, &p3);
  addDataToHead(&papers, &p5);
  session.papers = papers;
  
  calFitnessScore(&session);
  TEST_ASSERT_EQUAL(0,session.fitnessScore);
}

/**
 *                                 session
 * Papers                  :   p1              p2              p5
 * programmes taking       : c1,c2            c2,c3            c7
 *                              *             -
 *                            ( 1 conflict, p1 conflict with p2)
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p5_which_cause_1conflict_in_programmes_should_get_1(void)
{
	LinkedList *papers = linkListNew(&p1);
  addDataToHead(&papers, &p2);
  addDataToHead(&papers, &p5);
  session.papers = papers;
  
  calFitnessScore(&session);
  TEST_ASSERT_EQUAL(1,session.fitnessScore);
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3
 * programmes taking       : c1,c2            c2,c3         c3,c4
 *   p1 got 1 conflict           -             -
 *   p2 got 1 conflict                           -          -
 *                            ( 1+1 = 2 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_which_cause_2conflict_in_programmes_should_get_2(void)
{
	LinkedList *papers = linkListNew(&p1);
  addDataToHead(&papers, &p2);
  addDataToHead(&papers, &p3);
  session.papers = papers;
  
  calFitnessScore(&session);
  TEST_ASSERT_EQUAL(2,session.fitnessScore);
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3          p4            
 * programmes taking       : c1,c2            c2,c3         c3,c4         c4,c5         
 *   p1 got 1 conflict           *             -                                         
 *   p2 got 1 conflict                           *          -                          
 *   p3 got 1 conflict                                          *         -                   
 *                            ( 1+1+1 = 3 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_p4_which_cause_3conflict_in_programmes_should_get_3(void)
{
	LinkedList *papers = linkListNew(&p1);
  addDataToHead(&papers, &p2);
  addDataToHead(&papers, &p3);
  addDataToHead(&papers, &p4);
  session.papers = papers;
  
  calFitnessScore(&session);
  TEST_ASSERT_EQUAL(3,session.fitnessScore);
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3          p4            p6
 * programmes taking       : c1,c2            c2,c3         c3,c4         c4,c5         c2,c3,c4
 *   p1 got 2 conflict          *             -                                         -
 *   p2 got 3 conflict                           *          -   -                          -   -
 *   p3 got 2 conflict                                          *         -                    -
 *                            ( 2+3+2 = 7 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_p4_p6_which_cause_7conflict_in_programmes_should_get_7(void)
{
	LinkedList *papers = linkListNew(&p1);
  addDataToHead(&papers, &p2);
  addDataToHead(&papers, &p3);
  addDataToHead(&papers, &p4);
  addDataToHead(&papers, &p6);
  session.papers = papers;
  
  calFitnessScore(&session);
  TEST_ASSERT_EQUAL(7,session.fitnessScore);
}

