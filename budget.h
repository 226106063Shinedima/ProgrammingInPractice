#ifndef BUDGET_H
#define BUDGET_H
void addBudget(void);
void displayBudgets(void);
double calculateBudgetBalance(double allocated, double spent);
double getTotalAllocated(void);
double getTotalSpent(void);
int getBudgetCount(void);
void saveBudgets(void);
void loadBudgets(void);
#endif