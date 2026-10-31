
#include <stdio.h>
#include "records.h"
#include "salaries.h"
#include "employees.h"
#include "utilities.h"

void swapSalaries(double *a, double *b)
{
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void giveRaise(double salaries[], int n, double percent)
{
    int i;

    for (i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

void displaySalaries(const double salaries[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest;
    int i;

    highest = salaries[0];

    for (i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;

    for (i = 0; i < n; i++)
    {
        total = total + salaries[i];
    }

    return total / n;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (list[i].id == id)
        {
            return &list[i];    
        }
    }

    return NULL;                
}
void updateEmployeeSalary(void)
{
    int id;
    double newSalary;
    Employee *found;

    printf("Enter employee ID: ");
    id = readInt();

    found = findEmployee(getEmployees(), getEmployeeCount(), id);

    if (found == NULL)
    {
        printf("Employee with ID %d was not found.\n", id);
        return;
    }

    printf("%s currently earns N$%.2f\n", found->name, found->salary);
    printf("Enter new salary: ");
    newSalary = readDouble();

    if (newSalary < 0)
    {
        printf("Salary cannot be negative.\n");
        return;
    }

    updateSalary(found, newSalary);

    printf("Updated record:\n");
    printf("%d | %s | %s | N$%.2f\n",
           found->id, found->name, found->department, found->salary);
}
void salaryStatistics(void)
{
    Employee *list;
    double salaries[MAX_RECORDS];
    int count;
    int i;

    list = getEmployees();
    count = getEmployeeCount();

    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        salaries[i] = list[i].salary;
    }

    printf("\n--- SALARY STATISTICS ---\n");
    displaySalaries(salaries, count);
    printf("Highest salary: N$%.2f\n", findHighest(salaries, count));
    printf("Average salary: N$%.2f\n", calculateAverage(salaries, count));
}

void swapEmployeeSalaries(void)
{
    int firstId;
    int secondId;
    Employee *first;
    Employee *second;

    printf("Enter the first employee ID: ");
    firstId = readInt();
    printf("Enter the second employee ID: ");
    secondId = readInt();

    if (firstId == secondId)
    {
        printf("Please choose two different employees.\n");
        return;
    }

    first = findEmployee(getEmployees(), getEmployeeCount(), firstId);
    second = findEmployee(getEmployees(), getEmployeeCount(), secondId);

    if (first == NULL || second == NULL)
    {
        printf("One of the employee IDs was not found.\n");
        return;
    }

    swapSalaries(&first->salary, &second->salary);

    printf("Salaries swapped.\n");
    printf("%s now earns N$%.2f\n", first->name, first->salary);
    printf("%s now earns N$%.2f\n", second->name, second->salary);
}
