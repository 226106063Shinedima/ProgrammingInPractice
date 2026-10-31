
#ifndef SALARIES_H
#define SALARIES_H

#include "records.h"

void swapSalaries(double *a, double *b);
void giveRaise(double salaries[], int n, double percent);
void updateSalary(Employee *e, double newSalary);

void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);

Employee *findEmployee(Employee list[], int n, int id);

void updateEmployeeSalary(void);
void salaryStatistics(void);
void swapEmployeeSalaries(void);

#endif