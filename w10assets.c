#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"
#define MAX_ASSETS 30
char assetDescriptions[MAX_ASSETS][50];
double assetValues[MAX_ASSETS];
int assetCount = 0;
void addAsset(void)
{
    char description[50];
    double value;
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset list is full.\n");
        return;
    }
    printf("Enter asset description: ");
    readString(description, sizeof(description));
    printf("Enter asset value: ");
    value = readDouble();
    if (value < 0)
    {
        printf("Value cannot be negative.\n");
        return;
    }
    strcpy(assetDescriptions[assetCount], description);
    assetValues[assetCount] = value;
    assetCount++;
    printf("Asset added.\n");
}
void listAssets(void)
{
    int i;
    double total = 0.0;
    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }
    printf("\n%-30s %15s\n", "Description", "Value");
    printf("------------------------------------------------\n");
    for (i = 0; i < assetCount; i++)
    {
        printf("%-30s %15.2f\n", assetDescriptions[i], assetValues[i]);
        total = total + assetValues[i];
    }
    printf("------------------------------------------------\n");
    printf("%-30s %15.2f\n", "Total value", total);
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
        fprintf(fp, "%s|%.2f\n", assetDescriptions[i], assetValues[i]);
    }
    fclose(fp);
    printf("%d asset(s) saved to data/assets.txt\n", assetCount);
}
void loadAssets(void)
{
    FILE *fp;
    char description[50];
    double value;
    fp = fopen("data/assets.txt", "r");
    if (fp == NULL)
    {
        printf("No saved asset file found (data/assets.txt).\n");
        return;
    }
    assetCount = 0;
    while (assetCount < MAX_ASSETS &&
           fscanf(fp, " %49[^|]|%lf", description, &value) == 2)
    {
    }
        strcpy(assetDescriptions[assetCount], description);
        assetValues[assetCount] = value;
        assetCount++;
    fclose(fp);
    printf("%d asset(s) loaded from data/assets.txt\n", assetCount);
}