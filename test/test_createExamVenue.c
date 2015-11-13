#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "CreateExamsList.h"

#define PROGRAMME1    programmes
#define PROGRAMME2    programmes->next
#define PROGRAMME3    programmes->next->next
#define PROGRAMME4    programmes->next->next->next

#define PAPER1    papers
#define PAPER2    papers->next
#define PAPER3    papers->next->next
#define PAPER4    papers->next->next->next

Venue M1;
Paper math, physics, chemistry, biology;
Programme RMB1, RMB2, RFS1, RFS2;
   
void setUp(void)
{
  Paper subjectRMB1[] = { math};
  Paper subjectRMB2[] = { physics};
  Paper subjectRFS1[] = { chemistry};
  
  //void setVenue(Venue *target, char *blockName, int code, int seats)
  setVenue(&M1, "M", 1, 100);

  //void setPaper(Paper *target ,char *code, int hour, int lecturerID)
  setPaper(&math      , "math"       , 2, 1001);
  setPaper(&physics   , "physics"    , 2, 1002);
  setPaper(&chemistry , "chemistry"  , 2, 1003);
  
  //void setProgramme(Programme *target ,char *name, int studentNum, Paper subjects[])
  setProgramme(&RMB1 , "RMB1", 25, subjectRMB1);
  setProgramme(&RMB2 , "RMB2", 25, subjectRMB2);
  setProgramme(&RFS1 , "RFS1", 25, subjectRFS1);
}

void tearDown(void){}

/** FUNCTION:   ExamVenue createExamVenue(Venue *venue, LinkedList **programmsList, LinkedList **paperList)
*
*   create ExamVenue by put the programmsList and paperList into a venue
*
*   input conditions :  1. totalStudent in programmsList can not large than seat in venue
*                       2. *venue cant be NULL
*                       3. paparList and programmsList have same length
*
*/

void test_createExamVenue_empty_programmes_empty_papers_into_venue_M1(void){
  
  LinkedList *progList = NULL;
  LinkedList *papList = NULL;
  
  ExamVenue examVenue = createExamVenue(&M1, &progList, &papList);
  TEST_ASSERT_NULL(examVenue.programmes);
  TEST_ASSERT_NULL(examVenue.papers);
  TEST_ASSERT_EQUAL_PTR(examVenue.venue, &M1);
}

void test_createExamVenue_put_RMB1_and_MATH_into_venue_M1(void){
  
  LinkedList *progList = linkListNew(&RMB1);
  LinkedList *papList  = linkListNew(&math);
  
  ExamVenue examVenue = createExamVenue(&M1, &progList, &papList);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME1->data, &RMB1);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER1->data, &math);
  
  TEST_ASSERT_NULL(examVenue.PROGRAMME2);
  TEST_ASSERT_NULL(examVenue.PAPER2);
}

void test_createExamVenue_put_RMB1_RMB2_and_MATH_PHYSICS_into_venue_M1(void){
  
  LinkedList *progList = linkListNew(&RMB1);
  addDataToTail( &progList, &RMB2);
  
  LinkedList *papList = linkListNew(&math);
  addDataToTail( &papList, &physics);
 
  ExamVenue examVenue = createExamVenue(&M1, &progList, &papList);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME1->data, &RMB1);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME2->data, &RMB2);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER1->data, &math);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER2->data, &physics);
  
  TEST_ASSERT_NULL(examVenue.PROGRAMME3);
  TEST_ASSERT_NULL(examVenue.PAPER3);
}

void test_createExamVenue_put_RMB1_RMB2_RFS1_and_MATH_PHYSICS_CHEMISTRY_into_venue_M1(void){
  
  LinkedList *progList = linkListNew(&RMB1);
  addDataToTail( &progList, &RMB2);
  addDataToTail( &progList, &RFS1);
  
  LinkedList *papList = linkListNew(&math);
  addDataToTail( &papList, &physics);
  addDataToTail( &papList, &chemistry);
 
  ExamVenue examVenue = createExamVenue(&M1, &progList, &papList);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME1->data, &RMB1);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME2->data, &RMB2);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME3->data, &RFS1);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER1->data, &math);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER2->data, &physics);
  TEST_ASSERT_EQUAL_PTR(examVenue.PAPER3->data, &chemistry);
  
  TEST_ASSERT_NULL(examVenue.PROGRAMME4);
  TEST_ASSERT_NULL(examVenue.PAPER4);
}

