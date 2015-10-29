#ifndef ExamStructure_H
#define ExamStructure_H
#include "LinkedList.h"
#include "Node.h"
#include "string.h"

typedef struct Lecture Lecture;
typedef struct Programme Programme;
typedef struct Paper Paper;
typedef struct Venue Venue;
typedef struct VenueGroup VenueGroup;
typedef struct Period Period;
typedef struct Day Day;
typedef struct ETT ETT;

struct Lecture{
  char *name;
  int ID;
};

struct Programme{
  char *name;
  int numOfStudent;
  LinkedList *papers;
};

struct Paper{
  char *name;
  int numOfStudent;
  int hour;
  Node *programmes;
  Node *examiners;
};

struct Venue{
  char *name;
  int totalSeats;
  Node *papers;
  Node *examiners;
};

struct VenueGroup{
  char *name;
  int numOfVenue;
  Node *venues;
  Node *examiners;
};

struct Period{
  LinkedList *venues;
};

struct Day{
  Period morning;
  Period afternoon;
};

struct ETT{
  LinkedList *day;
};


#endif // ETT_dataStructure_H
