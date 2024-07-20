#include "date.h"
#include <stdio.h>
#include <time.h>

static void getToday(int *day, int *month, int *year)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *year = tm.tm_year + 1900;
    *month = tm.tm_mon + 1;
    *day = tm.tm_mday;
}

static void getYesterday(int *day, int *month, int *year)
{
    time_t t = time(NULL) - 86400; // Subtract 24 hours (86400 seconds)
    struct tm tm = *localtime(&t);
    *year = tm.tm_year + 1900;
    *month = tm.tm_mon + 1;
    *day = tm.tm_mday;
}

char* selectDate()
{
    int choice;
    int day, month, year;
    printf("Select an option:\n1. Today\n2. Yesterday\n3. Enter date manually\nChoice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        getToday(&day, &month, &year);
        break;
    case 2:
        getYesterday(&day, &month, &year);
        break;
    case 3:
        printf("Enter day: ");
        scanf("%d", &day);
        printf("Enter month: ");
        scanf("%d", &month);
        printf("Enter year: ");
        scanf("%d", &year);
        break;
    default:
        printf("Invalid choice.\n");
        selectDate();
    }

     char dateStr[11];
    snprintf(dateStr, sizeof(dateStr), "%04d-%02d-%02d", year, month, day);
    return dateStr;
}

