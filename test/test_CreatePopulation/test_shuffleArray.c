#include "unity.h"
#include "CreatePopulation.h"
#include "ExamStruct.h"
#include "SetElements.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "mock_Random.h"
#include "printfStructs.h"
#include "CalFitnessScore.h"
#include "PaperListConvertion.h"


#define SIZE sizeof(papersArr)/sizeof(*papersArr)

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 

#define HEAD  pList
#define HEAD1 pList->next
#define HEAD2 pList->next->next
#define HEAD3 pList->next->next->next
#define HEAD4 pList->next->next->next->next
#define HEAD5 pList->next->next->next->next->next
#define HEAD6 pList->next->next->next->next->next->next
#define HEAD7 pList->next->next->next->next->next->next->next
#define HEAD8 pList->next->next->next->next->next->next->next->next
#define HEAD9 pList->next->next->next->next->next->next->next->next->next
#define HEAD10 pList->next->next->next->next->next->next->next->next->next->next

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

void setUp(void){
  
  //void setProgramme(Programme *target ,char *programmeName, int numStudent)
  setProgramme(&c1,"c1", 100);
  setProgramme(&c2,"c2", 80);
  setProgramme(&c3,"c3", 90);
  setProgramme(&c4,"c4", 75);
  setProgramme(&c5,"c5", 70);    // Total student = 415
 
  setPaper(&p1, "p1");
  setPaper(&p2, "p2");
  setPaper(&p3, "p3");
  setPaper(&p4, "p4");
  setPaper(&p5, "p5");
  setPaper(&p6, "p6");
  setPaper(&p7, "p7");
  setPaper(&p8, "p8");
  setPaper(&p9, "p9");
  setPaper(&p10, "p10");
  
  addProgrammeToPaper(&p1, &c2);
  addProgrammeToPaper(&p1, &c1);
  addProgrammeToPaper(&p1, &c3);
  
  addProgrammeToPaper(&p2, &c4);
  addProgrammeToPaper(&p2, &c5);
  
  addProgrammeToPaper(&p3, &c1);
  addProgrammeToPaper(&p3, &c5);
  
  addProgrammeToPaper(&p4, &c3);
  addProgrammeToPaper(&p4, &c4);
  
  addProgrammeToPaper(&p5, &c2);
  addProgrammeToPaper(&p5, &c4);
  addProgrammeToPaper(&p5, &c3);
  
  addProgrammeToPaper(&p6, &c1);
  addProgrammeToPaper(&p6, &c2);
  addProgrammeToPaper(&p6, &c3);
  addProgrammeToPaper(&p6, &c4);
  addProgrammeToPaper(&p6, &c5);
  
  addProgrammeToPaper(&p7, &c4);
  addProgrammeToPaper(&p7, &c3); 
  addProgrammeToPaper(&p7, &c1); 
  
  addProgrammeToPaper(&p8, &c2);
  addProgrammeToPaper(&p8, &c5);
  addProgrammeToPaper(&p8, &c1);
  
  addProgrammeToPaper(&p9, &c2);
  addProgrammeToPaper(&p9, &c3);
  addProgrammeToPaper(&p9, &c5);
  
  addProgrammeToPaper(&p10, &c4);
  addProgrammeToPaper(&p10, &c5);
  addProgrammeToPaper(&p10, &c2);
  addProgrammeToPaper(&p10, &c1);
  
/** p : paper , c : programme
  *
  *             p1       p2         p3        p4       p5       p6        p7        p8        p9       p10
  *  ----------------------------------------------------------------------------------------------------
  *             c1       c4         c1        c3      c2        c1        c4        c2        c2       c4
  *             c2       c5         c5        c4      c4        c2        c3        c5        c3       c5
  *             c3                                    c3        c3        c1        c1        c5       c2
  *                                                             c4                                     c1
  *                                                             c5
  *Stundet:    270      145        170       165      245      417       265       250        240     325    
  *
  *Total examiner = 2492
  *
  *TotalSeat in school = 500
*/
}

