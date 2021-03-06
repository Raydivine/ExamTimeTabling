#include "unity.h"
#include "CreatePopulation.h"
#include "ExamStruct.h"
#include "SetElements.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"
#include "PaperListConvertion.h"
#include "CalFitnessScore.h"
#include "Random.h"
#include "printfStructs.h"

#define TOTAL_PAPERS sizeof(papersArr)/sizeof(*papersArr)
#define TOTAL_SAMPLES sizeof(population)/sizeof(*population)
#define CLEAR_PAPPER_1_TO_5  clearLinkList(&(p1.programmes)); clearLinkList(&(p2.programmes)); clearLinkList(&(p3.programmes)); clearLinkList(&(p4.programmes)); clearLinkList(&(p5.programmes));
#define CLEAR_PAPPER_6_TO_10  clearLinkList(&(p6.programmes)); clearLinkList(&(p7.programmes)); clearLinkList(&(p8.programmes)); clearLinkList(&(p9.programmes)); clearLinkList(&(p10.programmes)); 

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
  *Student:    270      145        170       165      245      417       265       250        240     325    
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

/**
*  void initPopulation(Table population[], Paper papers[], int sizePopulation ,int sizePapers ,int sizeSession)
*
*   The function will init samples to population[], the number of samples is sizePopulation
*   papers[] is the elmeents to build a table, 
*   sizeSession is the maximun seat is session
*
*
*   Notice : The sizePapers must larger than the students in paperm
*            in this case 
*/
void xtest_initPopulation_given_5_population_and_sizeSession_is_500(void){
  int sizeSession = 500; // must larger than 417, which is students number in p6
	Table *population[5];
  
  printf("-------------- The * indicate the session has conflict--------------\n\n");
  
  Paper *papersArr[10] =  { &p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&p10};
  initPopulation( population, papersArr, TOTAL_SAMPLES, TOTAL_PAPERS, sizeSession);
  //printfPopulationFitnessScore( population, 5);
  printfPopulation( population, TOTAL_SAMPLES);
  
  clearPopulation( population, TOTAL_SAMPLES);
}

void xtest_initPopulation_given_5_population_and_sizeSession_is_420(void){
  int sizeSession = 420;  
	Table *population[5];
  
  Paper *papersArr[10] =  { &p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&p10};
  initPopulation( population, papersArr, TOTAL_SAMPLES, TOTAL_PAPERS, sizeSession);
  printfPopulation( population, TOTAL_SAMPLES);
  
  clearPopulation( population, TOTAL_SAMPLES);
}

void Xtest_initPopulation_given_10_population_and_sizeSession_is_450(void){
  int sizeSession = 450;  
	Table *population[10];
  
  Paper *papersArr[10] =  { &p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&p10};
  initPopulation( population, papersArr, TOTAL_SAMPLES, TOTAL_PAPERS, sizeSession);
  printfPopulation( population, TOTAL_SAMPLES);
  
  clearPopulation( population, TOTAL_SAMPLES);
}
