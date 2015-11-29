#include "unity.h"
#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST  clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes)); clearLinkList(&(p6.programmes));
#define S1_HEAD  s1.papers
#define S1_HEAD1 s1.papers->next
#define S1_HEAD2 s1.papers->next->next
#define S1_HEAD3 s1.papers->next->next->next
#define S1_HEAD4 s1.papers->next->next->next->next
#define S1_HEAD5 s1.papers->next->next->next->next->next
#define S1_HEAD6 s1.papers->next->next->next->next->next->next

#define S2_HEAD  s2.papers
#define S2_HEAD1 s2.papers->next
#define S2_HEAD2 s2.papers->next->next
#define S2_HEAD3 s2.papers->next->next->next
#define S2_HEAD4 s2.papers->next->next->next->next
#define S2_HEAD5 s2.papers->next->next->next->next->next
#define S2_HEAD6 s2.papers->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2;

void setUp(void){
  s1 = createSession();
  s2 = createSession();
}

void tearDown(void){}

/**   void mutateInTwoSessions(Session *session1, Session *session2)
*
*       This function will exchange the elements in 2 session, which are no conflict to other,
*       the exchanged elements must have close studentNum( +- 20% ), in order to mantain balance
*       if cant find the non conflict elements, 
*       or the non conflict elements dont have close studentNum
*       then will do nothing.
*
*
*       session2 will give true papers to p1 , which is
*
*       The criteria of truePapers
*       1.  truePapers cannot conflict to session1
*       2.  truePapers its self cannot has conflict
*       3.  truePapers's studentNum must close to session1's exchange elements's studetNum ( not more or less then 20% of studetNum)
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
void test_mutateInTwoSessions_given_p3_p2_no_conflict_should_exchange(void){
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
  TEST_ASSERT_EQUAL_PTR( &p3, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p2, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1             p2(50)                             
 *           c1,c2           c8,c3                  
 *                            *
 *
 *    s2 :    p3(25)        p4(25)        p5                        
 *            c4,c5          c6,c7       c1,c2
 *              *             *
 *                                
 *    p2 no conflict to s2, p3 and p4 no conflict to s1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p3          p4        p1                      
 *           c4,c5        c6,c7     c1,c2                            
 *                                           
 *    s2 :     p2          p5                              
 *            c8,c3       c1,c2
 *             
*/
void test_mutateInTwoSessions_given_p2_and_p3_p4_no_conflict_should_exchange(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2 ,"p2", 50);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 25);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p3, &c5);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c6);  
  addProgrammeToPaper(&p4, &c7);  
  
  setPaperWithPopulation(&p5 ,"p5", 50);
  addProgrammeToPaper(&p5, &c1);  
  addProgrammeToPaper(&p5, &c2);
 
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p3, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD2->data);
  TEST_ASSERT_NULL(S1_HEAD3);
  TEST_ASSERT_EQUAL_PTR( &p2, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1(100)        p2(50)        p3                         
 *             c8,c3         c8,c3      c1,c9            
 *                             *
 *
 *    s2 :    p4(25)        p5(25)         p6                      
 *            c4,c5          c6,c7       c1,c9
 *              *             *           
 *                                                             
 *    p1, p2 no conflict to s2,but p1 has 100 students which s2 cant return possible combo, therefore exchange with p2
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p4          p5        p1       p3                      
 *           c4,c5        c6,c7    c8,c3     c1,c9                           
 *                                           
 *    s2 :     p2          p6                              
 *            c8,c3       c1,c9
 *             
*/
void test_mutateInTwoSessions_given_p1_p2_no_conflict_s2_but_p1_has_100_stundet_which_s2_cant_return_possible_combo_therefore_should_use_p2(void){
  setPaperWithPopulation(&p1, "p1", 100);
  addProgrammeToPaper(&p1, &c8);
  addProgrammeToPaper(&p1, &c3);
  
  setPaperWithPopulation(&p2 ,"p2", 50);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c9);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaperWithPopulation(&p5 ,"p5", 25);
  addProgrammeToPaper(&p5, &c6);  
  addProgrammeToPaper(&p5, &c7);
  
  setPaperWithPopulation(&p6 ,"p6", 50);
  addProgrammeToPaper(&p6, &c1);  
  addProgrammeToPaper(&p6, &c9);
 
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p6);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p3, S1_HEAD3->data);
  TEST_ASSERT_NULL(S1_HEAD4);
  TEST_ASSERT_EQUAL_PTR( &p2, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p6, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}