void tearDown(void){
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
}


void test_shuffleArray_given_papersArr_are_no_shuffle_because_random_number_are_same_as_i(void){
	Paper *papersArr[] = { &p1,&p2,&p3,&p4,&p5};
  
  random_IgnoreAndReturn(0);
  random_IgnoreAndReturn(1);
  random_IgnoreAndReturn(2);
  random_IgnoreAndReturn(3);
  random_IgnoreAndReturn(4);  // the number return is same as the i in for loop, therefore is no shuffering
  shuffleArray( papersArr, SIZE);
  
  TEST_ASSERT_EQUAL_PTR(&p1, papersArr[0]);
  TEST_ASSERT_EQUAL_PTR(&p2, papersArr[1]);
  TEST_ASSERT_EQUAL_PTR(&p3, papersArr[2]);
  TEST_ASSERT_EQUAL_PTR(&p4, papersArr[3]);
  TEST_ASSERT_EQUAL_PTR(&p5, papersArr[4]);
}

void test_shuffleArray_given_p1_shuffle_with_p5(void){
	Paper *papersArr[] = { &p1,&p2,&p3,&p4,&p5};
  
  random_IgnoreAndReturn(4); // p1 is shuffle with p5 
  random_IgnoreAndReturn(1);
  random_IgnoreAndReturn(2);
  random_IgnoreAndReturn(3);
  random_IgnoreAndReturn(4);  
  shuffleArray( papersArr, SIZE);
  
  TEST_ASSERT_EQUAL_PTR(&p5, papersArr[0]);
  TEST_ASSERT_EQUAL_PTR(&p2, papersArr[1]);
  TEST_ASSERT_EQUAL_PTR(&p3, papersArr[2]);
  TEST_ASSERT_EQUAL_PTR(&p4, papersArr[3]);
  TEST_ASSERT_EQUAL_PTR(&p1, papersArr[4]);
}

void test_shuffleArray_given_p4_shuffle_with_p2(void){
	Paper *papersArr[] = { &p1,&p2,&p3,&p4,&p5};
  
  random_IgnoreAndReturn(0); 
  random_IgnoreAndReturn(1);
  random_IgnoreAndReturn(2);
  random_IgnoreAndReturn(1); // p4 is shuffle with p2 
  random_IgnoreAndReturn(4);  
  shuffleArray( papersArr, SIZE);
  
  TEST_ASSERT_EQUAL_PTR(&p1, papersArr[0]);
  TEST_ASSERT_EQUAL_PTR(&p4, papersArr[1]);
  TEST_ASSERT_EQUAL_PTR(&p3, papersArr[2]);
  TEST_ASSERT_EQUAL_PTR(&p2, papersArr[3]);
  TEST_ASSERT_EQUAL_PTR(&p5, papersArr[4]);
}

void test_shuffleArray_given_p4_shuffle_with_p2_and_p3_shuffle_with_p1(void){
	Paper *papersArr[] = { &p1,&p2,&p3,&p4,&p5};
  
  random_IgnoreAndReturn(0); 
  random_IgnoreAndReturn(1);
  random_IgnoreAndReturn(0); // p3 is shuffle with p1
  random_IgnoreAndReturn(1); // p4 is shuffle with p2 
  random_IgnoreAndReturn(4);  
  shuffleArray( papersArr, SIZE);
  
  TEST_ASSERT_EQUAL_PTR(&p3, papersArr[0]);
  TEST_ASSERT_EQUAL_PTR(&p4, papersArr[1]);
  TEST_ASSERT_EQUAL_PTR(&p1, papersArr[2]);
  TEST_ASSERT_EQUAL_PTR(&p2, papersArr[3]);
  TEST_ASSERT_EQUAL_PTR(&p5, papersArr[4]);
}
