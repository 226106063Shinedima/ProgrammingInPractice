#ifndef UTILITIES_H
#define UTILITIES_H
#include "records.h"
void clearInput(void);
int readInt(void);
double readDouble(void);
void readString(char text[], int size);
void pauseScreen(void);
int isValidDate(Date d);
int dateIsBefore(Date first, Date second);
#endif