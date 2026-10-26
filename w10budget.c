#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"
#define MAX_BUDGETS 20
char budgetDepartments[MAX_BUDGETS][30];
double budgetAllocated[MAX_BUDGETS];
double budgetSpent[MAX_BUDGETS];
int budgetCount = 0;
void addBudget(void)
{
    char department[30];
    double allocated;
    double spent;
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget list is full.\n");
        return;
    }
    printf("Enter department name: ");
    readString(department, sizeof(department));
    printf("Enter amount allocated: ");
    allocated = readDouble();
    printf("Enter amount spent: ");
    spent = readDouble();
    if (allocated < 0 || spent < 0)
    {
        printf("Amounts cannot be negative.\n");
        return;
    }
    strcpy(budgetDepartments[budgetCount], department);
    budgetAllocated[budgetCount] = allocated;
    budgetSpent[budgetCount] = spent;
    budgetCount++;
    printf("Budget added.\n");
}
void listBudgets(void)
{
    int i;
    double balance;
    if (budgetCount == 0)
    {
        printf("No budgets have been added yet.\n");
        return;
    }
    printf("\n%-20s %13s %13s %13s\n", "Department", "Allocated", "Spent", "Balance");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < budgetCount; i++)
    {
        balance = calculateBudgetBalance(budgetAllocated[i], budgetSpent[i]);
        printf("%-20s %13.2f %13.2f %13.2f", budgetDepartments[i],
               budgetAllocated[i], budgetSpent[i], balance);
        if (balance < 0)
        {
            printf("  OVER BUDGET");
        }
        printf("\n");
    }
}

double calculateBudgetBalance(double allocated, double spent)
{
    return allocated - spent;
}
double getTotalAllocated(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++)
    {
        total = total + budgetAllocated[i];
    }
    return total;
}
double getTotalSpent(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++)
    {
        total = total + budgetSpent[i];
    }
    return total;
}
int getBudgetCount(void)
{
    return budgetCount;
}
 
void saveBudgets(void)
{
    FILE *fp;
    int i;
    fp = fopen("data/budgets.txt", "w");
    if (fp == NULL)
    {
        perror("data/budgets.txt");
        return;
    }
    for (i = 0; i < budgetCount; i++)
    {
        fprintf(fp, "%s|%.2f|%.2f\n", budgetDepartments[i],
                budgetAllocated[i], budgetSpent[i]);
    }
    fclose(fp);
    printf("%d budget(s) saved to data/budgets.txt\n", budgetCount);
}
void loadBudgets(void)
{
    FILE *fp;
    char department[30];
    double allocated;
    double spent;
    fp = fopen("data/budgets.txt", "r");
    if (fp == NULL)
    {
        printf("No saved budget file found (data/budgets.txt).\n");
        return;
    }
    budgetCount = 0;
    while (budgetCount < MAX_BUDGETS &&
           fscanf(fp, " %29[^|]|%lf|%lf", department, &allocated, &spent) == 3)
    {
    }
        strcpy(budgetDepartments[budgetCount], department);
        budgetAllocated[budgetCount] = allocated;
        budgetSpent[budgetCount] = spent;
        budgetCount++;
    fclose(fp);
    printf("%d budget(s) loaded from data/budgets.txt\n", budgetCount);
}