#include "unity.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "CreateExamsList.h"

Venue M1, M2, M3, M4;

Paper papers[]
  = { 
      { .code = "A-MB1", .hour = 2, .lecturerID = 1001 },
      { .code = "B-MB1", .hour = 2, .lecturerID = 1002 },
      { .code = "A-MB2", .hour = 2, .lecturerID = 1001 },
      { .code = "B-MB2", .hour = 2, .lecturerID = 1002 },
      { .code = "A-FS1", .hour = 2, .lecturerID = 1003 },
      { .code = "B-FS1", .hour = 2, .lecturerID = 1004 },
      { .code = "A-FS2", .hour = 2, .lecturerID = 1003 },
      { .code = "B-FS2", .hour = 2, .lecturerID = 1004 },
      { .code = "A-MQA", .hour = 1, .lecturerID = 0001 },  // Sharing papers of RMB1 , RFS1 
      { .code = "B-MQA", .hour = 1, .lecturerID = 0001 }  // Sharing papers OF RMB2 , RFS2 
    };

void setUp(void)
{/**
   Venue venueArr[]
  = {
      {.blockName = "M", .code = 1 , .seats = 50 },
      {.blockName = "M", .code = 2 , .seats = 50 },
      {.blockName = "Q", .code = 1 , .seats = 50 },
      {.blockName = "Q", .code = 2 , .seats = 50 }
    };
  
  Lecturer lectureArrList[] 
  = {   
      {.ID = 1001},  {.ID = 1002},  {.ID = 1003},  {.ID = 1004},
      {.ID = 0001}
    };
    */
  
    /**
  Programme programmeArr[]
  = {
      { 
        .name       = "RMB1", 
        .studentNum = 25, 
        .subjects   = { papers[0], papers[1], papers[8] }
      },
      
      { 
        .name       = "RMB2", 
        .studentNum = 25, 
        .subjects   = { papers[2], papers[3], papers[9] }
      },
      
      { 
        .name       = "RFS1", 
        .studentNum = 25, 
        .subjects   = { papers[4], papers[5], papers[8] }
      },
      
      { 
        .name       = "RFS2", 
        .studentNum = 25, 
        .subjects   = { papers[6], papers[7], papers[9] }
      },
  
    };*/
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
