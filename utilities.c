#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clearInput(void)
{
    int c;
    c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
int readInt(void)
{
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
}

double readDouble(void)
{
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
}
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
int isValidDate(Date d)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay;
    if (d.year < 1900 || d.year > 2100)
    {
        return 0;
    }
    if (d.month < 1 || d.month > 12)
    {
        return 0;
    }
    maxDay = daysInMonth[d.month - 1];
 
    if (d.month == 2)
    {
        if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        {
            maxDay = 29;
        }
    }
    if (d.day < 1 || d.day > maxDay)
    {
        return 0;
    }
    return 1;
}
int dateIsBefore(Date first, Date second)
{
    if (first.year != second.year)
    {
        return first.year < second.year;
    }
    if (first.month != second.month)
    {
        return first.month < second.month;
    }
    return first.day < second.day;
}