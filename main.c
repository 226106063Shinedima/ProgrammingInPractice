#include <stdio.h>
#include "records.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"
#include "salaries.h"
#include "utilities.h"
#include "reports.h"
void displayMainMenu(void);
void saveAllData(void);
void loadAllData(void);
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
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                addSupplier();
                break;
            case 5:
                displaySuppliers();
                break;
            case 6:
                addAsset();
                break;
            case 7:
                displayAssets();
                break;
            case 8:
                addBudget();
                break;
            case 9:
                displayBudgets();
                break;
            case 10:
                addProject();
                break;
            case 11:
                displayProjects();
                break;
            case 12:
                employeeReport();
                budgetReport();
                recordCountReport();
                pauseScreen();
                break;
            case 13:
                saveAllData();
                break;
            case 14:
                loadAllData();
                break;
            case 15:
                saveEmployeesBinary();
                break;
            case 16:
                loadEmployeesBinary();
                break;
            case 17:
                updateEmployeeSalary();
                break;
            case 18:
                salaryStatistics();
                break;
            case 19:
                swapEmployeeSalaries();
                break;
            case 20:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 20);
    return 0;
}
void displayMainMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("Employees: %d, Suppliers: %d, Assets: %d, Budgets: %d, Projects: %d\n",
           getEmployeeCount(), getSupplierCount(), getAssetCount(),
           getBudgetCount(), getProjectCount());
    printf("----------------------------------------\n");
    printf(" 1. Add Employee\n");
    printf(" 2. Display Employees\n");
    printf(" 3. Search Employee\n");
    printf(" 4. Add Supplier\n");
    printf(" 5. Display Suppliers\n");
    printf(" 6. Add Asset\n");
    printf(" 7. Display Assets\n");
    printf(" 8. Add Budget\n");
    printf(" 9. Display Budgets\n");
    printf("10. Add Project\n");
    printf("11. Display Projects\n");
    printf("12. Reports\n");
    printf("13. Save Data (text files)\n");
    printf("14. Load Data (text files)\n");
    printf("15. Save Employees (binary file)\n");
    printf("16. Load Employees (binary file)\n");
    printf("17. Update Employee Salary\n");
    printf("18. Salary Statistics\n");
    printf("19. Swap Two Employees' Salaries\n");
    printf("20. Exit\n");
    printf("Enter choice: ");
}

void saveAllData(void)
{
    saveEmployees();
    saveSuppliers();
    saveAssets();
    saveBudgets();
    saveProjects();
}

void loadAllData(void)
{
    loadEmployees();
    loadSuppliers();
    loadAssets();
    loadBudgets();
    loadProjects();
    recordCountReport();
}