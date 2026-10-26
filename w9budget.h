#ifndef BUDGET_H
#define BUDGET_H
void addBudget(void);
void listBudgets(void);
double calculateBudgetBalance(double allocated, double spent);
double getTotalAllocated(void);
double getTotalSpent(void);
int getBudgetCount(void);
#endif