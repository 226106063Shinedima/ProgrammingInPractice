#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clearInput(void)
{
}
    int c;
    c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
int readInt(void)
{
}
    int number;
    int result;
    result = scanf("%d", &number);
    while (result != 1)
    {
        if (result == EOF)
        {
            return 0;
        }
        printf("Invalid input. Enter a whole number: ");
        clearInput();
        result = scanf("%d", &number);
    }
    clearInput();
    return number;
double readDouble(void)
{
}
    double number;
    int result;
    result = scanf("%lf", &number);
    while (result != 1)
    {
        if (result == EOF)
        {
            return 0.0;
        }
        printf("Invalid input. Enter a number: ");
        clearInput();
        result = scanf("%lf", &number);
    }
    clearInput();
    return number;
void readString(char text[], int size)
{
    int i;
    if (fgets(text, size, stdin) == NULL)
    {
        text[0] = '\0';
        return;
    }
    text[strcspn(text, "\n")] = '\0'; 
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '|')
        {
            text[i] = '-';
        }
    }
}
void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}