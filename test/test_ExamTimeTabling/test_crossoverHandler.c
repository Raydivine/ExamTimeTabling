#include "unity.h"
#include "ExamTimeTabling.h"
#include "CreatePopulation.h"
#include "ExamStruct.h"
#include "SetElements.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "PaperListConvertion.h"
#include "CalFitnessScore.h"
#include "RatioChecking.h"
#include "Mutation.h"
#include "Crossover.h"
#include "mock_Random.h"
#include "printfStructs.h"

#define TOTAL_PAPERS sizeof(papersArr)/sizeof(*papersArr)
#define TOTAL_SAMPLES sizeof(population)/sizeof(*population)
#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_SESSION_1_TO_4 clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));
#define CLEAR_SESSION_5_TO_8 clearLinkList(&(s5.papers)); clearLinkList(&(s6.papers)); clearLinkList(&(s7.papers)); clearLinkList(&(s8.papers));

#define S1 population[TOTAL_SAMPLES-1]->sessions
#define S2 population[TOTAL_SAMPLES-1]->sessions->next
#define S3 population[TOTAL_SAMPLES-1]->sessions->next->next
#define S4 population[TOTAL_SAMPLES-1]->sessions->next->next->next
#define S5 population[TOTAL_SAMPLES-1]->sessions->next->next->next->next
#define S6 population[TOTAL_SAMPLES-1]->sessions->next->next->next->next->next
#define S7 population[TOTAL_SAMPLES-1]->sessions->next->next->next->next->next->next

// The below define are the paper sequence in session
//  example:  S1_1  = session1's first paper
//  example:  S1_2  = session1's second paper
//  example:  S2_1  = session2's first paper
#define S1_1 ((Session*)S1->data)->papers
#define S1_2 ((Session*)S1->data)->papers->next
#define S1_3 ((Session*)S1->data)->papers->next->next
#define S1_4 ((Session*)S1->data)->papers->next->next->next
#define S1_5 ((Session*)S1->data)->papers->next->next->next->next
#define S1_6 ((Session*)S1->data)->papers->next->next->next->next->next
#define S1_7 ((Session*)S1->data)->papers->next->next->next->next->next->next
#define S1_8 ((Session*)S1->data)->papers->next->next->next->next->next->next->next
#define S1_9 ((Session*)S1->data)->papers->next->next->next->next->next->next->next->next
#define S1_10 ((Session*)S1->data)->papers->next->next->next->next->next->next->next->next->next

#define S2_1 ((Session*)S2->data)->papers
#define S2_2 ((Session*)S2->data)->papers->next
#define S2_3 ((Session*)S2->data)->papers->next->next
#define S2_4 ((Session*)S2->data)->papers->next->next->next
#define S2_5 ((Session*)S2->data)->papers->next->next->next->next
#define S2_6 ((Session*)S2->data)->papers->next->next->next->next->next
#define S2_7 ((Session*)S2->data)->papers->next->next->next->next->next->next

#define S3_1 ((Session*)S3->data)->papers
#define S3_2 ((Session*)S3->data)->papers->next
#define S3_3 ((Session*)S3->data)->papers->next->next
#define S3_4 ((Session*)S3->data)->papers->next->next->next
#define S3_5 ((Session*)S3->data)->papers->next->next->next->next
#define S3_6 ((Session*)S3->data)->papers->next->next->next->next->next
#define S3_7 ((Session*)S3->data)->papers->next->next->next->next->next->next

#define S4_1 ((Session*)S4->data)->papers
#define S4_2 ((Session*)S4->data)->papers->next
#define S4_3 ((Session*)S4->data)->papers->next->next
#define S4_4 ((Session*)S4->data)->papers->next->next->next
#define S4_5 ((Session*)S4->data)->papers->next->next->next->next
#define S4_6 ((Session*)S4->data)->papers->next->next->next->next->next
#define S4_7 ((Session*)S4->data)->papers->next->next->next->next->next->next


Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4,s5,s6,s7,s8;
Table *tableA, *tableB;

