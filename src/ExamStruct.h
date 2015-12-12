#ifndef ExamStruct_H
#define ExamStruct_H
#include "LinkedList.h"
#include "Node.h"

#define MAX_SESSIONS 100

//extern maxSessions;

typedef struct Lecturer Lecturer;
typedef struct Programme Programme;
typedef struct Paper Paper;
typedef struct Venue Venue;
typedef struct Session Session;
typedef struct Ses Ses;


typedef struct Table Table;

//-----------------USER VARAIBLE----------------------

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

struct Paper{
  char *code;
  int takersNum;
  LinkedList *programmes; 
};


//------------------SYSTEM VARIABLE---------------------------

struct Session{
  LinkedList *papers;
  int population;
};


struct Table{
  LinkedList *sessions;
  int fitnessScore;
};

struct Ses{
  Ses *next;
  LinkedList *papers;
  int size;
};


#endif // ExamStruct_H
