#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "Mutation.h"

#define listA1  listA->next

#define S2_HEAD   s2.papers
#define S2_HEAD2  s2.papers->next

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


/**  Dont do Mutation : case 1
 *                              
 *  listA :    p1              p2                              
 *            c1,c2           c2,c3                  
 *                              *
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
 
  takenPaper = getTruePaperFromListA( &listA, &listB);
  TEST_ASSERT_EQUAL_PTR( &p2, takenPaper);
  TEST_ASSERT_EQUAL_PTR( &p1,listA->data);
  TEST_ASSERT_EQUAL_PTR( &p2,listA1->data);
  TEST_ASSERT_NULL(listA1);
  // TEST_ASSERT_EQUAL_PTR( &p2,S2_HEAD2->data);
  
  clearLinkList(&listA);
  clearLinkList(&listB);
  clearLinkList(&(p1.programmes));
  clearLinkList(&(p2.programmes));
  clearLinkList(&(p3.programmes));
  clearLinkList(&(p4.programmes));
}

