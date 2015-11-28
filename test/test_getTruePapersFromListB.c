#include "unity.h"
#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST clearLinkList(&(takenPapers)); clearLinkList(&listA); clearLinkList(&listB); clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); 
#define LISTB_HEAD  listB
#define LISTB_HEAD1 listB->next
#define LISTB_HEAD2 listB->next->next
#define LISTB_HEAD3 listB->next->next
#define LISTB_HEAD4 listB->next->next->next

#define TAKEN_PAPER1 takenPapers
#define TAKEN_PAPER2 takenPapers->next
#define TAKEN_PAPER3 takenPapers->next->next
#define TAKEN_PAPER4 takenPapers->next->next
#define TAKEN_PAPER5 takenPapers->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
LinkedList *listA, *listB, *takenPapers;

void setUp(void){}

void tearDown(void){}

/**    takenPapers = getTruePapersFromListB(LinkedList **listA, LinkedList *listB, int targetNum)
*
*       This function will return the takenPapers contain in ListB ,
*       the takenPapers does not cause conflict in ListA, 
*       and the numberStudent in takenPapers must within 120% of the targetNum, to prevent overflow 
*       if does not find the possible combo papers , then will return NULL
*/  

/**  listB is NULL , this function will return NULL
 * ****************************************************************   
 *
 *  listA :    p3              p4                            
 *            c1,c5          c5,c6   
 * 
 *  listB :    NULL                          
 *                              
 * ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = NULL
*/
void test_getTruePapersFromListB_given_ListB_is_NULL_should_return_NULL(void){
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  listB = NULL;
  
  listA = linkListNew(&p4);
  addDataToHead(&listA, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_NULL(takenPapers);
  TEST_ASSERT_NULL(LISTB_HEAD);

  CLEAR_ALL_LIST;
}

/**   ListB all elements conflict with listA, so return NULL
 * ****************************************************************   
 *                
 *  listA :    p1             p2                          
 *            c1,c5          c5,c6   
 * 
 *  listB :    p3              p4                            
 *            c1,c3          c5,c2               
 *                                      
 *  ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = NULL
*/
void test_getTruePapersFromListB_given_ListB_all_elements_conflict_with_listA_should_return_NULL(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c5); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c3);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c2);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_NULL(takenPapers);
  TEST_ASSERT_EQUAL_PTR( &p3, LISTB_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD1->data);
  TEST_ASSERT_NULL(LISTB_HEAD2);

  CLEAR_ALL_LIST;
}

/**   p3 does not conflict with listA, and studentNum in p3 is 140, 
 *    but targetNum is 100, which  cause overflow , therefore return NULL
 * ****************************************************************   
 *   ( targetNum = 100 )
 *                
 *  listA :    p1             p2                          
 *            c1,c5          c5,c6   
 * 
 *  listB :    p3              p4                            
 *            c7,c8          c5,c2               
 *            (140)                            
 *  ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = NULL
*/
void test_getTruePapersFromListB_given_ListB_1_element_not_conflict_with_listA_but_doesnt_meet_targetNum_should_return_NULL(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c5); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);
  
  // setPaperWithPopulation(Paper *target ,char *paperCode, int num) , tool function
  setPaperWithPopulation(&p3 ,"p3", 140);
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c8);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c2);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 100);
  TEST_ASSERT_NULL(takenPapers);
  TEST_ASSERT_EQUAL_PTR( &p3, LISTB_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD1->data);
  TEST_ASSERT_NULL(LISTB_HEAD2);

  CLEAR_ALL_LIST;
}

/**   p3 does not conflict with listA, and studentNum in p3 is 40, 
 *    and targetNum is 100, which within range, should take out p3
 * ****************************************************************   
 *   ( targetNum = 100 )
 *                
 *  listA :    p1             p2                          
 *            c1,c5          c5,c6   
 * 
 *  listB :    p3              p4                            
 *            c7,c8          c5,c2               
 *            (40)                            
 *  ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = p3
 *
 *  listB :   p4                            
 *          c5,c2               
 *             
*/
void test_getTruePapersFromListB_given_p3_not_conflict_with_listA_and__meet_targetNum_should_take_out(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c5); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);

  setPaperWithPopulation(&p3 ,"p3", 40);
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c8);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c2);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 100);
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER1->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD->data);
  TEST_ASSERT_NULL(LISTB_HEAD1);
  TEST_ASSERT_NULL(TAKEN_PAPER2);

  CLEAR_ALL_LIST;
}

/**   p3,p4 does not conflict with listA, and studentNum in p3,p4 are 40, 
 *    and targetNum is 100, which within range, should take out p3 and p4
 * ****************************************************************   
 *   ( targetNum = 100 )
 *                
 *  listA :    p1             p2                          
 *            c1,c5          c5,c6   
 * 
 *  listB :    p3              p4                            
 *            c7,c8          c3,c2               
 *            (40)            (40)                   
 *  ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = p3
 *
 *  listB :   p4                            
 *          c5,c2               
 *             
*/
void test_getTruePapersFromListB_given_p3_p4_not_conflict_with_listA_and_meet_targetNum_should_take_out(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c5); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c5);
  addProgrammeToPaper(&p2, &c6);

  setPaperWithPopulation(&p3 ,"p3", 40);
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c8);
  
  setPaperWithPopulation(&p4 ,"p4", 40);
  addProgrammeToPaper(&p4, &c3);  
  addProgrammeToPaper(&p4, &c2);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 100);
  TEST_ASSERT_EQUAL_PTR( &p4, TAKEN_PAPER1->data);   // because is addDataToHead(), so is Last in first out 
  TEST_ASSERT_EQUAL_PTR( &p3, TAKEN_PAPER2->data); 
  TEST_ASSERT_NULL(TAKEN_PAPER3);
  TEST_ASSERT_NULL(LISTB_HEAD1);


  CLEAR_ALL_LIST;
}

/**  listA is NULL , this function will return NULL
 * ****************************************************************    
 *
 *    listA :      NULL                        
 *                                                      
 *    listB :    p3              p4                            
 *             c1,c5          c5,c6               
 *                                       
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPapers = NULL
*/
void xtest_getTruePapersFromListB_given_ListA_is_NULL_should_return_NULL(void){
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  listA = NULL;
  
  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPapers = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_NULL(takenPapers);
  TEST_ASSERT_EQUAL_PTR( &p3, LISTB_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD1->data);
  TEST_ASSERT_NULL(LISTB_HEAD2);

  CLEAR_ALL_LIST;
}

