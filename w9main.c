#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
void displayMainMenu(void);
int main(void)
{
    int choice;
    printf("Municipal Financial Management System\n");
    do
    {
        displayMainMenu();
        choice = readInt();
        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Total payroll: N$%.2f\n", calculatePayrollTotal());
                break;
            case 5:
                addBudget();
                break;
            case 6:
                listBudgets();
                break;
            case 7:
                employeeReport();
                pauseScreen();
                break;
            case 8:
                budgetReport();
                pauseScreen();
                break;
            case 9:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);
    return 0;
}
void displayMainMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Employee\n");
    printf("2. List Employees\n");
    printf("3. Search Employee\n");
    printf("4. Calculate Payroll Total\n");
    printf("5. Add Budget\n");
    printf("6. List Budgets\n");
    printf("7. Employee Report\n");
    printf("8. Budget Report\n");
    printf("9. Exit\n");
    printf("Enter choice: ");
}