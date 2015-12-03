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

void setUp(void){
  setPaperTakersNum(&p1, "p1", 50);
  setPaperTakersNum(&p2, "p2", 50);
  setPaperTakersNum(&p3, "p3", 50);
  setPaperTakersNum(&p4, "p4", 50);
  setPaperTakersNum(&p5, "p5", 50);
  setPaperTakersNum(&p6, "p6", 50);
  setPaperTakersNum(&p7, "p7", 50);
  setPaperTakersNum(&p8, "p8", 50);
  setPaperTakersNum(&p9, "p9", 50);
  setPaperTakersNum(&p10, "p10", 50);
}

void tearDown(void){
  clearLinkList(&remains);
}

/**  s = Session useRemainBuildSession(LinkedList **remain, int num)
*
*    use remain's element to build session ( which remain is paperList),
*    the session's population must <= num,
*    while building session , remain elements are reducing
*    finally, return the session to s
*/ 

/**  remains = p1,p2,p3,p4
  *
  *  population = 50 
  *
  *  Because each paper has 50 person, so should build 1 session 
  *
  *----------------output-------------------
  *
  * remains = p2,p3,p4
  *
  *    s 
  *   p1             
  * 
*/
void test_useRemainBuildSession_should_build_session_with_p1(void){
  
   
  remains = linkListNew(&p4);
  addDataToHead(&remains, &p3);
  addDataToHead(&remains, &p2);
  addDataToHead(&remains, &p1);
  
  Session s = useRemainBuildSession(&remains, 50);
 
}
