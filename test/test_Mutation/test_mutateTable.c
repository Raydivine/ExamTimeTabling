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
Table *table;

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
  
  addPaperToSession(&s1, &p2);
  addPaperToSession(&s1, &p1);
  addPaperToSession(&s2, &p4);
  addPaperToSession(&s2, &p3);
  addPaperToSession(&s3, &p6);
  addPaperToSession(&s3, &p5);
  addPaperToSession(&s4, &p8);
  addPaperToSession(&s4, &p7);
  
  table = createDynamicTable();
  
/** The Table show below
  *
  *               s1           |          s2         |         s3          |        s4
  *           p1,       p2    |     p3,      p4     |    p5,       p6     |     p7,      p8
  *         c1,c2     c2,c3  |   c3,c4     c4,c5   |   c5,c6     c6,c7   |    c7,c8      c8,c1
  *
  *  The 4 sessions have conflict, and s1 contact s2, s2 contact s3 , s4 contanct s1
  *
  *
*/
}

void tearDown(void){
  
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_ALL_SESSION;
  clearLinkList(&(table->sessions));
}

/**   void mutateTable(Table *table)
*
*     This function will use mutateTable(LinkedList **sessionList)
*
*     The mutate way will be like that
*
*       S1            S2            S3          S4          S5
*      list2-------------------------------------------------
*                     list3----------------------------------    
*                                   list4-------------------- 
*                                              list5---------
*
*
*       S1            S2            S3          S4          S5
*       -------------------------------------------------------
*       (s1)          s1s2          s1s3       s1s4        s1s5    (s1 do  mutation with rest of element)
*                     (s2)          s2s4       s2s4        s2s5    
*                                     (s3)     s3s4        s3s5                       
*                                              (s4)        s4s5     
*         
*      The global mutation design allow all the session mutate with others   
*       Because there is 5 session, so each session done 4 mutation 
*        s1 mutate start from s2 to s5 
*        s2 mutate start from s3 to s5  ( skip s1, because s1 already done mutation with s2)
*        s3 mutate start from s4 to s5  ( skip s1,s2 , because s1,s2 already mutate with s3)
*        s4 mutate with s5 only         ( s1-s3 already mutate with s4 )
*        s5 dont do mutation            ( because all session already mutate with it)
*         
*      list 1 till list 5 will be input to  mutateTable(LinkedList **sessionList),
*      so all the sesion will mutate to others
*
*     Due to table is large combination strucutre, it is very hard to ensure the result,
*     So the tests below is just printOut the input and output structure, to oberserve is the structure become better 
*         
*     Notice : Un "X" to see the print input and output structure 
*/  

void test_mutateTable_given_s1_at_head_should_mutate(void){
  Table *table = createDynamicTable();
  addSessionToTable(table, &s4);
  addSessionToTable(table, &s3);
  addSessionToTable(table, &s2);
  addSessionToTable(table, &s1);
  
  printf("--------------testing mutateTable()----------------\n\n");
  printf("test1\n");
  
  printf("Input\n");
  printfTable(table);
  mutateTable(table);
  printf("Output\n");
  printfTable(table);


}

void test_mutateTable_given_s2_at_head_should_mutate(void){
  Table *table = createDynamicTable();
  addSessionToTable(table, &s4);
  addSessionToTable(table, &s3);
  addSessionToTable(table, &s1);
  addSessionToTable(table, &s2);
  
  printf("test2\n");
  printf("Input\n");
  printfTable(table);
  mutateTable(table);
  printf("Output\n");
  printfTable(table);

  
}

void test_mutateTable_given_s3_at_head_should_mutate(void){
  Table *table = createDynamicTable();
  addSessionToTable(table, &s4);
  addSessionToTable(table, &s1);
  addSessionToTable(table, &s2);
  addSessionToTable(table, &s3);
  
  printf("test3\n");
  printf("Input\n");
  printfTable(table);
  mutateTable(table);
  printf("Output\n");
  printfTable(table);

 
}


void test_mutateTable_given_s4_at_head_should_mutate(void){
  Table *table = createDynamicTable();
  addSessionToTable(table, &s1);
  addSessionToTable(table, &s3);
  addSessionToTable(table, &s2);
  addSessionToTable(table, &s4);
  
  printf("test4\n");
  printf("Input\n");
  printfTable(table);
  mutateTable(table);
  printf("Output\n");
  printfTable(table);

}