/** Session                  
 *     s1 :    p1(50)        p2(50)        p3                         
 *             c8,c3         c8,c3      c1,c9            
 *              *
 *
 *    s2 :    p4(25)        p5(25)         p6                      
 *            c4,c5          c6,c7       c1,c9
 *              *             *           
 *                                                             
 *    p1, p2 no conflict s2, and s2 can return the combo which close to p1 studentNum, therefore exchange with p1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p4          p5        p2       p3                      
 *           c4,c5        c6,c7    c8,c3     c1,c9                           
 *                                           
 *    s2 :     p1          p6                              
 *            c8,c3       c1,c9
 *             
*/
void test_mutateInTwoSessions_given_p1_p2_no_conflict_s2_and_s2_can_return_possible_combo_close_to_p1_studentNum_therefore_should_use_p1(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c8);
  addProgrammeToPaper(&p1, &c3);
  
  setPaperWithPopulation(&p2 ,"p2", 50);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c9);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaperWithPopulation(&p5 ,"p5", 25);
  addProgrammeToPaper(&p5, &c6);  
  addProgrammeToPaper(&p5, &c7);
  
  setPaperWithPopulation(&p6 ,"p6", 50);
  addProgrammeToPaper(&p6, &c1);  
  addProgrammeToPaper(&p6, &c9);
 
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p6);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p2, S1_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p3, S1_HEAD3->data);
  TEST_ASSERT_NULL(S1_HEAD4);
  TEST_ASSERT_EQUAL_PTR( &p1, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p6, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1(100)        p2(100)        p3(50)                         
 *             c8,c3         c8,c3          c8,c3           
 *                                          *
 *
 *    s2 :    p4(25)        p5(25)         p6(5)                      
 *            c4,c5          c6,c7        c1,c9
 *              *             *             *  
 *                                                             
 *    p1, p2, p3 no conflict to s2, but s2 only can return papers combo for p3, therefore exchanged with p3
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p4          p5         p6        p1       p2                      
 *           c4,c5        c6,c7      c1,c9    c8,c3     c8,c3                           
 *                                           
 *    s2 :     p3                                     
 *            c8,c3       
 *             
*/
void test_mutateInTwoSessions_given_p1_p2_p3_but_s2_only_can_return_papers_combo_for_p3_therefore_exchange_with_p3(void){
  setPaperWithPopulation(&p1, "p1", 100);
  addProgrammeToPaper(&p1, &c8);
  addProgrammeToPaper(&p1, &c3);
  
  setPaperWithPopulation(&p2 ,"p2", 100);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c8);
  addProgrammeToPaper(&p3, &c3);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaperWithPopulation(&p5 ,"p5", 25);
  addProgrammeToPaper(&p5, &c6);  
  addProgrammeToPaper(&p5, &c7);
  
  setPaperWithPopulation(&p6 ,"p6", 5);
  addProgrammeToPaper(&p6, &c1);  
  addProgrammeToPaper(&p6, &c9);
 
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p6);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p6, S1_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD3->data);
  TEST_ASSERT_EQUAL_PTR( &p2, S1_HEAD4->data);
  TEST_ASSERT_NULL(S1_HEAD5);
  TEST_ASSERT_EQUAL_PTR( &p3, S2_HEAD->data);
  TEST_ASSERT_NULL(S2_HEAD1);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1(100)        p2(100)        p3(50)                         
 *             c8,c3         c8,c3          c8,c3           
 *                                          *
 *
 *    s2 :    p4(25)        p5(25)         p6(10)                      
 *            c4,c5          c6,c7        c1,c9
 *              *             *               
 *                                                             
 *    p4+p5 = 50 , p4+p5+p6 = 60 ( which more than 20% of p3(50) ), therefore only change with p4,p5
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p4          p5        p1       p2                      
 *           c4,c5        c6,c7    c8,c3     c8,c3                           
 *                                           
 *    s2 :     p3          p6                          
 *            c8,c3      c1,c9
 *             
*/
void test_mutateInTwoSessions_given_p4_p5_p6_equal_60_which_more_than_20percent_of_p3_therefore_only_change_with_p4_p5(void){
  setPaperWithPopulation(&p1, "p1", 100);
  addProgrammeToPaper(&p1, &c8);
  addProgrammeToPaper(&p1, &c3);
  
  setPaperWithPopulation(&p2 ,"p2", 100);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c8);
  addProgrammeToPaper(&p3, &c3);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaperWithPopulation(&p5 ,"p5", 25);
  addProgrammeToPaper(&p5, &c6);  
  addProgrammeToPaper(&p5, &c7);
  
  setPaperWithPopulation(&p6 ,"p6", 10);
  addProgrammeToPaper(&p6, &c1);  
  addProgrammeToPaper(&p6, &c9);
 
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p6);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, S1_HEAD3->data);
  TEST_ASSERT_NULL(S1_HEAD4);
  TEST_ASSERT_EQUAL_PTR( &p3, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p6, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}

/** Session                  
 *     s1 :    p1(100)        p2(100)        p3(50)                         
 *             c8,c3         c8,c3          c8,c3           
 *                                          *
 *
 *    s2 :    p4(25)        p5(25)         p6(5)                      
 *            c4,c5          c6,c7        c7,c9
 *              *             *               
 *                                                             
 *    p4p5p6 together is meet p3 studentNum, but p6 having conflict with p5, therefore only changed with p4,p5
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *    s1 :     p4          p5        p1       p2                      
 *           c4,c5        c6,c7    c8,c3     c8,c3                           
 *                                           
 *    s2 :     p3          p6                          
 *            c8,c3      c7,c9
 *             
*/
void test_mutateInTwoSessions_given_p6_conflict_with_p4_p5_so_only_exchanged_with_p4_p5_no_p6(void){
  setPaperWithPopulation(&p1, "p1", 100);
  addProgrammeToPaper(&p1, &c8);
  addProgrammeToPaper(&p1, &c3);
  
  setPaperWithPopulation(&p2 ,"p2", 100);
  addProgrammeToPaper(&p2, &c8);  
  addProgrammeToPaper(&p2, &c3);  
  
  setPaperWithPopulation(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c8);
  addProgrammeToPaper(&p3, &c3);
  
  setPaperWithPopulation(&p4 ,"p4", 25);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaperWithPopulation(&p5 ,"p5", 25);
  addProgrammeToPaper(&p5, &c6);  
  addProgrammeToPaper(&p5, &c7);
  
  setPaperWithPopulation(&p6 ,"p6", 5);
  addProgrammeToPaper(&p6, &c7);  
  addProgrammeToPaper(&p6, &c9);
 
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p6);
  addPaperToSession(&s2, &p5);
  addPaperToSession(&s2, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  mutateInTwoSessions(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p4, S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p5, S1_HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, S1_HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p2, S1_HEAD3->data);
  TEST_ASSERT_NULL(S1_HEAD4);
  TEST_ASSERT_EQUAL_PTR( &p3, S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p6, S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);

  CLEAR_ALL_LIST;
}
