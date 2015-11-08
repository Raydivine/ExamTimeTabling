#ifndef ExamStruct_H
#define ExamStruct_H
#include "LinkedList.h"
#include "Node.h"


#define MAX_DAYS  50

typedef struct Lecturer Lecturer;
typedef struct Programme Programme;
typedef struct Paper Paper;
typedef struct Venue Venue;
typedef struct Day Day;
typedef struct Table Table;

//-----------------USER VARAIBLE----------------------
struct Lecturer{
  int lecturerID;
  int ID;
};

struct Programme{
  char *name;
  int studentNum;
};

struct Paper{
  char *code;
  int hour;
  int lecturerID; 
  LinkedList *programmes;
};

struct Venue{
  char *blockName;
  int venueCode;
  int seats;
};

//------------------SYSTEM VARIABLE---------------------------

struct Exam{
  Venue *venue;
  Node *lecturers;
  LinkedList *papers;
  LinkedList *programmes;
};

struct Day{
  LinkedList *examsAM;
  LinkedList *examsPM;
};

struct Table{
  Day days[MAX_DAYS];
  int daysNum;
};

#endif // ExamStruct_H
