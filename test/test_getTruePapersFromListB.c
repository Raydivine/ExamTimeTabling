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



