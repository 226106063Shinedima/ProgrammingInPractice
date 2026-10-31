#include <stdio.h>
#include <string.h>
#include "records.h"
#include "budget.h"
#include "utilities.h"
Budget budgets[MAX_RECORDS];
int budgetCount = 0;
void addBudget(void)
{
    char department[20];
    double allocated;
    double spent;
    if (budgetCount >= MAX_RECORDS)
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
    strcpy(budgets[budgetCount].department, department);
    budgets[budgetCount].allocated = allocated;
    budgets[budgetCount].spent = spent;
    budgetCount++;
    printf("Budget added.\n");
}
void displayBudgets(void)
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
        balance = calculateBudgetBalance(budgets[i].allocated, budgets[i].spent);
        printf("%-20s %13.2f %13.2f %13.2f", budgets[i].department,
               budgets[i].allocated, budgets[i].spent, balance);
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
        total = total + budgets[i].allocated;
    }
    return total;
}
double getTotalSpent(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < budgetCount; i++)
    {
        total = total + budgets[i].spent;
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
        fprintf(fp, "%s|%.2f|%.2f\n", budgets[i].department,
                budgets[i].allocated, budgets[i].spent);
    }
    fclose(fp);
    printf("%d budget(s) saved to data/budgets.txt\n", budgetCount);
}
void loadBudgets(void)
{
    FILE *fp;
    fp = fopen("data/budgets.txt", "r");
    if (fp == NULL)
    {
        printf("No saved budget file found (data/budgets.txt).\n");
        return;
    }
    budgetCount = 0;
    while (budgetCount < MAX_RECORDS &&
           fscanf(fp, " %19[^|]|%lf|%lf",
                  budgets[budgetCount].department,
                  &budgets[budgetCount].allocated,
                  &budgets[budgetCount].spent) == 3)
    {
        budgetCount++;
    }
    fclose(fp);
    printf("%d budget(s) loaded from data/budgets.txt\n", budgetCount);
}