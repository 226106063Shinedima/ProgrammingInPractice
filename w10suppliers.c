#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"
#define MAX_SUPPLIERS 20
char supplierNames[MAX_SUPPLIERS][50];
char supplierEmails[MAX_SUPPLIERS][50];
char supplierPhones[MAX_SUPPLIERS][20];
char supplierTowns[MAX_SUPPLIERS][30];
int supplierCount = 0;
void addSupplier(void)

{
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }
    printf("Enter supplier name: ");
    readString(name, sizeof(name));
    printf("Enter email: ");
    readString(email, sizeof(email));
    printf("Enter phone: ");
    readString(phone, sizeof(phone));
    printf("Enter town: ");
    readString(town, sizeof(town));
    strcpy(supplierNames[supplierCount], name);
    strcpy(supplierEmails[supplierCount], email);
    strcpy(supplierPhones[supplierCount], phone);
    strcpy(supplierTowns[supplierCount], town);
    supplierCount++;
    printf("Supplier added.\n");
}
void listSuppliers(void)
{
    int i;
    if (supplierCount == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }
    printf("\n--- SUPPLIERS ---\n");
    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}
int getSupplierCount(void)
{
    return supplierCount;
}

void saveSuppliers(void)
{
    FILE *fp;
    int i;
    fp = fopen("data/suppliers.txt", "w");
    if (fp == NULL)
    {
    }
        perror("data/suppliers.txt");
        return;
    for (i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%s|%s|%s|%s\n", supplierNames[i], supplierEmails[i],
                supplierPhones[i], supplierTowns[i]);
    }
    fclose(fp);
    printf("%d supplier(s) saved to data/suppliers.txt\n", supplierCount);
}
void loadSuppliers(void)
{
    FILE *fp;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
    fp = fopen("data/suppliers.txt", "r");
    if (fp == NULL)
    {
    }
        printf("No saved supplier file found (data/suppliers.txt).\n");
        return;
    supplierCount = 0;
    while (supplierCount < MAX_SUPPLIERS &&
           fscanf(fp, " %49[^|]|%49[^|]|%19[^|]|%29[^\n]",
                  name, email, phone, town) == 4)
    {
    }
        strcpy(supplierNames[supplierCount], name);
        strcpy(supplierEmails[supplierCount], email);
        strcpy(supplierPhones[supplierCount], phone);
        strcpy(supplierTowns[supplierCount], town);
        supplierCount++;
    fclose(fp);
    printf("%d supplier(s) loaded from data/suppliers.txt\n", supplierCount);
}