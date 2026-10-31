#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"
void employeeReport(void)
{
    int count;
    double total;
    printf("\n===== EMPLOYEE REPORT =====\n");
    displayEmployees();
    count = getEmployeeCount();
    total = calculatePayrollTotal();
    if (count > 0)
    {
        printf("\nNumber of employees: %d\n", count);
        printf("Total payroll      : N$%.2f\n", total);
        printf("Average salary     : N$%.2f\n", total / count);
    }
}
void budgetReport(void)
{
    double allocated;
    double spent;
    double balance;
    printf("\n===== BUDGET REPORT =====\n");
    displayBudgets();
    if (getBudgetCount() > 0)
    {
        allocated = getTotalAllocated();
        spent = getTotalSpent();
        balance = calculateBudgetBalance(allocated, spent);
        printf("\nTotal allocated: N$%.2f\n", allocated);
        printf("Total spent    : N$%.2f\n", spent);
        printf("Total balance  : N$%.2f\n", balance);
        if (balance > 0)
        {
            printf("Overall result : SURPLUS\n");
        }
        else if (balance < 0)
        {
            printf("Overall result : DEFICIT\n");
        }
        else
        {
            printf("Overall result : BALANCED\n");
        }
    }
}
void recordCountReport(void)
{
    printf("\n--- RECORDS IN MEMORY ---\n");
    printf("Employees: %d\n", getEmployeeCount());
    printf("Suppliers: %d\n", getSupplierCount());
    printf("Assets   : %d\n", getAssetCount());
    printf("Budgets  : %d\n", getBudgetCount());
    printf("Projects : %d\n", getProjectCount());
}