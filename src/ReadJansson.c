#include "ReadJansson.h"
#include "ExamStructure.h"
#include <jansson.h>
#include <jansson_config.h>

//gcc src/ReadJson.c -Llib/lib -ljansson -Ilib/include 


Lecture lectureList[]
  = {
      { .name = "John", .ID = 1, },
      { .name = "Jack", .ID = 2, },
      { .name = "Paul", .ID = 3, },
      { .name = "Mary", .ID = 4, }, 
    };
       
Programme programmeList[]
  = {
      { .name = "RMB1", . numOfStudent = 10 },
      { .name = "RMB2", . numOfStudent = 10 },
      { .name = "RMB3", . numOfStudent = 10 },
      { .name = "RMM3", . numOfStudent = 10 },
      { .name = "RMM3", . numOfStudent = 10 },
      { .name = "RMM3", . numOfStudent = 10 },
    };   
    
Paper paperList[]
  = {
      { .name = "Chemistry", . numOfStudent = 10},
      { .name = "Biology"  , . numOfStudent = 10},
      { .name = "Physics"  , . numOfStudent = 10},
      { .name = "Math"     , . numOfStudent = 10},
    };


Venue venueList[] 
  = {
      { .name = "D300", .totalSeats = 55, },                 
      { .name = "D301", .totalSeats = 55, },                 
      { .name = "D302", .totalSeats = 55, },                 
      { .name = "D303", .totalSeats = 55, },                 
      { .name = "D304", .totalSeats = 55, },                 
    };
    

