#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "Mutation.h"

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

Session session;

void setUp(void)
{
//-----------------TEST ELEMENT----------SHARE TO ALL TEST  

//setProgramme(Programme *target ,char *name, int studentNum)
  setProgramme(&c1 ,"c1", 30);
  setProgramme(&c2 ,"c2", 30);
  setProgramme(&c3 ,"c3", 30);
  setProgramme(&c4 ,"c4", 30);
  setProgramme(&c5 ,"c5", 30);
  setProgramme(&c6 ,"c6", 30);
  setProgramme(&c7 ,"c7", 30);
  setProgramme(&c8 ,"c8", 30);
  setProgramme(&c9 ,"c9", 30);
  setProgramme(&c10 ,"c10", 30);


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
  
  //calFitnessScore(&session);
  //TEST_ASSERT_EQUAL(7,session.fitnessScore);
}

