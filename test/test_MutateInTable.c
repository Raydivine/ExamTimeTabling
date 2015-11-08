#include "unity.h"
#include "Mutation.h"
#include "ExamStruct.h"

#include "LinkedList.h"
#include "LinkedListAdd.h"

#define ARRAY_SIZE  sizeof( days ) / sizeof( days[0]  )

void setUp(void){
  
  Venue venueList[]
  = {
      {.blockName = "M", .code = 1 , .seats = 50 },
      {.blockName = "M", .code = 2 , .seats = 50 },
      {.blockName = "Q", .code = 1 , .seats = 50 },
      {.blockName = "Q", .code = 2 , .seats = 50 }
    };
  
  Lecturer lectureList[] 
  = {   
      {.ID = 1001},  {.ID = 1002},  {.ID = 1003},  {.ID = 1004},
      {.ID = 0001}
    };
    
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
    
  Programme programmeList[]
  = {
      { 
        .name       = "RMB1", 
        .studentNum = 30, 
        .subjects   = { papers[0], papers[1], papers[8] }
      },
      
      { 
        .name       = "RMB2", 
        .studentNum = 30, 
        .subjects   = { papers[2], papers[3], papers[9] }
      },
      
      { 
        .name       = "RFS1", 
        .studentNum = 30, 
        .subjects   = { papers[4], papers[5], papers[8] }
      },
      
      { 
        .name       = "RFS2", 
        .studentNum = 30, 
        .subjects   = { papers[6], papers[7], papers[9] }
      },
  
    };
}

void tearDown(void){}

    




void test_given_a_examList_with_2_lecturerConflict_and_manually_exchange(void){
  
  // LinkedList  *list1, *list2;
  
  // Day days[] = {
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2}
          // };
          
//printf("%d\n",ARRAY_SIZE );   
  
}

