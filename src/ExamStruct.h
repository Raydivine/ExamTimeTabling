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

typedef struct ExamVenue ExamVenue;
typedef struct ExamVenuesList ExamVenuesList;
typedef struct Day Day;
typedef struct Table Table;

//-----------------USER VARAIBLE----------------------
struct Lecturer{
  int lecturerID;
  int ID;
};

struct Paper{
  char *code;
  int hour;
  int lecturerID; 
};

struct Programme{
  char *name;
  int studentNum;
  Paper subjects[MAX_SUBJECTS];
};

struct Venue{
  char *blockName;
  int code;
  int seats;
};

//------------------SYSTEM VARIABLE---------------------------

struct ExamVenue{
  Venue *venue;
  Node *lecturers;
  Node *programmes;
  LinkedList *papers;
};

struct ExamVenuesList{
  LinkedList *ExamVenue;
  int fitnessScore;
}

struct Day{
  LinkedList *examsAM;
  LinkedList *examsPM;
};

struct Table{
  Day days[MAX_DAYS];
  int daysNum;
};

#endif // ExamStruct_H
