#include "CreateExamsList.h"
#include "ExamStruct.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "Node.h"
#include <stdio.h>

 //printf("%s\n", venueArr[0].blockName);
 // printf("%s\n", programmeArr[0].name);

LinkedList *createExamsList(Venue venueArr[], Programme programmeArr[]){
  
  LinkedList *ExamVenues;
 
}

ExamVenue createExamVenue(Venue *venue, LinkedList **programmsList){
  
  ExamVenue examVenue;
  
  examVenue.venue = venue;
  examVenue.programmes = *programmsList;
  
  return examVenue;
}