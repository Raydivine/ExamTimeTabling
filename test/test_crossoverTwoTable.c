#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "SetElements.h"
#include "printfStructs.h"
#include "PaperListConvertion.h"
#include "Crossover.h"

#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 
#define CLEAR_ALL_SESSION clearLinkList(&(s1.papers)); clearLinkList(&(s2.papers)); clearLinkList(&(s3.papers)); clearLinkList(&(s4.papers));

Paper p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
Programme c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
Session s1,s2,s3,s4;

void setUp(void)
{
}

void tearDown(void)
{
  CLEAR_ALL_SESSION; 
}


/**  Table crossoverTwoTable(Table tableA, Table tableB, Paper *target, int population)
*
*    This function will build a child from tableA and tableB
*    a) target is the choosen point while doing crossover between tableA and tableB
*    b) population is the total student in session , while this number is depend on the total seat in school
*
*    ProccessFlow
*    1. Convert tableA and tableB to paperLoopA and paperLoopB 
*       ( paper is the unit element in chromosome, convert to loop is for the convenient of crossover)
*    2. Point the head of them to target
*       ( as the starting middle point to do croosover )
*    3. Reverse paperLoopA
*       ( reversed paperLoopA so its direction go to left, while paperLoopB go to right)
*    4.  Pass paperLoopA and paperLoopB to buildChildList()
*       ( this will return a croosover child list)  
*    5.  Convert the child list to child table
*    6.  child table do mutation for effectively get the good output 
*
*
*/

void test_module_generator_needs_to_be_implemented(void)
{
	TEST_IGNORE_MESSAGE("Implement me!");
}
