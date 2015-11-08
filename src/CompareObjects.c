#include "CompareObjects.h"
#include "ExamStruct.h"

int compareLecturersID(void *a, void *b){
  
  Lecturer *x = (Lecturer*)a; 
  Lecturer *y = (Lecturer*)b; 
  
  if(y->ID > x->ID)
    return 1;
  else if(y->ID < x->ID)
    return -1;
  else
    return 0;
}
