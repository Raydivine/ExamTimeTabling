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
  //void setVenue(Venue *target, char *blockName, int code, int seats);
  setVenue(&M1, "M", 1, 50);
  setVenue(&M2, "M", 2, 50);
  setVenue(&M3, "M", 3, 50);
  setVenue(&M4, "M", 4, 50);
  
  //void setPaper(Paper *target ,char *code, int hour, int lecturerID);
  setPaper(&math      , "math"       , 2, 1001);
  setPaper(&physics   , "physics"    , 2, 1002);
  setPaper(&chemistry , "chemistry"  , 2, 1003);
  setPaper(&biology   , "biology"    , 2, 1004);
  
  //void setProgramme(Programme *target ,char *name, int studentNum);
  // RMB1.name = "R";
  // RMB1.studentNum = 50;
  // setProgramme(&RMB1 , "RMB1", 50);
  // setProgramme(&RMB2 , "RMB2", 50);
  // setProgramme(&RFS1 , "RFS1", 50);
  // setProgramme(&RFS2 , "RFS2", 50);
  
  // RMB2.subjects = { physics };
  // RFS1.subjects = { chemistry };
  // RFS2.subjects= { biology };
  
  //RMB1.arr[0] = 1;
  
  
}

void tearDown(void)
{
}

void test_createExamsList_given_1program_1_venue_should_create(void){
  

  // Venue venueArr[] = { {.blockName = "Q", .code = 2 , .seats = 50 } };
  
  // Programme programmeArr[]= {{  .name       = "RMB1", 
                                // .studentNum = 25, 
                                // .subjects   = { papers[0], papers[1], papers[8] } 
                            // }};
                            
  
	
}
