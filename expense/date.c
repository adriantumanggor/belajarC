#include "date.h"
#include <stdio.h>
#include <stdlib.h> // For malloc
#include <time.h>

void getToday(int *day, int *month, int *year)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *year = tm.tm_year + 1900;
    *month = tm.tm_mon + 1;
    *day = tm.tm_mday;
}

void getYesterday(int *day, int *month, int *year)
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
        return selectDate();
    }

    char *dateStr = malloc(11 * sizeof(char)); // Allocate memory for the date string
    if (dateStr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    snprintf(dateStr, 11, "%04d-%02d-%02d", year, month, day);
    return dateStr;
}
