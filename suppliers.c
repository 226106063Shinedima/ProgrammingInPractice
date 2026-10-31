#include <stdio.h>
#include <string.h>
#include "records.h"
#include "suppliers.h"
#include "utilities.h"
Supplier suppliers[MAX_RECORDS];
int supplierCount = 0;
void addSupplier(void)
{
    int id;
    int i;
    int duplicate = 0;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
    if (supplierCount >= MAX_RECORDS)
    {
        printf("Supplier list is full.\n");
        return;
    }
    printf("Enter supplier ID: ");
    id = readInt();
    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id)
        {
            duplicate = 1;
        }
    }
    if (duplicate == 1)
    {
        printf("A supplier with ID %d already exists.\n", id);
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
    suppliers[supplierCount].id = id;
    strcpy(suppliers[supplierCount].name, name);
    strcpy(suppliers[supplierCount].email, email);
    strcpy(suppliers[supplierCount].phone, phone);
    strcpy(suppliers[supplierCount].town, town);
    supplierCount++;
    printf("Supplier added.\n");
}
void displaySuppliers(void)
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
        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name : %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town : %s\n", suppliers[i].town);
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
        perror("data/suppliers.txt");
        return;
    }
    for (i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%d|%s|%s|%s|%s\n", suppliers[i].id, suppliers[i].name,
                suppliers[i].email, suppliers[i].phone, suppliers[i].town);
    }
    fclose(fp);
    printf("%d supplier(s) saved to data/suppliers.txt\n", supplierCount);
}
void loadSuppliers(void)
{
    FILE *fp;
    fp = fopen("data/suppliers.txt", "r");
    if (fp == NULL)
    {
        printf("No saved supplier file found (data/suppliers.txt).\n");
        return;
    }
    supplierCount = 0;
    while (supplierCount < MAX_RECORDS &&
           fscanf(fp, "%d|%39[^|]|%39[^|]|%14[^|]|%19[^\n]",
                  &suppliers[supplierCount].id,
                  suppliers[supplierCount].name,
                  suppliers[supplierCount].email,
                  suppliers[supplierCount].phone,
                  suppliers[supplierCount].town) == 5)
    {
        supplierCount++;
    }
    fclose(fp);
    printf("%d supplier(s) loaded from data/suppliers.txt\n", supplierCount);
}