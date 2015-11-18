#ifndef ExamStruct_H
#define ExamStruct_H
#include "LinkedList.h"
#include "Node.h"

#define MAX_SUBJECTS 6
#define MAX_DAYS  50

typedef struct Lecturer Lecturer;
typedef struct Programme Programme;
typedef struct Paper Paper;
typedef struct Venue Venue;
typedef struct Session Session;

//-----------------USER VARAIBLE----------------------

struct Paper{
  char *code;
  int takersNum;
  LinkedList *programmes; 
};

struct Programme{
  char *name;
  int studentNum;
};

struct Lecturer{
  int lecturerID;
};

struct Venue{
  char *blockName;
  int code;
  int seats;
};

//------------------SYSTEM VARIABLE---------------------------


struct Session{
  LinkedList *papers;
  int fitnessScore;
};


#endif // ExamStruct_H
