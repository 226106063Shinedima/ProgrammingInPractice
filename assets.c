#include <stdio.h>
#include <string.h>
#include "records.h"
#include "assets.h"
#include "utilities.h"
Asset assets[MAX_RECORDS];
int assetCount = 0;
void addAsset(void)
{
    int id;
    int i;
    int duplicate = 0;
    char description[40];
    double value;
    Date acquired;
    if (assetCount >= MAX_RECORDS)
    {
        printf("Asset list is full.\n");
        return;
    }
    printf("Enter asset ID: ");
    id = readInt();
    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            duplicate = 1;
        }
    }
    if (duplicate == 1)
    {
        printf("An asset with ID %d already exists.\n", id);
        return;
    }
    printf("Enter asset description: ");
    readString(description, sizeof(description));
    printf("Enter asset value: ");
    value = readDouble();
    printf("Date acquired - day: ");
    acquired.day = readInt();
    printf("Date acquired - month: ");
    acquired.month = readInt();
    printf("Date acquired - year: ");
    acquired.year = readInt();
    if (value < 0)
    {
        printf("Value cannot be negative.\n");
        return;
    }
    if (isValidDate(acquired) == 0)
    {
        printf("That is not a valid date. Asset not added.\n");
        return;
    }
    assets[assetCount].id = id;
    strcpy(assets[assetCount].description, description);
    assets[assetCount].value = value;
    assets[assetCount].acquired = acquired;
    assetCount++;
    printf("Asset added.\n");
}
void displayAssets(void)
{
    int i;
    int best = 0;
    double total = 0.0;
    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }
    printf("\n%-6s %-25s %14s %12s\n", "ID", "Description", "Value (N$)", "Acquired");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < assetCount; i++)
    {
        printf("%-6d %-25s %14.2f %02d/%02d/%d\n", assets[i].id,
               assets[i].description, assets[i].value,
               assets[i].acquired.day, assets[i].acquired.month,
               assets[i].acquired.year);
        total = total + assets[i].value;
    }

    for (i = 1; i < assetCount; i++)
    {
        if (assets[i].value > assets[best].value)
        {
            best = i;
        }
    }
    printf("\nTotal value of assets: N$%.2f\n", total);
    printf("Most valuable asset: %s (N$%.2f)\n",
           assets[best].description, assets[best].value);
}
int getAssetCount(void)
{
    return assetCount;
}
void saveAssets(void)
{
    FILE *fp;
    int i;
    fp = fopen("data/assets.txt", "w");
    if (fp == NULL)
    {
        perror("data/assets.txt");
        return;
    }
    for (i = 0; i < assetCount; i++)
    {
        fprintf(fp, "%d|%s|%.2f|%d|%d|%d\n", assets[i].id,
                assets[i].description, assets[i].value,
                assets[i].acquired.day, assets[i].acquired.month,
                assets[i].acquired.year);
    }
    fclose(fp);
    printf("%d asset(s) saved to data/assets.txt\n", assetCount);
}
void loadAssets(void)
{
    FILE *fp;
    fp = fopen("data/assets.txt", "r");
    if (fp == NULL)
    {
        printf("No saved asset file found (data/assets.txt).\n");
        return;
    }
    assetCount = 0;
    while (assetCount < MAX_RECORDS &&
           fscanf(fp, "%d|%39[^|]|%lf|%d|%d|%d",
                  &assets[assetCount].id,
                  assets[assetCount].description,
                  &assets[assetCount].value,
                  &assets[assetCount].acquired.day,
                  &assets[assetCount].acquired.month,
                  &assets[assetCount].acquired.year) == 6)
    {
        assetCount++;
    }
    fclose(fp);
    printf("%d asset(s) loaded from data/assets.txt\n", assetCount);
}