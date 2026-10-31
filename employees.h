#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include "records.h"
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculatePayrollTotal(void);
int getEmployeeCount(void);
Employee *getEmployees(void);
void saveEmployees(void);
void loadEmployees(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);
#endif