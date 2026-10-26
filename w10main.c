#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
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
                listEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                addSupplier();
                break;
            case 5:
                listSuppliers();
                break;
            case 6:
                addAsset();
                break;
            case 7:
                listAssets();
                break;
            case 8:
                addBudget();
                break;
            case 9:
                listBudgets();
                break;
            case 10:
                employeeReport();
                budgetReport();
                recordCountReport();
                pauseScreen();
                break;
            case 11:
                saveAllData();
                break;
            case 12:
                loadAllData();
                break;
            case 13:
                saveEmployeesBinary();
                break;
            case 14:
                loadEmployeesBinary();
                break;
            case 15:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 15);
    return 0;
}
void displayMainMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf(" 1. Add Employee\n");
    printf(" 2. List Employees\n");
    printf(" 3. Search Employee\n");
    printf(" 4. Add Supplier\n");
    printf(" 5. List Suppliers\n");
    printf(" 6. Add Asset\n");
    printf(" 7. List Assets\n");
    printf(" 8. Add Budget\n");
    printf(" 9. List Budgets\n");
    printf("10. Reports\n");
    printf("11. Save Data (text files)\n");
    printf("12. Load Data (text files)\n");
    printf("13. Save Employees (binary file)\n");
    printf("14. Load Employees (binary file)\n");
    printf("15. Exit\n");
    printf("Enter choice: ");
}

void saveAllData(void)
{
    saveEmployees();
    saveSuppliers();
    saveAssets();
    saveBudgets();
}

void loadAllData(void)
{
}
    loadEmployees();
    loadSuppliers();
    loadAssets();
    loadBudgets();
    recordCountReport();