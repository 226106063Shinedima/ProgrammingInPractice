#include <stdio.h>
int main()
{
    float salaries[50];
    float total = 0;
    float average;
    float highest;
    float lowest;
    float searchSalary;
    float temp;
    int found = 0;
    printf("EMPLOYEE SALARY MANAGEMENT SYSTEM\n");
    printf("---------------------------------\n");
    
    for (int i = 0; i < 50; i++)
    {
        do
        {
            printf("Enter salary for employee %d: ", i + 1);
            scanf("%f", &salaries[i]);
            if (salaries[i] <= 0)
            {
                printf("The salary must be more than zero. Try again.\n");
            }
        } while (salaries[i] <= 0);
    }
   
    printf("\n--- ALL SALARIES ---\n");
    for (int i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }
   
    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 0; i < 50; i++)
    {
        total = total + salaries[i];
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }
    
    average = total / 50;
    printf("\n--- SALARY REPORT ---\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            found = 1;
            printf("Salary found at position %d (employee %d)\n", i, i + 1);
            break;
        }
    }
    if (found == 0)
    {
        printf("Salary not found.\n");
    }
   
    for (int i = 0; i < 50 - 1; i++)
    {
        for (int j = 0; j < 50 - i - 1; j++)
        {
            if (salaries[j] > salaries[j + 1])
            {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }
   
    printf("\n--- SALARIES SORTED FROM LOWEST TO HIGHEST ---\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d. %.2f\n", i + 1, salaries[i]);
    }
    return 0;
}