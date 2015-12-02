#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "RatioChecking.h"
#include "Mutation.h"
#include "printfStructs.h"

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_ALL_SESSION clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4;

void setUp(void){
  setProgramme(&c1,"c1", 0);
  setProgramme(&c2,"c2", 0);
  setProgramme(&c3,"c3", 0);
  setProgramme(&c4,"c4", 0);
  setProgramme(&c5,"c5", 0);
  setProgramme(&c6,"c6", 0);
  setProgramme(&c7,"c7", 0);
  setProgramme(&c8,"c8", 0);
  setProgramme(&c9,"c9", 0);
  setProgramme(&c10,"c10", 0);
  
  setPaperWithPopulation(&p1, "p1", 50);
  setPaperWithPopulation(&p2, "p2", 50);
  setPaperWithPopulation(&p3, "p3", 50);
  setPaperWithPopulation(&p4, "p4", 50);
  setPaperWithPopulation(&p5, "p5", 50);
  setPaperWithPopulation(&p6, "p6", 50);
  setPaperWithPopulation(&p7, "p7", 50);
  setPaperWithPopulation(&p8, "p8", 50);
  
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
}

void tearDown(void){
  
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_ALL_SESSION;
}


/**
  *     s1       s2      s3     s4
  *     p1       p3      p5     p7
  *     c1,      c1      c1     c1
  *
  *    0         0      0      0
  *
  *  each session has 0 conflict 
  *
  * fitnessSocre = 0
*/
void test_calFitnessScore_given_each_session_only_1paper_0_conflict_should_get_0(void){
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p5, &c1);
  addProgrammeToPaper(&p7, &c1);
  

  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p7);
  
  
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  int ans = calFitnessScore(list);
  TEST_ASSERT_EQUAL(0, ans);
  
  clearLinkList(&list); 
}

/**
  *       s1          s2         s3          s4
  *     p1,p2       p3,p4       p5,p6      p7,p8
  *     c1,c2       c1,c2       c1,c2      c1,c2
  *
  *       0           0           0           0
  *
  *  each session has 0 conflict 
  *
  * fitnessSocre = 0
*/
void test_calFitnessScore_given_0_conflict_should_get_0(void){
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p4, &c2);
  addProgrammeToPaper(&p5, &c1);
  addProgrammeToPaper(&p6, &c2);
  addProgrammeToPaper(&p7, &c1);
  addProgrammeToPaper(&p8, &c2);
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  int ans = calFitnessScore(list);
  TEST_ASSERT_EQUAL(0, ans);
  
  clearLinkList(&list); 
}

/** 
  *       s1          s2         s3          s4
  *     p1,p2       p3,p4       p5,p6      p7,p8
  *     c1,c1       c2,c2       c3,c3      c4,c4
  *
  *       1           1           1           1
  *
  *  each session has 1 conflict (first paper conflict to second paper)
  *
  * fitnessSocre = 4
*/
void test_calFitnessScore_given_4_conflict_should_get_4(void){
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c1);
  addProgrammeToPaper(&p3, &c2);
  addProgrammeToPaper(&p4, &c2);
  addProgrammeToPaper(&p5, &c3);
  addProgrammeToPaper(&p6, &c3);
  addProgrammeToPaper(&p7, &c4);
  addProgrammeToPaper(&p8, &c4);
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  int ans = calFitnessScore(list);
  TEST_ASSERT_EQUAL(4, ans);
  
  clearLinkList(&list); 
}


/** 
  *       s1             s2           s3          s4
  *     p1,p2,p3,p4  p1,p2,p3,p4   p1,p2,p3,p4   p1,p2,p3,p4  
  *     c1,c1,c2,c2  c1,c1,c2,c2   c1,c1,c2,c2   c1,c1,c2,c2
  *
  *       2              2              2           2
  *
  *  each session has 2 conflict ( 1st conflict to 2nd , 3rd conflict to 4th)
  *
  * fitnessSocre = 8
*/
void test_calFitnessScore_given_8_conflict_should_get_8(void){
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c1);
  addProgrammeToPaper(&p3, &c2);
  addProgrammeToPaper(&p4, &c2);


  addPaperToSession(&s1, &p4);
  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s2, &p2);
  addPaperToSession(&s2, &p1);
  addPaperToSession(&s3, &p4);
  addPaperToSession(&s3, &p3);
  addPaperToSession(&s3, &p2);
  addPaperToSession(&s3, &p1);
  addPaperToSession(&s4, &p4);
  addPaperToSession(&s4, &p3);
  addPaperToSession(&s4, &p2);
  addPaperToSession(&s4, &p1);
  
  
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  int ans = calFitnessScore(list);
  TEST_ASSERT_EQUAL(8, ans);
  
  clearLinkList(&list); 
}




/** 
  *       s1        s2         s3          s4
  *     p1,p2,p3  p1,p2,p3  p1,p2,p3  p1,p2,p3
  *     c1,c1,c1  c1,c1,c1  c1,c1,c1  c1,c1,c1 
  *
  *       3           3        3           3
  *
  *  each session has 3 conflict ( 1st to 2nd ad 3rd (2 conflict), 2nd conflict to 3rd (1 conflict))
  *
  * fitnessSocre = 12
*/
void test_calFitnessScore_given_12_conflict_should_get_12(void){
  
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c1);
  addProgrammeToPaper(&p3, &c1);


  addPaperToSession(&s1, &p3);
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s2, &p2);
  addPaperToSession(&s2, &p1);
  addPaperToSession(&s3, &p3);
  addPaperToSession(&s3, &p2);
  addPaperToSession(&s3, &p1);
  addPaperToSession(&s4, &p3);
  addPaperToSession(&s4, &p2);
  addPaperToSession(&s4, &p1);
  
  
  LinkedList *list = linkListNew(&s4);
  addDataToHead(&list, &s3);
  addDataToHead(&list, &s2);
  addDataToHead(&list, &s1);
  
  int ans = calFitnessScore(list);
  TEST_ASSERT_EQUAL(12, ans);
  
  clearLinkList(&list); 
}

