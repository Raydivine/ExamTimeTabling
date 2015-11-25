#ifndef Mutation_H
#define Mutation_H
#include "ExamStruct.h"
#include "LinkedList.h"

void mutateInTwoSessions(Session *session1, Session *session2);
Paper *getTruePaperFromListA(LinkedList **listA, LinkedList *listB);

#endif // Mutation_H
