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

int compareStudentsNumber(void *a, void *b){
  
  Programme *x = (Programme*)a; 
  Programme *y = (Programme*)b; 
  
  if(y->studentNum > x->studentNum)
    return 1;
  else 
    return -1;
}