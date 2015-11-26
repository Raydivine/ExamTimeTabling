#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "Mutation.h"

#define S1_HEAD   s1.papers
#define S1_HEAD2  s1.papers->next

#define S2_HEAD   s2.papers
#define S2_HEAD2  s2.papers->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

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
}

void tearDown(void){}


/** 
 *                              
 *  Session1 :    p1              p2                              
 *               c1,c2           c2,c3                  
 *                                *
 *
 *  Session2 :    p3              p4                            
 *               c1,c5          c5,c6               
 *                                *
 * 
 *   p2 and p4 have not conflict with other session, therefore shold do Mutation
 *   
 *
 *  Session1 :    p1              p4                              
 *               c1,c2           c5,c6                 
 *                                
 *
 *  Session2 :    p3              p2                            
 *               c1,c5          c2,c3               
 *                                
*/
void test_mutateInTwoSessions_given_the_2session_p3_p4_no_conflict_with_other_should_do_Mutation(void){
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  Session s1 = createSession();
  addPaperToSession(&s1, &p2);  // For the faster process speed, the used LinkedList add functions
  addPaperToSession(&s1, &p1);  // is addDataToHead() , so adding the element has to been in reverse way 
  
  Session s2 = createSession();
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //----------------------------------------------------------------------------------------
  mutateInTwoSessions(&s1, &s2);
  // TEST_ASSERT_EQUAL_PTR( &p1,S1_HEAD->data);
  // TEST_ASSERT_EQUAL_PTR( &p4,S1_HEAD2->data);
  // TEST_ASSERT_EQUAL_PTR( &p3,S2_HEAD->data);
  // TEST_ASSERT_EQUAL_PTR( &p2,S2_HEAD2->data);
  
  clearLinkList(&(s1.papers));
  clearLinkList(&(s2.papers));
  clearLinkList(&(p1.programmes));
  clearLinkList(&(p2.programmes));
  clearLinkList(&(p3.programmes));
  clearLinkList(&(p4.programmes));
}

