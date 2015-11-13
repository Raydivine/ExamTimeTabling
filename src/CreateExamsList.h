#ifndef CreateExamsList_H
#define CreateExamsList_H
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"

LinkedList *createExamsList(Venue venueArr[], Programme programmeArr[]);
ExamVenue createExamVenue(Venue *venue, LinkedList **programmsList, LinkedList **paperList);


#endif // CreateExamsList_H
