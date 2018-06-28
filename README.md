# ExamTimeTabling

This project is arrange the exam time table in best outcome.

During the preparation of academic exam, the university having the difficulties to arrange a good time table , 
their desire is a shorten time table with comfortable timing.  Example the student shall not taken more than 3 exam subject in one day, else it might be heavy, but if they separate the exam subject into different days, the exam period will become longer and affected their academic calendar. 

So, they trying to arrange a shorten time table and it is comfortable to every student, the problems are some compulsory subjects like English are apply for all courses, some common subjects like business study are apply for business relevant courses only, and some special subject might just apply for one course. 

They have to arrange the time table to meet the goals :
1. The student cannot take more than 1 subjects in same time
2. The student shall not take more than 3 subjects in a day else it might heavy
3. The compulsory or common subject must finish in one time for all relevant student, else if the exam time is separated, the first batch students can share the exam question to second batch student

In computer science, Genetic Algorithm is a way to achieve this mission, it is an algorithm to find best solution and it is taking gene evolution as reference. The gene evolution are done by mutation and crossover,
mutation is the DNA re-order and crossover is the exchange of DNA element.

The movie X-MEN is the well-know criteria for briefing mutation, the character of mutants are the transform of human's mutation, 
their DNA have been reorder so they gain powerful. 

A baby born from parents is the represent of chromosome crossover,  the baby will naturally inherit the good DNA from parent, so human species will always become better. 

The Genetic Algorithm taking the concept of mutation and crossover. 
First, the program will generate large number of time tables randomly and present them in gene form. 
The program will calculate the fitness score of the time table , which the fitness score is referring the goals. 
Then , randomly pick the time tables to do mutation and crossover for improve fitness score, 
and sort them in best fitness score order, the process will always repeated until the fitness cannot be improve.

From that, we get the best solution of the time table