Table *population[5];
const int sizeSession = 100;

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
  
  setPaperTakersNum(&p1, "p1", 50);
  setPaperTakersNum(&p2, "p2", 50);
  setPaperTakersNum(&p3, "p3", 50);
  setPaperTakersNum(&p4, "p4", 50);
  setPaperTakersNum(&p5, "p5", 50);
  setPaperTakersNum(&p6, "p6", 50);
  setPaperTakersNum(&p7, "p7", 50);
  setPaperTakersNum(&p8, "p8", 50);
  
  addProgrammeToPaper(&p1, &c2);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p2, &c3);
  addProgrammeToPaper(&p2, &c2);
  addProgrammeToPaper(&p3, &c4);
  addProgrammeToPaper(&p3, &c3);
  addProgrammeToPaper(&p4, &c5);
  addProgrammeToPaper(&p4, &c4);
  addProgrammeToPaper(&p5, &c6);
  addProgrammeToPaper(&p5, &c5);
  addProgrammeToPaper(&p6, &c7);
  addProgrammeToPaper(&p6, &c6);
  addProgrammeToPaper(&p7, &c8);
  addProgrammeToPaper(&p7, &c7); 
  addProgrammeToPaper(&p8, &c1);
  addProgrammeToPaper(&p8, &c8);
  
  s1 = createSession();
  s2 = createSession();
  s3 = createSession();
  s4 = createSession();
  s5 = createSession();
  s6 = createSession();
  s7 = createSession();
  s8 = createSession();
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  addPaperToSession(&s5, &p3);
  addPaperToSession(&s5, &p7);
  addPaperToSession(&s6, &p1);
  addPaperToSession(&s6, &p5);
  addPaperToSession(&s7, &p2);
  addPaperToSession(&s7, &p8);
  addPaperToSession(&s8, &p6);
  addPaperToSession(&s8, &p4);
  
  tableA = createDynamicTable();
  addSessionToTable(tableA, &s4);
  addSessionToTable(tableA, &s3);
  addSessionToTable(tableA, &s2);
  addSessionToTable(tableA, &s1);
  
  tableB = createDynamicTable();
  addSessionToTable(tableB, &s8);
  addSessionToTable(tableB, &s7);
  addSessionToTable(tableB, &s6);
  addSessionToTable(tableB, &s5);
  
/** Table A
  *
  *               s1           |          s2         |         s3          |        s4
  *           p1,       p2    |     p3,      p4     |    p5,       p6     |     p7,      p8
  *         c1,c2     c2,c3  |   c3,c4     c4,c5   |   c5,c6     c6,c7   |    c7,c8      c8,c1
  *
  * -------------------------------------------------------------------------------------------
  * Table B
  *
  *               s5           |          s6         |         s7          |        s8
  *           p7,        p3   |     p5,      p1     |    p8,       p2     |     p4,      p6
  *         c7,c8       c3,c4 |   c5,c6    c1,c2    |   c8,c1    c2,c3   |    c4,c5      c6,c7
  *
  * 
  * The 2 table share to all test
*/

  population[5];
  population[0] = tableA;
  population[1] = tableB;
  population[2] = tableA;
  population[3] = tableB;
  //population[4] will declare in test functin for testing
}

void tearDown(void){
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_SESSION_1_TO_4;
  CLEAR_SESSION_5_TO_8;
  clearLinkList(&(tableA->sessions)); 
  clearLinkList(&(tableB->sessions)); 
}


/**   void crossoverHandler(Table *population[], Paper *target, int sizePopulation, int sizeSession)
*
*     This funciton used to handle croosover process 
*      population[] is the samples of table
*      target is the crossover point to do crossover
*      number of samples is population size
*      sizeSession is the maxium seat in the school, which means the maximum number of student having exam in same period
*
*       while running the process, randomly select two table to do crossover, then produce a child
*       if the child has lest fitnessScore than the last seat of population,
*       then the child will replace the seat
*/

