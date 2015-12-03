#include "unity.h"
#include "BuildSessionList.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

#define sList   sList
#define sList1  sList->next
#define sList2  sList->next->next
#define sList3  sList->next->next->next
#define sList4  sList->next->next->next->next
#define sList5  sList->next->next->next->next->next
#define sList6  sList->next->next->next->next->next->next
#define sList7  sList->next->next->next->next->next->next->next
#define sList8  sList->next->next->next->next->next->next->next->next
#define sList9  sList->next->next->next->next->next->next->next->next->next
#define sList10 sList->next->next->next->next->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *pList, *sList;

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
  
  pList = linkListNew(&p10);
  addDataToHead(&pList, &p9);
}

void tearDown(void){
  clearLinkList(&pList);
//  clearLinkList(&sList);
}

void test_buildSessionListFromPaperList_given_population_is_50_should_create_10_session(void){
  
	sList = buildSessionListFromPaperList(pList, 50);
}
