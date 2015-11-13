#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"
#include "CreateExamsList.h"

#define PROGRAMME1    programmes->data
#define PROGRAMME2    programmes->next->data
#define PROGRAMME3    programmes->next->next->data
#define PROGRAMME4    programmes->next->next->next->data
#define PROGRAMME5    programmes->next->next->next->next->data

Venue M1;
Paper math, physics, chemistry, biology;
Programme RMB1, RMB2, RFS1, RFS2;
   
void setUp(void)
{
  Paper subjectRMB1[] = { math};
  Paper subjectRMB2[] = { physics};
  Paper subjectRFS1[] = { chemistry};
  Paper subjectRFS2[] = { biology};
  
  //void setVenue(Venue *target, char *blockName, int code, int seats)
  setVenue(&M1, "M", 1, 100);

  //void setPaper(Paper *target ,char *code, int hour, int lecturerID)
  setPaper(&math      , "math"       , 2, 1001);
  setPaper(&physics   , "physics"    , 2, 1002);
  setPaper(&chemistry , "chemistry"  , 2, 1003);
  setPaper(&biology   , "biology"    , 2, 1004);
  
  //void setProgramme(Programme *target ,char *name, int studentNum, Paper subjects[])
  setProgramme(&RMB1 , "RMB1", 25, subjectRMB1);
  setProgramme(&RMB2 , "RMB2", 25, subjectRMB2);
  setProgramme(&RFS1 , "RFS1", 25, subjectRFS1);
  setProgramme(&RFS2 , "RFS2", 25, subjectRFS2);
}

void tearDown(void){}

/** FUNCTION:   ExamVenue createExamVenue(Venue *venue, LinkedList *programmsList)
*
*   create ExamVenue by put the programmsList into 1 venue
*
*   input conditions :  1. totalStudent in programmsList can not large than seat in venue
*                       2. *venue cant be NULL
*
*/


void test_createExamVenue_put_nothing_into_venue_M1(void){
  
  LinkedList *head = NULL;
  
  ExamVenue examVenue = createExamVenue(&M1, &head);
  TEST_ASSERT_NULL(examVenue.programmes);
  TEST_ASSERT_NOT_NULL(examVenue.venue);
  TEST_ASSERT_EQUAL_PTR(examVenue.venue, &M1);
}

void test_createExamVenue_put_RMB1_into_venue_M1(void){
  
  LinkedList *head = linkListNew(&RMB1);
  
  ExamVenue examVenue = createExamVenue(&M1, &head);
  TEST_ASSERT_NOT_NULL(examVenue.venue);
  TEST_ASSERT_NOT_NULL(examVenue.programmes);
  TEST_ASSERT_EQUAL_PTR(examVenue.venue, &M1);
  
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME1, &RMB1);
}

void test_createExamVenue_put_RMB1_RMB2_into_venue_M1(void){
  
  LinkedList *head = linkListNew(&RMB1);
  addDataToTail( &head, &RMB2);
 
  ExamVenue examVenue = createExamVenue(&M1, &head);
  TEST_ASSERT_NOT_NULL(examVenue.venue);
  TEST_ASSERT_NOT_NULL(examVenue.programmes);
  TEST_ASSERT_EQUAL_PTR(examVenue.venue, &M1);
  
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME1, &RMB1);
  TEST_ASSERT_EQUAL_PTR(examVenue.PROGRAMME2, &RMB2);
}
