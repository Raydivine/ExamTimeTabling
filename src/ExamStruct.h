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
typedef struct ExamVenue ExamVenue;
typedef struct ExamVenuesList ExamVenuesList;
typedef struct Day Day;
typedef struct Table Table;

//-----------------USER VARAIBLE----------------------

struct Paper{
  char *code;
  int hour;
  LinkedList *programmes; 
};

struct Programme{
  char *name;
  int studentNum;
};

struct Lecturer{
  int lecturerID;
  int ID;
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

struct ExamVenue{
  Venue *venue;
  Node *lecturers;
  LinkedList *programmes;
  LinkedList *papers;
};

struct ExamVenuesList{
  LinkedList *ExamVenues;
  int fitnessScore;
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
