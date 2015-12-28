#ifndef ExamTimeTabling_H
#define ExamTimeTabling_H
#include "ExamStruct.h"
#include "LinkedList.h"

void examTimeTabling(Paper *papers[], int sizePapers, int sizeSession);
void crossoverHandler(Table *population[], Paper *target, int sizePopulation, int sizeSession);


#endif // ExamTimeTabling_H
