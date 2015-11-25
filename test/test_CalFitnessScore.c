#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

Paper p1,p2,p3,p4,p5,p6;
Programme c1,c2,c3,c4,c5,c6,c7;

void setUp(void)
{
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  

/**
 *                                 PaperList
 * Papers                  :   p1              p2              p3           p4          p5        p6
 * programmes taking       : c1,c2            c2,c3          c3,c4        c4,c5        c7       c2,c3,c4
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
}

void tearDown(void){
  clearLinkList(&(p1.programmes));
  clearLinkList(&(p2.programmes));
  clearLinkList(&(p3.programmes)); 
  clearLinkList(&(p4.programmes)); 
  clearLinkList(&(p5.programmes)); 
  clearLinkList(&(p6.programmes)); 
}

/**
 *                                 session
 * Papers                  :   p1              p3            p5 
 * programmes taking       : c1,c2            c3,c4         c7      
*/
void test_calFitnessScore_given_session_has_papers_p1_p3_p5_which_does_not_cause_conflict_in_programmes_should_get_0(void)
{
	Session ses = createSession();
  addPaperToSession(&ses, &p1);
  addPaperToSession(&ses, &p3);
  addPaperToSession(&ses, &p5);
  
  calFitnessScore(&ses);
  TEST_ASSERT_EQUAL(0,ses.fitnessScore);
  
  clearLinkList(&(ses.papers)); 
}

/**
 *                                 session
 * Papers                  :   p1              p2              p5
 * programmes taking       : c1,c2            c2,c3            c7
 *                              *             1
 *                            ( 1 conflict, p1 conflict with p2)
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p5_which_cause_1conflict_in_programmes_should_get_1(void)
{
	Session ses = createSession();
  addPaperToSession(&ses, &p1);
  addPaperToSession(&ses, &p2);
  addPaperToSession(&ses, &p5);
  
  calFitnessScore(&ses);
  TEST_ASSERT_EQUAL(1,ses.fitnessScore);
  
  clearLinkList(&(ses.papers)); 
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3
 * programmes taking       : c1,c2            c2,c3         c3,c4
 *   p1 got 1 conflict           *             1
 *   p2 got 1 conflict                           -          1
 *                            ( 1+1 = 2 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_which_cause_2conflict_in_programmes_should_get_2(void)
{
	Session ses = createSession();
  addPaperToSession(&ses, &p1);
  addPaperToSession(&ses, &p2);
  addPaperToSession(&ses, &p3);
  
  calFitnessScore(&ses);
  TEST_ASSERT_EQUAL(2,ses.fitnessScore);
  
  clearLinkList(&(ses.papers)); 
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3          p4            
 * programmes taking       : c1,c2            c2,c3         c3,c4         c4,c5         
 *   p1 got 1 conflict           *             1                                         
 *   p2 got 1 conflict                           *          1                          
 *   p3 got 1 conflict                                          *         1                   
 *                            ( 1+1+1 = 3 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_p4_which_cause_3conflict_in_programmes_should_get_3(void)
{
	Session ses = createSession();
  addPaperToSession(&ses, &p1);
  addPaperToSession(&ses, &p2);
  addPaperToSession(&ses, &p3);
  addPaperToSession(&ses, &p4);
  
  calFitnessScore(&ses);
  TEST_ASSERT_EQUAL(3,ses.fitnessScore);
  
  clearLinkList(&(ses.papers)); 
}

/**
 *                                 session
 * Papers                  :   p1              p2              p3          p4            p6
 * programmes taking       : c1,c2            c2,c3         c3,c4         c4,c5         c2,c3,c4
 *   p1 got 2 conflict          *             1                                         2
 *   p2 got 2 conflict                           *          1  1                            2  2
 *   p3 got 2 conflict                                          *         1                    2
 *   p4 got 1 conflict                                                    *                    2                    
 *                            ( 2+2+2+1 = 7 )
*/
void test_calFitnessScore_given_session_has_papers_p1_p2_p3_p4_p6_which_cause_7conflict_in_programmes_should_get_7(void)
{
	Session ses = createSession();
  addPaperToSession(&ses, &p1);
  addPaperToSession(&ses, &p2);
  addPaperToSession(&ses, &p3);
  addPaperToSession(&ses, &p4);
  addPaperToSession(&ses, &p6);

  calFitnessScore(&ses);
  TEST_ASSERT_EQUAL(7,ses.fitnessScore);
  
  clearLinkList(&(ses.papers)); 
}