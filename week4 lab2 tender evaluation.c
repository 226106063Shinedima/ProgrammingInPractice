#include <stdio.h>
int main()
{
    char supplierName[50];
    float price;
    float budget;
    int registered;
    int documentsComplete;
    printf("TENDER EVALUATION\n");
    printf("-----------------\n");
    printf("Enter supplier name: ");
    scanf("%49s", supplierName);
    printf("Enter tender price: ");
    scanf("%f", &price);
    printf("Enter available budget: ");
    scanf("%f", &budget);
    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);
    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);
    printf("\nSupplier: %s\n", supplierName);
     if (registered == 1 && documentsComplete == 1 && price <= budget)
    {
        printf("Status: Qualified\n");
    }
    else
    {
        printf("Status: Disqualified\n");
        if (registered == 0)
        {
            printf("Reason: Supplier is not registered.\n");
        }
        if (documentsComplete == 0)
        {
            printf("Reason: Documents are not complete.\n");
        }
        if (price > budget)
        {
            printf("Reason: Price is more than the budget.\n");
        }
    }
    return 0;
}