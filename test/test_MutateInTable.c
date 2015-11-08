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
      {.ID = 1001},  {.ID = 1002},  {.ID = 2001},  {.ID = 2002},
      {.ID = 3001},  {.ID = 3002},  {.ID = 4001},  {.ID = 4002},
      {.ID = 0001}
    };
    
  Paper papers[]
  = { 
      { .code = "A-FS01", .hour = 2, .lecturerID = 1001 },
      { .code = "A-FS02", .hour = 2, .lecturerID = 1002 },
      { .code = "A-SS01", .hour = 2, .lecturerID = 2001 },
      { .code = "A-SS02", .hour = 2, .lecturerID = 2002 },
      { .code = "A-BS01", .hour = 2, .lecturerID = 3001 },
      { .code = "A-BS02", .hour = 2, .lecturerID = 3002 },
      { .code = "A-PR01", .hour = 2, .lecturerID = 4001 },
      { .code = "A-PR02", .hour = 2, .lecturerID = 4002 },
      { .code = "A-MQA1", .hour = 1, .lecturerID = 0001 },  // Sharing papers
    };
    
  Programme programmeList[]
  = {
      { 
        .name       = "RFS1", 
        .studentNum = 30, 
        .subjects   = { papers[0], papers[1], papers[8] }
      },
      
      { 
        .name       = "RSS1", 
        .studentNum = 30, 
        .subjects     = { papers[2], papers[3], papers[8] }
      },
      
      { 
        .name       = "RBS1", 
        .studentNum = 30, 
        .subjects   = { papers[4], papers[5], papers[8] }
      },
      
      { 
        .name       = "RPR1", 
        .studentNum = 30, 
        .subjects   = { papers[6], papers[7], papers[8] }
      },
  
    };
}

void tearDown(void){}

    




void test_(void){
  
  // LinkedList  *list1, *list2;
  
  // Day days[] = {
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2},
            // { .examsAM = list1, .examsPM = list2}
          // };
          
//printf("%d\n",ARRAY_SIZE );   
  
}

