#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "Mutation.h"

#define CLEAR_ALL_LIST clearLinkList(&listA); clearLinkList(&listB); clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes));

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
LinkedList *listA, *listB;
Paper *takenPaper;

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


/**     takenPaper = getTruePaperFromListA( &listA, listB);  
 *                  
 *  listA :      NULL                        
 *                                                      
 *  listB :    p3              p4                            
 *            c1,c5          c5,c6               
 *                                
 *    listA is NULL , this function will return NULL
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = NULL
*/
void test_getTruePaperFromListA_given_ListA_is_NULL_should_return_NULL(void){
  
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
  
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_NULL(takenPaper);
  TEST_ASSERT_NULL(listA);

  CLEAR_ALL_LIST;
}

/**   takenPaper = getTruePaperFromListA( &listA, listB);    
 *                  
 *  listA :    p1              p2                              
 *            c1,c2           c2,c3                  
 *                       
 *
 *  listB :   NULL                        
 *                                                        
 *   listB is NULL. so will return 1st element of listA, which is p1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  listA :    p2                                          
 *           c2,c3     
 * 
 *     takenPaper = p1
*/
void test_getTruePaperFromListA_given_listB_is_NULL_should_return_first_elment_of_listA(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
    
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = NULL;
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
 
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_EQUAL_PTR( &p1, takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p2,listA->data);
  TEST_ASSERT_NULL(listA->next);

  CLEAR_ALL_LIST;
}

/**     takenPaper = getTruePaperFromListA( &listA, listB);  
 *                  
 *  listA :    p1              p2                              
 *            c1,c2           c2,c5                  
 *                              
 *
 *  listB :    p3              p4                            
 *            c1,c5          c5,c6               
 *                                
 *    listA elements are conflict with ListB, therefore the function need to return NULL
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *     takenPaper = NULL
*/
void test_getTruePaperFromListA_given_ListA_elements_are_conflict_with_listB_should_return_NULL(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c5);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
  
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_NULL(takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p1,listA->data);
  TEST_ASSERT_EQUAL_PTR( &p2,listA->next->data);

  CLEAR_ALL_LIST;
}
 
/**  takenPaper = getTruePaperFromListA( &listA, listB);
 *                     
 *  listA :    p1              p2                              
 *            c1,c2           c2,c3                  
 *                         (no conflict to listB)
 *
 *  listB :    p3              p4                            
 *            c1,c5          c5,c6               
 *                                
 *    p2 has no conflict with list2 , therefore it should take out from list1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  listA :    p1                                          
 *           c1,c2     
 * 
 *     takenPaper = p2
*/
void test_getTruePaperFromListA_given_p2_has_no_conflict_with_listB_should_take_out(void){
  
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
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
 
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_EQUAL_PTR( &p2, takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p1,listA->data);
  TEST_ASSERT_NULL(listA->next);

  CLEAR_ALL_LIST;
}


/**    takenPaper = getTruePaperFromListA( &listA, listB);
 *                    
 *  listA :         p1                             p2                              
 *                  c1,c2                        c2,c3                  
 *          (no conflict to listB)
 *
 *  listB :        p3                              p4                            
 *                c7,c5                          c5,c6               
 *                                
 *    p1 has no conflict with list2 , therefore it should take out from list1
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  listA :    p2                                          
 *           c2,c3     
 * 
 *     takenPaper = p1
*/
void test_getTruePaperFromListA_given_p1_has_no_conflict_with_listB_should_take_out(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c7);
  addProgrammeToPaper(&p3, &c5);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  listA = linkListNew(&p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p4);
  addDataToHead(&listB, &p3);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
 
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_EQUAL_PTR( &p1, takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p2,listA->data);
  TEST_ASSERT_NULL(listA->next);

  CLEAR_ALL_LIST;
}

/**    takenPaper = getTruePaperFromListA( &listA, listB);
 *                    
 *  listA :    p1              p2                             p3                   
 *            c1,c2           c2,c3                          c9,c10  
 *                      (no conflict to listB)        (no conflict to listB)
 *
 *  listB :    p4              p5             p6                     
 *            c1,c5          c5,c6          c7,c8   
 *                                
 *    p2 and p3 are no flict with ListB, but this function only return 1 paper,
 *    because p2 is in front of p3, so only will take out p2
 *        
 *    ---------------------OUTPUT----------------------------                            
 *                                
 *  listA :    p1          p3                           
 *           c1,c2       c9,c10
 * 
 *     takenPaper = p2
*/
void test_getTruePaperFromListA_given_p2_and_p3_has_no_conflict_with_listB_should_only_take_out_p2(void){
  
  setPaper(&p1 ,"p1");
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c2); 
  
  setPaper(&p2 ,"p2");
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p2, &c3);
  
  setPaper(&p3 ,"p3");
  addProgrammeToPaper(&p3, &c9);
  addProgrammeToPaper(&p3, &c10);
  
  setPaper(&p4 ,"p4");
  addProgrammeToPaper(&p4, &c1);  
  addProgrammeToPaper(&p4, &c5);  
  
  setPaper(&p5 ,"p5");
  addProgrammeToPaper(&p4, &c5);  
  addProgrammeToPaper(&p4, &c6);  
  
  setPaper(&p6 ,"p6");
  addProgrammeToPaper(&p4, &c7);  
  addProgrammeToPaper(&p4, &c8);  
  
  listA = linkListNew(&p3);
  addDataToHead(&listA, &p2);
  addDataToHead(&listA, &p1);

  listB = linkListNew(&p6);
  addDataToHead(&listB, &p5);
  addDataToHead(&listB, &p4);
  //--------------------------------THE ABOVE ARE THE ELEMENT INITIALIZATION---------------------------------------
 
  takenPaper = getTruePaperFromListA( &listA, listB);
  TEST_ASSERT_EQUAL_PTR( &p2, takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p1,listA->data);
  TEST_ASSERT_EQUAL_PTR( &p3,listA->next->data);
  TEST_ASSERT_NULL(listA->next->next);

  CLEAR_ALL_LIST;
}

