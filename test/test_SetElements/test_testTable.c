#include "unity.h"
#include "CalFitnessScore.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "printfStructs.h"

Paper p1;
Session s1;

void setUp(void){
  
   setPaperTakersNum(&p1, "p1", 50);
   
   s1 = createSession();
   addPaperToSession(&s1, &p1);
}

void tearDown(void){}

/**
  struct Table{
    LinkedList *sessions;  = NULL
    int fitnessScore;      = 0
  };
*/

void test_testTable_should_create_the_table_with_0_fitnessScore_0_empty_papers(void){

  Table t = createTable();
  testTable(&t, &s1);
  printfTable(t);

  
}


