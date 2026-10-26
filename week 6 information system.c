#include <stdio.h>
#include <string.h>
int main()
{
    float salaries[50];
    float salaryTotal = 0;
    float salaryAverage;
    float highestSalary;
    float lowestSalary;
    float searchSalary;
    int salaryFound = 0;

    float budgets[10];
    float budgetTotal = 0;
    float budgetAverage;
    float temp;
    
    char registrations[20][20];
    char searchRegistration[20];
    int registrationFound = 0;
    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("=======================================\n");
    
    printf("\nPART A: EMPLOYEE SALARIES\n");
    
    for (int i = 0; i < 50; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
    
    printf("\nEmployee Salaries\n");
    for (int i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }
    
    highestSalary = salaries[0];
    lowestSalary = salaries[0];
    for (int i = 0; i < 50; i++)
    {
        salaryTotal = salaryTotal + salaries[i];
        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }
        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }
    salaryAverage = salaryTotal / 50;
    printf("\nAverage salary: %.2f\n", salaryAverage);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);
    /* search for a particular salary */
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            salaryFound = 1;
            printf("Salary found at position %d (employee %d)\n", i, i + 1);
            break;
        }
    }
    if (salaryFound == 0)
    {
        printf("Salary not found.\n");
    }
    
    printf("\nPART B: DEPARTMENT BUDGETS\n");
    
    for (int i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
   
    printf("\nDepartment Budgets\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }
    /* total and average */
    for (int i = 0; i < 10; i++)
    {
        budgetTotal = budgetTotal + budgets[i];
    }
    budgetAverage = budgetTotal / 10;
    printf("\nTotal budget: %.2f\n", budgetTotal);
    printf("Average budget: %.2f\n", budgetAverage);
    
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }
    printf("\nBudgets sorted from lowest to highest\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }
    
    printf("\nPART C: VEHICLE REGISTRATION NUMBERS\n");
    
    for (int i = 0; i < 20; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }
    
    printf("\nVehicle Registrations\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d. %s\n", i + 1, registrations[i]);
    }
    
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchRegistration);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            registrationFound = 1;
            printf("Registration found at position %d\n", i);
            break;
        }
    }
    if (registrationFound == 0)
    {
        printf("Registration not found.\n");
    }
    return 0;
}