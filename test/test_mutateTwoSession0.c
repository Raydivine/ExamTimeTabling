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
LinkedList *listA, *listB, *takenPapers;
Session s1,s2;

void setUp(void){
  s1 = createSession();
  s2 = createSession();
}

void tearDown(void){}


/**   void mutateTwoSession(Session *session1, Session *session2)
*
*       This function will exchange the elements in 2 session, which are no conflict to other,
*       the exchanged elements must have close studentNum( +- 20% ), in order to mantain balance
*       if cant find the non conflict elements, 
*       or the non conflict elements dont have close studentNum
*       then will do nothing.
*
*       session2 will give true papers to p1 , which is
*
*       The criteria of truePapers
*       1.  truePapers cannot conflict to session1
*       2.  truePapers its self cannot has conflict
*       3.  truePapers's studentNum must close to session1's exchange elements's studetNum ( not more or less then 20% of studetNum)*
*       
*       Notice: The below tests are the cases while this function will do nothing
*/ 

/**  
 *                              
 *  Session1 :    p1              p2                              
 *               c1,c2           c3,c4                  
 *
 *  Session2 :    p3              p4                            
 *               c2,c3          c4,c1                
 * 
 *   Session1 and Session2 all elements are confict with each other, their programmes element already exist in other session, 
 *   so no matter how exchange will just only cause confict, therefore should not do mutation
*/
void test_mutateTwoSession_given_the_2session_all_element_conflict_with_other_should_not_do_Mutation(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2, "p2", 50);
  addProgrammeToPaper(&p2, &c3);
  addProgrammeToPaper(&p2, &c4);
  
  setPaperWithPopulation(&p3, "p3", 50);
  addProgrammeToPaper(&p3, &c2);
  addProgrammeToPaper(&p3, &c3);
  
  setPaperWithPopulation(&p4, "p4", 50);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c1);  
  

  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //----------------------------------------------------------------------------------------
  mutateTwoSession(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p1,S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2,S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p3,S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4,S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);
  
  CLEAR_ALL_LIST;
}


/**  
 *                              
 *  Session1 :    p1              p2                              
 *               c1,c2           c5,c6                  
 *                                 *
 *
 *  Session2 :    p3              p4                            
 *               c2,c3          c4,c1                
 * 
 *    
 *   p2 is no confict to session2, but session2 all elements confict to session1, so do nothing
*/
void test_mutateTwoSession_given_the_session2_all_elements_conflict_to_session1_should_do_nothing(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2, "p2", 50);
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);
  
  setPaperWithPopulation(&p3, "p3", 50);
  addProgrammeToPaper(&p3, &c2);
  addProgrammeToPaper(&p3, &c3);
  
  setPaperWithPopulation(&p4, "p4", 50);
  addProgrammeToPaper(&p4, &c4);  
  addProgrammeToPaper(&p4, &c1);  
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //----------------------------------------------------------------------------------------
  mutateTwoSession(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p1,S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2,S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p3,S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4,S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);
  
  CLEAR_ALL_LIST;
}

/**  
 *                              
 *  Session1 :    p1              p2(100)                              
 *               c1,c2           c5,c6                  
 *                                 *
 *
 *  Session2 :    p3(10)           p4(10)                            
 *               c7,c8           c9,c10                
 * 
 *    
 *   p2 is no confict to session2, but session2 can not return a papers combo having close number to p2, so do nothing
*/
void test_mutateTwoSession_given_the_session2_cannot_return_papers_combo_having_close_number_to_p2_should_do_nothing(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2, "p2", 100);
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);
  
  setPaperWithPopulation(&p3, "p3", 10);
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c8);
  
  setPaperWithPopulation(&p4, "p4", 10);
  addProgrammeToPaper(&p4, &c9);  
  addProgrammeToPaper(&p4, &c10);  
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //----------------------------------------------------------------------------------------
  mutateTwoSession(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p1,S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2,S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p3,S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4,S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);
  
  CLEAR_ALL_LIST;
}

/**  
 *                              
 *  Session1 :    p1              p2(100)                              
 *               c1,c2           c5,c6                  
 *                                 *
 *
 *  Session2 :    p3(50)           p4(50)                            
 *               c7,c8           c8,c1                
 *                   
 *    (p3 and p4 having c8 )
 *   p2 is no confict to session2, p3 and p4 together can meet p2 studentNum, but p3 p4 them selves has confict, so do nothing
*/
void test_mutateTwoSession_given_the_p3_p4_having_c8_cause_conflict_so_do_nothing(void){
  setPaperWithPopulation(&p1, "p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperWithPopulation(&p2, "p2", 100);
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);
  
  setPaperWithPopulation(&p3, "p3", 50);
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c8);
  
  setPaperWithPopulation(&p4, "p4", 50);
  addProgrammeToPaper(&p4, &c8);  
  addProgrammeToPaper(&p4, &c1);  
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  //----------------------------------------------------------------------------------------
  mutateTwoSession(&s1, &s2);
  TEST_ASSERT_EQUAL_PTR( &p1,S1_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2,S1_HEAD1->data);
  TEST_ASSERT_NULL(S1_HEAD2);
  TEST_ASSERT_EQUAL_PTR( &p3,S2_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4,S2_HEAD1->data);
  TEST_ASSERT_NULL(S2_HEAD2);
  
  CLEAR_ALL_LIST;
}

