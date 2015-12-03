#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"
 
 
#define HEAD  child.sessions
#define HEAD1 child.sessions->next
#define HEAD2 child.sessions->next->next
#define HEAD3 child.sessions->next->next->next
#define HEAD4 child.sessions->next->next->next->next
#define HEAD5 child.sessions->next->next->next->next->next
#define HEAD6 child.sessions->next->next->next->next->next->next


#define LIST  remains
#define LIST1 remains->next
#define LIST2 remains->next->next
#define LIST3 remains->next->next->next
#define LIST4 remains->next->next->next->next
#define LIST5 remains->next->next->next->next->next
#define LIST6 remains->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *remains, *sList;
Table child;

void setUp(void){
  setPaperWithPopulation(&p1, "p1", 50);
  setPaperWithPopulation(&p2, "p2", 50);
  setPaperWithPopulation(&p3, "p3", 50);
  setPaperWithPopulation(&p4, "p4", 50);
  setPaperWithPopulation(&p5, "p5", 50);
  setPaperWithPopulation(&p6, "p6", 50);
  setPaperWithPopulation(&p7, "p7", 50);
  setPaperWithPopulation(&p8, "p8", 50);
  setPaperWithPopulation(&p9, "p9", 50);
  setPaperWithPopulation(&p10, "p10", 50);
  
  remains = linkListNew(&p10);
  addDataToHead(&remains, &p9);
}

void tearDown(void){
  clearLinkList(&remains);
  clearLinkList(&(child.sessions));

}


/**  addRemainToChild(Table *child, LinkedList *remains, int population)
*
*    This function add remains(paperList) to child,
*    First, it build the Session by using element in paperList (while Session's totalStudent must <= population)
*    , then add the session to table, this process continuously until all the remains are added to child.
*    
*    Input Condition
*    1. remains must not has repeated element in child ( this feature is handle by previous function, buildChildTable() )
*    2. population must larger then unit paper's studentNum
*/ 

/**  parrent = p1,p2,p3,p4
  *
  *  child =  NULL
  *
  *  population = 50 
  *
  *  Because each paper has 50 person, so should build 4 session 
  *
  *----------------output-------------------
  *
  *     child =   s1  s2  s3  s4
  *               p1  p2  p3  p4
  * 
*/
void xtest_addRemainToChild_should_build_child_with_4_session(void){
  
  remains = linkListNew(&p4);
  addDataToHead(&remains, &p3);
  addDataToHead(&remains, &p2);
  addDataToHead(&remains, &p1);
  
  
  
  //-------------------------------------------------------------------------------------------
}
