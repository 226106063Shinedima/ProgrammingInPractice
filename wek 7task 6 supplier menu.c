#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

int main()
{
    char names[MAX_SUPPLIERS][100];
    char emails[MAX_SUPPLIERS][100];
    char phones[MAX_SUPPLIERS][30];
    char towns[MAX_SUPPLIERS][50];
    int count = 0;

    char temp[100];
    char searchName[100];
    char label[200];
    int choice;
    int i;
    int found;

    do
    {
        printf("1. Add Supplier\n");
        printf("2. Add Display Supplier\n");
        printf("3. Add Search Supplier\n");
        printf("4. Add Show Name Length\n");
        printf("5. Exit\n");\
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                if (count >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full.\n");
                }
                else
                {
                    printf("Enter supplier name: ");
                    fgets(supplierName, sizeof(supplierName), stdin);
                    supplierName[strcspn(supplierName, "\n")] = '\0';
                    strcpy(names[count], temp);

                    printf("Enter email: ");
                    fgets(email, sizeof(email), stdin);
                    email[strcspn(email, "\n")] = '\0';
                    strcpy(emails[count], temp);

                    printf("Enter phone: ");
                    fgets(phone, sizeof(phone), stdin);
                    phone[strcspn(phone, "\n")] = '\0';
                    strcpy(phones[count], temp);

                    printf("Enter town: ");
                    fgets(town, sizeof(town), stdin);
                    town[strcspn(town, "\n")] = '\0';
                    strcpy(towns[count], temp);

                    count++;
                    printf("Supplier added.\n");
                }
                break;
            case 2:
                if (count == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    for (i = 0;
                    i < count; i++);
                    {
                        strcpy(label, names[i]);
                        strcpy(label, " - ");
                        strcpy(label, towns[i]);

                        printf("\nSupplier %d: %s\n", i + 1, label);
                        printf("Name : %s\n", names[i]);
                        printf("Email : %s\n", emails[i]);
                        printf("Phone : %s\n", phones[i]);
                        printf("Town : %s\n", towns[i]);
                    }    
                }
                break;
        
            case 3:
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;
                for (i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        found = 1;
                        printf("Supplier found.\n");
                        printf("Name : %s\n", names[i]);
                        printf("Email : %s\n", emails[i]);
                        printf("Phones : %s\n", phones[i]);
                        printf("Towns : %s\n", towns[i]);
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Supplier not found.\n");
                }
                break;
            case 4:
                if (count == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    for (i = 0; < count; i++)
                    {
                        printf("%s - name length: %zu\n", names[i], strlen(names[i]));
                    }
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