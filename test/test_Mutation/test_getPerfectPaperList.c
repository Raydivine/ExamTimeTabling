#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST clearLinkList(&(perfectPapers)); clearLinkList(&listA); clearLinkList(&listB); clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); 
#define LISTB_HEAD  listB
#define LISTB_HEAD1 listB->next
#define LISTB_HEAD2 listB->next->next
#define LISTB_HEAD3 listB->next->next
#define LISTB_HEAD4 listB->next->next->next

#define TAKEN_PAPER1 perfectPapers
#define TAKEN_PAPER2 perfectPapers->next
#define TAKEN_PAPER3 perfectPapers->next->next
#define TAKEN_PAPER4 perfectPapers->next->next
#define TAKEN_PAPER5 perfectPapers->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
LinkedList *listA, *listB, *perfectPapers;
int currentNum;

void setUp(void){
  currentNum = 0;
}

void tearDown(void){}

/**    perfectPapers = getPerfectPaperList(LinkedList *list1, LinkedList *list2, int *currentNum, int targetNum)
*
*       This function will return the perfectPapers contain in ListB
*
*       The criteria of perfectPapers
*       1.  perfectPapers cannot conflict to listA
*       2.  perfectPapers its self cannot has conflict
*       3.  perfectPapers's studentNum must close to targetNum ( not more then 20% of targetNum)
*
*       If can not find the combo is meet the conditon , then return NULL
*
*       *currentNum will contain perfectPapers's studentNum while this function return 
*
*   Notice : The below tests are the cases that function will return a  perfectPapers combo
*/  

/**  listA is NULL , so listB is no conflict to listA, 
 *   studentNum in p3,p4 are 50, sum toggether are 100 , is within ratio of targetNum
 *   so will take out  p3 and p4
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    NULL    
 *
 *  listB :    p3(50)         p4(50)                            
 *            c1,c5           c7,c6   
 *                              
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     perfectPapers = p4,p3 (Because is using addDataToHead(), so the order reverse)   
*/
void test_getPerfectPaperList_given_ListA_is_NULL_should_take_out_p3_p4(void){
  
  setPaperTakersNum(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  setPaperTakersNum(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c6);  
  
  listA = NULL;
  
  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p4, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
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
 *     perfectPapers = p5,p3 
*/
void test_getPerfectPaperList_given_p3_p5_no_conflict_but_p4_has_should_take_out_p3_p5(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c1);  
  addProgrammeToPaper(&p4, &c2);  
  
  setPaperTakersNum(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p5, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
  
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
 *     perfectPapers = p5,p3 
*/
void test_getPerfectPaperList_given_p3_p4_p5_no_conflict_but_p4_has_100_student_should_take_out_p3_p5(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 100);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperTakersNum(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p5, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
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
 *     perfectPapers = p4,p3 
*/
void test_getPerfectPaperList_given_p3_p4_p5_no_conflict_but_p3_p4_p5_has_150_student_should_take_out_p3_p4(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 50);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperTakersNum(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p4, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
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
 *     perfectPapers = p4,p5 
 *      ListB = p3;
*/
void test_getPerfectPaperList_given_p3_p4_p5_no_conflict_but_p3_150_student_should_take_out_p4_p5(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 150);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperTakersNum(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p5, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p4, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
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
 *     perfectPapers = p3 
*/
void test_getPerfectPaperList_given_p3_p4_p5_no_conflict_but_p3_has_100_student_should_take_out_p3_only(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 100);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 50);
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  setPaperTakersNum(&p5 ,"p3", 50);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p5, &c6);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER1->data);
  TEST_ASSERT_NULL(TAKEN_PAPER2);
  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , 
 *    however p3, p4 ,p5is no conflict to listA, and close to targetNum.
 *    But p4 and p5, are conflict to p3, so only take out p3 , in order to get perfect paper list
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(100)           p4(10)      p5(10)                          
 *            c3, c4             c3,c7       c4,c8   
 *              *               
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     perfectPapers = p3 
*/
void test_getPerfectPaperList_given_p4_p5_will_cause_conflict_to_p3_should_only_take_out_p3(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 100);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 10);
  addProgrammeToPaper(&p4, &c3);  
  addProgrammeToPaper(&p4, &c7);  
  
  setPaperTakersNum(&p5 ,"p3", 10);
  addProgrammeToPaper(&p5, &c4);
  addProgrammeToPaper(&p5, &c8);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER1->data);
  TEST_ASSERT_NULL(TAKEN_PAPER2);
  CLEAR_ALL_LIST;
}

/**   p3 , p4 and p5 no conflict to listA , 
 *    however p3, p4 ,p5is no conflict to listA, and close to targetNum.
 *    But p4 is conflict to p3, so only take out p3,p5 , in order to get perfect paper list
 * ****************************************************************   
 *  ( targetNum = 100 )
 *
 *  listA :    p1 
 *            c1, c2 
 *
 *  listB :    p3(100)           p4(10)      p5(10)                          
 *            c3, c4             c3,c7       c6,c8   
 *              *                             *
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     perfectPapers = p3 
*/
void test_getPerfectPaperList_given_p4_will_cause_conflict_to_p3_should_only_take_out_p3_p5(void){
  
  setPaperTakersNum(&p1 ,"p1", 50);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2);
  
  setPaperTakersNum(&p3 ,"p3", 100);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p3, &c4);
 
  setPaperTakersNum(&p4 ,"p4", 10);
  addProgrammeToPaper(&p4, &c3);  
  addProgrammeToPaper(&p4, &c7);  
  
  setPaperTakersNum(&p5 ,"p3", 10);
  addProgrammeToPaper(&p5, &c6);
  addProgrammeToPaper(&p5, &c8);
  
  listA = linkListNew(&p1);
  
  listB = linkListNew(&p5);
  addDataToHead(&listB, &p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  perfectPapers = getPerfectPaperList(listA, listB, &currentNum, 100);
  TEST_ASSERT_EQUAL_PTR( &p5, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data);
  TEST_ASSERT_NULL(TAKEN_PAPER3);
  CLEAR_ALL_LIST;
}
