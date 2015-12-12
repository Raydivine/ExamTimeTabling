#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "printfStructs.h"



void setUp(void){
}

void tearDown(void){}


void test_testTable_should_create_the_table_with_0_fitnessScore_0_empty_papers(void){

  Paper p1;
  setPaperTakersNum(&p1, "p1", 50);
   
  Session s1 = createSession();
  addPaperToSession(&s1, &p1);

  Table t = createTable();
  testTable(&t, &s1);
  printfTable(t);

}


