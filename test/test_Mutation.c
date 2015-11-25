#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "Mutation.h"

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

Session session;

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


  LinkedList *takersP6 = linkListNew(&c2);
  addDataToHead(&takersP6, &c3);
  addDataToHead(&takersP6, &c4);
  setPaper(&p6, "p6", takersP6);
  
}

void tearDown(void){}


/**  Dont do Mutation : case 1
 *                              
 *  Session1 :    p1              p2              p3           p4         
 *               c1,c2           c3,c4          c4,c5        c6,c7    
 *
 *  Session2 :    p5              p6              p7           p8         
 *               c2,c5           c7,c4          c2,c3        c1,c6   
 * 
 *   Session1 and Session2 all elements are confict with each other, their programmes element already exist in other session, 
 *   so no matter how exchange will just only cause confict, therefore should not do mutation
*/
void test_mutateInTwoSessions_given_the_2session_all_element_conflict_with_other_should_not_do_Mutation(void){
  
  
}