/**                       target = p5 , sizeSession = 100;
  * 
  *
  * Table A      p1   p2    p3    p4    p5   p6    p7    p8
  *                   <-----------------X                                       
  *                                
  * Table B      p7   p3    p5    p1    p8    p2    p4    p6
  *                         X----------->    break                                
  *           
  * 
  * output list  =   p2  p3  p4  p5  p1  p8  (p7   p6)  
  *                                           added mising element from tableA     
  *
  * ----------the outputList( crossoverList) converted to child (crossoveredTable)----------------
  *  child
  *
  *               s1           |          s2         |         s3          |        s4
  *           p2,       p3    |     p4,      p5     |    p1,       p8     |     p7,      p6
  *      
  * 
*/
void test_crossoverHandler_last_seat_fitnessScore_is_100_which_larger_than_child_should_be_replace(void){
  Table lastSeat;
  lastSeat.sessions = NULL;
  lastSeat.fitnessScore = 100; 
  population[4] = &lastSeat;  // manually set the last seat has high fitnessScore, so it sure replaced by croosoverChild
  
  random_IgnoreAndReturn(0);  // Notice : 0 == 2, 1 == 3, 4 == null
  random_IgnoreAndReturn(1);  // if mock 2 same number, then will forever stuck in while loop
  crossoverHandler( population, &p5, TOTAL_SAMPLES, sizeSession);
  
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NOT_NULL(S4);
  TEST_ASSERT_NULL(S5);
 
  TEST_ASSERT_EQUAL_PTR(&p2, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S2_2->data);
  TEST_ASSERT_EQUAL_PTR(&p1, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S3_2->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S4_1->data); 
  TEST_ASSERT_EQUAL_PTR(&p6, S4_2->data); 
  
  TEST_ASSERT_NULL(S1_3);
  TEST_ASSERT_NULL(S2_3);
  TEST_ASSERT_NULL(S3_3);
  TEST_ASSERT_NULL(S4_3);
}

void test_crossoverHandler_given_mock_2_1_should_get_same_result_of_test1(void){
  Table lastSeat;
  lastSeat.sessions = NULL;
  lastSeat.fitnessScore = 100; 
  population[4] = &lastSeat;  // manually set the last seat has high fitnessScore, so it sure replaced by croosoverChild
  
  random_IgnoreAndReturn(2);  // Notice : 0 == 2, 1 == 3, 4 == null
  random_IgnoreAndReturn(1);  // if mock 2 same number, then will forever stuck in while loop
  crossoverHandler( population, &p5, TOTAL_SAMPLES, sizeSession);
  
  TEST_ASSERT_NOT_NULL(S1);
  TEST_ASSERT_NOT_NULL(S2);
  TEST_ASSERT_NOT_NULL(S3);
  TEST_ASSERT_NOT_NULL(S4);
  TEST_ASSERT_NULL(S5);
 
  TEST_ASSERT_EQUAL_PTR(&p2, S1_1->data);
  TEST_ASSERT_EQUAL_PTR(&p3, S1_2->data);
  TEST_ASSERT_EQUAL_PTR(&p4, S2_1->data);
  TEST_ASSERT_EQUAL_PTR(&p5, S2_2->data);
  TEST_ASSERT_EQUAL_PTR(&p1, S3_1->data);
  TEST_ASSERT_EQUAL_PTR(&p8, S3_2->data);
  TEST_ASSERT_EQUAL_PTR(&p7, S4_1->data); 
  TEST_ASSERT_EQUAL_PTR(&p6, S4_2->data); 
  
  TEST_ASSERT_NULL(S1_3);
  TEST_ASSERT_NULL(S2_3);
  TEST_ASSERT_NULL(S3_3);
  TEST_ASSERT_NULL(S4_3);
}

void test_crossoverHandler_last_seat_fitnessScore_is_0_which_smaller_than_child_should_not_replace(void){
  Table lastSeat;
  lastSeat.sessions = NULL;
  lastSeat.fitnessScore = 0; 
  population[4] = &lastSeat;  // manually set the last seat has small fitnessScore, so it wpont replaced by croosoverChild
  
  random_IgnoreAndReturn(1);  // Notice : 0 == 2, 1 == 3, 4 == null
  random_IgnoreAndReturn(3);
  crossoverHandler( population, &p5, 4, sizeSession);
  
  TEST_ASSERT_NULL(S1);
}