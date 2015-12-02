#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"
 
#define CLEAR_ALL_SESSION clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers)); clearLinkList(&(session.papers));

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4, session;

LinkedList *slist, *plist;

void setUp(void){

  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  slist = linkListNew(&s4);
  addDataToHead(&slist, &s3);
  addDataToHead(&slist, &s2);
  addDataToHead(&slist, &s1);
  
  /** The share structrure show below
  *
  *       s1          s2         s3          s4
  *     p1,p2       p3,p4       p5,p6      p7,p8
  */
}

void tearDown(void){
  
  CLEAR_ALL_SESSION;
  clearLinkList(&slist);
  clearLinkList(&plist);
}

/**  
*     int isElementsNotInChild(LinkedList *sList, Session s)
*    
*     checl is s.papers already in sList, if yes return 0 , if no return 1
*
*/ 



/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = p9
 * 
 *   plist's element not in slist  , return 1
*/

void test_isElementsNotInChild_plist_has_p9_which_not_in_slist_should_return1(void){
  plist = linkListNew(&p9);
  
  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(1, ans);
}

/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = p9,p10
 * 
 *   plist's element not in slist  , return 1
*/

void test_isElementsNotInChild_plist_has_p9_p10_which_not_in_slist_should_return1(void){
  plist = linkListNew(&p9);
  addDataToHead(&plist, &p10);
  
  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(1, ans);
}

/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = NULL
 * 
 *   plist's element not in slist  , return 1
*/

void test_isElementsNotInChild_plist_NULL_which_not_in_slist_should_return1(void){
  plist = NULL;
  
  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(1, ans);
}

/** 
 *    slist                                                    
 *     NULL       
 *     
 * 
 *   pList = p1
 * 
 *   plist's element  in slist , return 0
*/

void test_isElementsNotInChild_slist_NULL_which_in_slist_should_return1(void){
  plist = linkListNew(&p1);
  slist = NULL;

  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(1, ans);
}


/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = p1
 * 
 *   plist's element  in slist , return 0
*/

void test_isElementsNotInChild_plist_has_p1_which_in_slist_should_return0(void){
  plist = linkListNew(&p1);

  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(0, ans);
}

/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = p8
 * 
 *   plist's element  in slist , return 0
*/

void test_isElementsNotInChild_plist_has_p8_which_in_slist_should_return0(void){
  plist = linkListNew(&p8);

  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(0, ans);
}

/** 
 *    slist                                                    
 *       s1          s2         s3          s4           
 *     p1,p2       p3,p4       p5,p6      p7,p8   
 * 
 *   pList = p4,p7
 * 
 *   plist's element not in slist  , return 0
*/

void test_isElementsNotInChild_plist_has_p4_p7_which_in_slist_should_return0(void){
  plist = linkListNew(&p4);
  addDataToHead(&plist, &p7);
  
  int ans =  isElementsNotInChild(slist, plist);
  TEST_ASSERT_EQUAL(0, ans);
}