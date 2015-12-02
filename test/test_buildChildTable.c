#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "Crossover.h"

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
}

void tearDown(void){
  
  CLEAR_PAPPER_1_TO_5;
  CLEAR_PAPPER_6_TO_10;
  CLEAR_ALL_SESSION;
}

/**  Table buildChildTable(Table tableA, Table tableB, LinkedList *parrent)
*
*    taking the non-repeating element from tableA,B to child , owns hit the repeated element then stop,
*    while takken the element, then remove it in parrent. which parrent is paperList contain all the elements.
*
*/ 



/**  parrent = p1,p2,p3,p4
  *
  *     s1      s2      s3    s4      
  *     p1      p2      p3    p4    
  *                                      //  for saving time and test code , the test struture using same resouces, but it wont cause error
  *     s1      s2      s3    s4 
  *     p1      p2      p3    p4 
  *
  *----------------output-------------------
  *
  * child = s1, 
  *
  * paperList = p2,p3,p4
*/
void test_buildChildTable_should_build_child_with_s1_only(void){
  
}