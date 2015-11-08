#include "unity.h"
#include "Mutation.h"
#include "ExamStruct.h"

#include "LinkedList.h"
#include "LinkedListAdd.h"

#define ARRAY_SIZE  sizeof( days ) / sizeof( days[0]  )

Lecturer lectureList[] 
  = {   
      {.ID = 1001},  {.ID = 1002},  {.ID = 2001},  {.ID = 2002},
      {.ID = 3001},  {.ID = 3002},  {.ID = 4001},  {.ID = 4002},
      {.ID = 0001}
    };
    
Programme programmeList[]
  = {
      {.name = "RFS1", .studentNum = 30}, 
      {.name = "RSS1", .studentNum = 30},
      {.name = "RBS1", .studentNum = 30}, 
      {.name = "RBR1", .studentNum = 30}
    };
    
Venue venueList[]
  = {
      {.blockName = "M", .code = 1 , .seats = 50 },
      {.blockName = "M", .code = 2 , .seats = 50 },
      {.blockName = "Q", .code = 1 , .seats = 50 },
      {.blockName = "Q", .code = 2 , .seats = 50 }
    };


void setUp(void){
  LinkedList *AFS01Examiners =  linkListNew(&programmeList[0]);
  
  Paper papers[]
  = { 
      { .code = "A-FS01", .hour = 2, .lecturerID = 1001, .programmes = AFS01Examiners }
    };
  
}
void tearDown(void){}

    




void test_(void){
  
  LinkedList  *list1, *list2;
  
  Day days[] = {
            { .examsAM = list1, .examsPM = list2},
            { .examsAM = list1, .examsPM = list2},
            { .examsAM = list1, .examsPM = list2},
            { .examsAM = list1, .examsPM = list2}
          };
          
       printf("%d\n",ARRAY_SIZE );   
  
}

