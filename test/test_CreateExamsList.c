#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "SetElements.h"

#include "CreateExamsList.h"

Venue M1, M2, M3, M4;
Paper math, physics, chemistry, biology;
Programme RMB1, RMB2, RFS1, RFS2;

      
  
//  RMB1.subjects = { math, physics };

void setUp(void)
{
  //void setVenue(Venue *target, char *blockName, int code, int seats)
  setVenue(&M1, "M", 1, 50);
  setVenue(&M2, "M", 2, 50);
  setVenue(&M3, "M", 3, 50);
  setVenue(&M4, "M", 4, 50);
  
  //void setPaper(Paper *target ,char *code, int hour, int lecturerID)
  setPaper(&math      , "math"       , 2, 1001);
  setPaper(&physics   , "physics"    , 2, 1002);
  setPaper(&chemistry , "chemistry"  , 2, 1003);
  setPaper(&biology   , "biology"    , 2, 1004);
  
  

  Paper subjectRMB1[] = { math};
  Paper subjectRMB2[] = { physics};
  Paper subjectRFS1[] = { chemistry};
  Paper subjectRFS2[] = { biology};
  // void setProgramme(Programme *target ,char *name, int studentNum, Paper subjects[])
  setProgramme(&RMB1 , "RMB1", 50, subjectRMB1);
  setProgramme(&RMB2 , "RMB2", 50, subjectRMB2);
  setProgramme(&RFS1 , "RFS1", 50, subjectRFS1);
  setProgramme(&RFS2 , "RFS2", 50, subjectRFS2);
}

void tearDown(void)
{
}

void test_createExamsList_given_1program_1_venue_should_create(void){

  //printf("%s", (RMB1.subjects[0]).code);
  
	
}
