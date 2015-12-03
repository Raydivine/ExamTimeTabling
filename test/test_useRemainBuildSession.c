#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"
 
 
#define HEAD  s.papers
#define HEAD1 s.papers->next
#define HEAD2 s.papers->next->next
#define HEAD3 s.papers->next->next->next
#define HEAD4 s.papers->next->next->next->next
#define HEAD5 s.papers->next->next->next->next->next
#define HEAD6 s.papers->next->next->next->next->next->next


#define LIST  remains
#define LIST1 remains->next
#define LIST2 remains->next->next
#define LIST3 remains->next->next->next
#define LIST4 remains->next->next->next->next
#define LIST5 remains->next->next->next->next->next
#define LIST6 remains->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
LinkedList *remains;

void setUp(void){
  setPaperTakersNum(&p1, "p1", 50);
  setPaperTakersNum(&p2, "p2", 50);
  setPaperTakersNum(&p3, "p3", 50);
  setPaperTakersNum(&p4, "p4", 50);

  remains = linkListNew(&p4);
  addDataToHead(&remains, &p3);
  addDataToHead(&remains, &p2);
  addDataToHead(&remains, &p1);
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
  *  num = 50 
  *
  *  Because each paper has 50 person, so s.papers should have p1 only
  *
  *----------------output-------------------
  *
  * remains = p2,p3,p4
  *
  *    s.papers = p1 
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_50_should_build_session_with_p1(void){
 
  Session s = useRemainBuildSession(&remains, 50);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_NULL(HEAD1);
  
  TEST_ASSERT_EQUAL_PTR( &p2, LIST->data);
  TEST_ASSERT_EQUAL_PTR( &p3, LIST1->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LIST2->data);
  TEST_ASSERT_NULL(LIST3);
  
  clearLinkList(&(s.papers));
}

/**  remains = p1,p2,p3,p4
  *
  *  num = 75 
  *
  *  Because each paper has 50 person, so s.papers should have p1 only
  *
  *----------------output-------------------
  *
  * remains = p2,p3,p4
  *
  *    s.papers = p1 
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_75_which_only_allow_1_session_should_build_session_with_p1(void){
    
  Session s = useRemainBuildSession(&remains, 75);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD->data);
  TEST_ASSERT_NULL(HEAD1);
  
  TEST_ASSERT_EQUAL_PTR( &p2, LIST->data);
  TEST_ASSERT_EQUAL_PTR( &p3, LIST1->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LIST2->data);
  TEST_ASSERT_NULL(LIST3);
  
  clearLinkList(&(s.papers));
}

/**  remains = p1,p2,p3,p4
  *
  *  num = 100 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2
  *
  *----------------output-------------------
  *
  * remains = p3,p4
  *
  *    s.papers = p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_100_should_build_session_with_p1_p2(void){
    
  Session s = useRemainBuildSession(&remains, 100);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
  TEST_ASSERT_NULL(HEAD2);
  
  TEST_ASSERT_EQUAL_PTR( &p3, LIST->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LIST1->data);
  TEST_ASSERT_NULL(LIST2);
  clearLinkList(&(s.papers));
}

/**  remains = p1,p2,p3,p4
  *
  *  num = 130 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2
  *
  *----------------output-------------------
  *
  * remains = p3,p4
  *
  *    s.papers = p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_130_maximum_can_put_in_2_should_build_session_with_p1_p2(void){
  
  Session s = useRemainBuildSession(&remains, 130);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD1->data);
  TEST_ASSERT_NULL(HEAD2);
  
  TEST_ASSERT_EQUAL_PTR( &p3, LIST->data);
  TEST_ASSERT_EQUAL_PTR( &p4, LIST1->data);
  TEST_ASSERT_NULL(LIST2);
  clearLinkList(&(s.papers));
}



/**  remains = p1,p2,p3,p4
  *
  *  num = 150 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2,p3
  *
  *----------------output-------------------
  *
  * remains = p4
  *
  *    s.papers = p3,p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_150_should_build_session_with_p1_p2_p3(void){
    
  Session s = useRemainBuildSession(&remains, 150);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
  TEST_ASSERT_NULL(HEAD3);
  
  TEST_ASSERT_EQUAL_PTR( &p4, LIST->data);
  TEST_ASSERT_NULL(LIST1);
  clearLinkList(&(s.papers));
}


/**  remains = p1,p2,p3,p4
  *
  *  num = 175 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2,p3
  *
  *----------------output-------------------
  *
  * remains = p4
  *
  *    s.papers = p3,p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_175_only_can_put_in_3_should_build_session_with_p1_p2_p3(void){
    
  Session s = useRemainBuildSession(&remains, 175);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD2->data);
  TEST_ASSERT_NULL(HEAD3);
  
  TEST_ASSERT_EQUAL_PTR( &p4, LIST->data);
  TEST_ASSERT_NULL(LIST1);
  clearLinkList(&(s.papers));
}

/**  remains = p1,p2,p3,p4
  *
  *  num = 200 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2,p3,p4
  *
  *----------------output-------------------
  *
  * remains = null
  *
  *    s.papers = p4,p3,p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_200_should_build_session_with_p1_p2_p3_p4(void){
  
  Session s = useRemainBuildSession(&remains, 200);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD3->data);
  TEST_ASSERT_NULL(HEAD4);
  
  TEST_ASSERT_NULL(LIST);
  clearLinkList(&(s.papers));
}

/**  remains = p1,p2,p3,p4
  *
  *  num = 250 
  *
  *  Because each paper has 50 person, so s.session should have p1,p2,p3,p4
  *
  *----------------output-------------------
  *
  * remains = null
  *
  *    s.papers = p4,p3,p2,p1
  *               
  * 
*/
void test_useRemainBuildSession_given_num_is_250__which_use_all_the_remains_should_left_remains_null(void){
  
  Session s = useRemainBuildSession(&remains, 250);
  TEST_ASSERT_EQUAL_PTR( &p4, HEAD->data);
  TEST_ASSERT_EQUAL_PTR( &p3, HEAD1->data);
  TEST_ASSERT_EQUAL_PTR( &p2, HEAD2->data);
  TEST_ASSERT_EQUAL_PTR( &p1, HEAD3->data);
  TEST_ASSERT_NULL(HEAD4);
  
  TEST_ASSERT_NULL(LIST);
  clearLinkList(&(s.papers));
}

void test_useRemainBuildSession_given_remains_NULL_should_return_Session_with_nothing(void){
  
  remains = NULL;
  Session s = useRemainBuildSession(&remains, 250);
  TEST_ASSERT_NULL(HEAD);
  
  TEST_ASSERT_NULL(LIST);
  clearLinkList(&(s.papers));
}

//Notice : This test will cause error, because the number is 10, which small than
//         papers.takersNum (50), the assertion() is used in its program
void xtest_useRemainBuildSession_given_num_is_10_which_less_than_papers_takerNum(void){
  
  Session s = useRemainBuildSession(&remains, 10);

}