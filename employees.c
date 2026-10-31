#include <stdio.h>
#include <string.h>
#include "records.h"
#include "employees.h"
#include "utilities.h"
Employee employees[MAX_RECORDS];
int employeeCount = 0;
void addEmployee(void)
{
    int id;
    int i;
    int duplicate = 0;
    char name[30];
    char department[20];
    double salary;
    if (employeeCount >= MAX_RECORDS)
    {
        printf("Employee list is full.\n");
        return;
    }
    printf("Enter employee ID: ");
    id = readInt();
    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
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
    printf("Enter department: ");
    readString(department, sizeof(department));
    printf("Enter monthly salary: ");
    salary = readDouble();
    if (salary < 0)
    {
        printf("Salary cannot be negative.\n");
        return;
    }
    employees[employeeCount].id = id;
    strcpy(employees[employeeCount].name, name);
    strcpy(employees[employeeCount].department, department);
    employees[employeeCount].salary = salary;
    employeeCount++;
    printf("Employee added.\n");
}
void displayEmployees(void)
{
    int i;
    if (employeeCount == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }
    printf("\n%-6s %-25s %-15s %12s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < employeeCount; i++)
    {
        printf("%-6d %-25s %-15s %12.2f\n", employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
    }
}
void searchEmployee(void)
{
    int id;
    int i;
    int found = 0;
    printf("Enter employee ID to search: ");
    id = readInt();
    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            found = 1;
            printf("Employee found.\n");
            printf("ID        : %d\n", employees[i].id);
            printf("Name      : %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary    : %.2f\n", employees[i].salary);
            break;
        }
    }
    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}
Employee *getEmployees(void)
{
    return employees;
}
double calculatePayrollTotal(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < employeeCount; i++)
    {
        total = total + employees[i].salary;
    }
    return total;
}
int getEmployeeCount(void)
{
    return employeeCount;
}
void saveEmployees(void)
{
    FILE *fp;
    int i;
    fp = fopen("data/employees.txt", "w");
    if (fp == NULL)
    {
        perror("data/employees.txt");
        return;
    }
    for (i = 0; i < employeeCount; i++)
    {
        fprintf(fp, "%d|%s|%s|%.2f\n", employees[i].id, employees[i].name,
                employees[i].department, employees[i].salary);
    }
    fclose(fp);
    printf("%d employee(s) saved to data/employees.txt\n", employeeCount);
}
void loadEmployees(void)
{
    FILE *fp;
    fp = fopen("data/employees.txt", "r");
    if (fp == NULL)
    {
        printf("No saved employee file found (data/employees.txt).\n");
        return;
    }
    employeeCount = 0;
    while (employeeCount < MAX_RECORDS &&
           fscanf(fp, "%d|%29[^|]|%19[^|]|%lf",
                  &employees[employeeCount].id,
                  employees[employeeCount].name,
                  employees[employeeCount].department,
                  &employees[employeeCount].salary) == 4)
    {
        employeeCount++;
    }
    fclose(fp);
    printf("%d employee(s) loaded from data/employees.txt\n", employeeCount);
}
void saveEmployeesBinary(void)
{
    FILE *fp;
    size_t w1;
    size_t w2;
    fp = fopen("data/employees.dat", "wb");
    if (fp == NULL)
    {
        perror("data/employees.dat");
        return;
    }
    w1 = fwrite(&employeeCount, sizeof(int), 1, fp);
    w2 = fwrite(employees, sizeof employees[0], employeeCount, fp);
    fclose(fp);
    if (w1 != 1 || w2 != (size_t)employeeCount)
    {
        printf("Error: the binary file was not written completely.\n");
        return;
    }
    printf("%d employee(s) saved to data/employees.dat\n", employeeCount);
}
void loadEmployeesBinary(void)
{
    FILE *fp;
    int count;
    size_t r1;
    size_t r2;
    fp = fopen("data/employees.dat", "rb");
    if (fp == NULL)
    {
        printf("No saved binary file found (data/employees.dat).\n");
        return;
    }
    r1 = fread(&count, sizeof(int), 1, fp);
    if (r1 != 1 || count < 0 || count > MAX_RECORDS)
    {
        printf("Error: data/employees.dat is damaged.\n");
        fclose(fp);
        return;
    }
    r2 = fread(employees, sizeof employees[0], count, fp);
    fclose(fp);
    if (r2 != (size_t)count)
    {
        printf("Error: data/employees.dat is damaged.\n");
        employeeCount = 0;
        return;
    }
    employeeCount = count;
    printf("%d employee(s) loaded from data/employees.dat\n", employeeCount);
}