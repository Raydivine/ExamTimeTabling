#include "unity.h"
#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); 
#define S1_HEAD  s1.papers
#define S1_HEAD1 s1.papers->next
#define S1_HEAD2 s1.papers->next->next
#define S1_HEAD3 s1.papers->next->next->next
#define S1_HEAD4 s1.papers->next->next->next->next

#define S2_HEAD  s2.papers
#define S2_HEAD1 s2.papers->next
#define S2_HEAD2 s2.papers->next->next
#define S2_HEAD3 s2.papers->next->next->next
#define S2_HEAD4 s2.papers->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
LinkedList *listA, *listB, *takenPapers;
Session s1,s2;

void setUp(void){
  s1 = createSession();
  s2 = createSession();
}

void tearDown(void){}

/**    mutateInTwoSessions(Session *session1, Session *session2)
*
*       This function will exchange the elements in 2 session, which are no conflict to other,
*       the exchanged elements must have close studentNum, in order to mantain balance
*       if cant find the non conflict elements, 
*       or the non conflict elements dont have close studentNum
*       then will do nothing.
*       
*/  

/** Session                
 *  s1 :    p1             p2(50)                             
 *         c1,c2           c2,c3                  
 *                          *
 *
 *  s2 :    p3(60)          p4                            
 *          c4,c5         c5,c1   
 *             *
 *                                
 *    p3 and p2 no conflict to order session, and they have close studentNum. so should exchange
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  s1 :    p3              p1           ( The exchanged papers will go to front, because is addDataToHead() )                  
 *         c4,c5           c1,c2                 
 *                              
 *  s2 :    p2              p4            ( The exchanged papers will go to front, because is addDataToHead() )                    
 *         c2,c3          c5,c1   
 *             
*/
void test_mutateInTwoSessions_given_p3_p4_no_conflict_should_exchange(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2 ,"p2", 50);
  addProgrammeToPaper(&p2, &c2);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p3, &c5);
  
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c1);  
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p3, s1.papers->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p2, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1             p2(50)                             
 *           c1,c2           c2,c3                  
 *                          *
 *
 *    s2 :    p5            p3(25)         p4(25)                            
 *          c2,c1          c4,c5          c5,c7   ()
 *                           *             *
 *                                
 *    p2 no conflict to s2, p3 and p4 no conflict to s1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  s1 :    p3              p1                          
 *         c4,c5           c1,c2                 
 *                              
 *  s2 :    p2              p4                              
 *         c2,c3          c5,c1   
 *             
*/
void test_mutateInTwoSessions_given_p3_p4_no_conflict_should_exchange(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2 ,"p2", 50);
  addProgrammeToPaper(&p2, &c2);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p3, &c5);
  
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c1);  
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p3, s1.papers->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p2, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/**  listA has p1 , listB  p3 and p5 no conflict to listA
 *   studentNum in p3,p5 are 50, sum toggether are 100 , is within ratio of targetNum
 *   so will take out  p3 and p5
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(50)           p4(50)       p5(50)                          
 *            c3, c4            c1,c2       c5,c6   
 *             *                              *                 
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = p5,p3 
 *      ListB = p4;
*/
void xtest_mutateInTwoSessions_given_p3_p5_no_conflict_but_p4_has_should_take_out_p3_p5(void){
  
  setPaperWithPopulation(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c1);  
  addProgrammeToPaper(&p4, &c2);  
  
  setPaperWithPopulation(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);

  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , but p4 has 100 student, which cant form the true papers combo
 *   
 *   so will take out  p3 and p5
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(50)           p4(100)      p5(50)                          
 *            c3, c4            c7,c8       c5,c6   
 *             *                            *                 
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = p5,p3 
 *      ListB = p4;
*/
void xtest_mutateInTwoSessions_given_p3_p4_p5_no_conflict_but_p4_has_100_student_should_take_out_p3_p5(void){
  
  setPaperWithPopulation(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperWithPopulation(&p4 ,"p4", 100);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperWithPopulation(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);

  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , all of them have 50 student, 
 *   because  p3-p4 has 100 student, p3-p4-p5 has 150 student
 *   so will take out  p3 and p4
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(50)           p4(50)       p5(50)                          
 *            c3, c4            c7,c8       c5,c6   
 *             *                  *                 
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = p4,p3 
 *      ListB = p5;
*/
void xtest_mutateInTwoSessions_given_p3_p4_p5_no_conflict_but_p3_p4_p5_has_150_student_should_take_out_p3_p4(void){
  
  setPaperWithPopulation(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperWithPopulation(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  
  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , but p3 has 150 student 
 *   so will take out  p4 and p5
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(150)           p4(50)      p5(50)                          
 *            c3, c4            c7,c8       c5,c6   
 *                                *            *                 
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = p4,p3 
 *      ListB = p5;
*/
void xtest_mutateInTwoSessions_given_p3_p4_p5_no_conflict_but_p3_150_student_should_take_out_p4_p5(void){
  
  setPaperWithPopulation(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p3 ,"p3", 150);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperWithPopulation(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);

  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , but p3 has 100 student , and p3-p4 is 150
 *   so will take out  p3 only
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(100)           p4(50)      p5(50)                          
 *            c3, c4            c7,c8       c5,c6   
 *              *               
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = p4,p3 
 *      ListB = p5;
*/
void xtest_mutateInTwoSessions_given_p3_p4_p5_no_conflict_but_p3_has_100_student_should_take_out_p3_only(void){
  
  setPaperWithPopulation(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p3 ,"p3", 100);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperWithPopulation(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperWithPopulation(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  
  CLEAR_ALL_LIST;
}
