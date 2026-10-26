#include <stdio.h>
#include <string.h>
#define MAX_SUPPLIERS 5

char names[MAX_SUPPLIERS][100];
char emails[MAX_SUPPLIERS][100];
char phones[MAX_SUPPLIERS][30];
char towns[MAX_SUPPLIERS][50];
int supplierCount = 0;

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int main()
{
    int choice;
    float amount;
    float basic;
    float housing;
    float transport;
    float revenue;
    float expenses;
    float balance;
    do
    {
        displayMenu();
        scanf("%d", &choice);
        getchar();  
        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            case 5:
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;
            case 6:
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
            case 7:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}
void displayMenu()
{
    printf("\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}
void addSupplier()
{
    char temp[100];
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier name: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(names[supplierCount], temp);
    printf("Enter email: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(emails[supplierCount], temp);
    printf("Enter phone: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(phones[supplierCount], temp);
    printf("Enter town: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(towns[supplierCount], temp);
    supplierCount++;
    printf("Supplier added.\n");
}
void displaySupplier()
{
    int i;
    if (supplierCount == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }
    printf("\n--- SUPPLIER DETAILS ---\n");
    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }
}
void searchSupplier()
{
    char searchName[100];
    int i;
    int found = 0;
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            found = 1;
            printf("Supplier found.\n");
            printf("Name : %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town : %s\n", towns[i]);
            break;
        }
    }
    if (found == 0)
    {
        printf("Supplier not found.\n");
    }
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