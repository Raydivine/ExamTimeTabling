#include "unity.h"
#include "CalConflict.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST clearLinkList(&listA); clearLinkList(&listB); clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes));
#define LISTB_HEAD  listB
#define LISTB_HEAD1 listB->next
#define LISTB_HEAD2 listB->next->next
#define LISTB_HEAD3 listB->next->next
#define LISTB_HEAD4 listB->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
LinkedList *listA, *listB, *paperList;

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


/**    paperList = getTruePapersFromListB(LinkedList **listA, LinkedList *listB, int targetNum)
*
*       This function will return the paperList contain in ListB ,
*       the paperList does not cause conflict in ListA, 
*       and the numberStudent in paperList must within 20% to the targetNum
*
*        NumberStudent - targetNum    x   100 %      <= 20          , meet the range condition 
*        -------------------------     
*               targetNum
*
*       if does not find the possible combo, then will return NULL
*/  

/**  listA is NULL , this function will return NULL
 * ****************************************************************    
 *
 *     listA :      NULL                        
 *                                                      
 *    listB :    p3              p4                            
 *             c1,c5          c5,c6               
 *                                       
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *     paperList = NULL
*/
void test_getTruePapersFromListB_given_ListA_is_NULL_should_return_NULL(void){
  
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
  
  paperList = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_NULL(paperList);
  TEST_ASSERT_EQUAL_PTR( &p3, LISTB_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD1->data);
  TEST_ASSERT_NULL(LISTB_HEAD2);

  CLEAR_ALL_LIST;
}


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
 *     paperList = NULL
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
  
  paperList = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_NULL(paperList);
  TEST_ASSERT_NULL(LISTB_HEAD);

  CLEAR_ALL_LIST;
}

/**   targetNum is 100, p3 does not conflict with listA
 * 
 *   but studentNum in p3 is 60, 
 *
 *    which does not meet the targetNum,
 *   therefore return NULL
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
  
  paperList = getTruePapersFromListB(listA, &listB, 30);
  TEST_ASSERT_EQUAL_PTR( &p3, LISTB_HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LISTB_HEAD1->data);
  TEST_ASSERT_NULL(LISTB_HEAD2);

  CLEAR_ALL_LIST;
}

