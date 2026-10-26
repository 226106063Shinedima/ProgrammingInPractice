#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"
#define MAX_EMPLOYEES 50
/* employee data is stored in parallel arrays */
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
double employeeSalaries[MAX_EMPLOYEES];
int employeeCount = 0;
void addEmployee(void)
{
    int id;
    int i;
    int duplicate = 0;
    char name[50];
    double salary;
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }
    printf("Enter employee ID: ");
    id = readInt();
    /* do not allow two employees with the same ID */
    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            duplicate = 1;
        }
    }
    if (duplicate == 1)
    {
        printf("An employee with ID %d already exists.\n", id);
        return;
    }
    printf("Enter employee name: ");
    readString(name, sizeof(name));
    printf("Enter monthly salary: ");
    salary = readDouble();
    if (salary < 0)
    {
        printf("Salary cannot be negative.\n");
        return;
    }
    employeeIDs[employeeCount] = id;
    strcpy(employeeNames[employeeCount], name);
    employeeSalaries[employeeCount] = salary;
    employeeCount++;
    printf("Employee added.\n");
}
void listEmployees(void)
{
    int i;
    if (employeeCount == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }
    printf("\n%-6s %-25s %12s\n", "ID", "Name", "Salary");
    printf("---------------------------------------------\n");
    for (i = 0; i < employeeCount; i++)
    {
        printf("%-6d %-25s %12.2f\n",
               employeeIDs[i], employeeNames[i], employeeSalaries[i]);
    }
}
void searchEmployee(void)
{
    int id;
    int i;
Page 14
PAP521S - Programming in Practice - Weeks 7 to 10 source code
    int found = 0;
    printf("Enter employee ID to search: ");
    id = readInt();
    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            found = 1;
            printf("Employee found.\n");
            printf("ID    : %d\n", employeeIDs[i]);
            printf("Name  : %s\n", employeeNames[i]);
            printf("Salary: %.2f\n", employeeSalaries[i]);
            break;
        }
    }
    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}
double calculatePayrollTotal(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < employeeCount; i++)
    {
        total = total + employeeSalaries[i];
    }
    return total;
}
int getEmployeeCount(void)
{
    return employeeCount;
}   