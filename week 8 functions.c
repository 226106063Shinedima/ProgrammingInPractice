#include <stdio.h>

void displayWelcome();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu();
int searchEmployee(int id, int ids[], int size);
int main()
{
    int choice;
    float amount;
    float vat;
    float basic;
    float housing;
    float transport;
    float salary;
    float revenue;
    float expenses;
    float balance;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id;
    int position;
    displayWelcome();
    do
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                /* Task 2: VAT */
                printf("Enter amount: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;
            case 2:
                /* Task 3: Salary */
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                salary = calculateSalary(basic, housing, transport);
                printf("Gross salary: %.2f\n", salary);
                break;
            case 3:
                /* Task 4: Budget */
                printf("Enter total revenue: ");
                scanf("%f", &revenue);
                printf("Enter total expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;
            case 4:
                
                printf("Enter employee ID: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, 5);
                if (position == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("Employee found at position %d.\n", position);
                }
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}

void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void displayMenu()
{
    printf("\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int searchEmployee(int id, int ids[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}