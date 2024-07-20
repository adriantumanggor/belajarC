#include "hitung.h"
#include "database.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>

void hitung_makan(MYSQL *conn, int option, const char *dateStr)
{
    int amount, category_id;

    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("Enter category ID: ");
    scanf("%d", &category_id);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO transactions (date, amount, category_id) VALUES ('%s', %d, %d)", dateStr, amount, category_id);

    insert_data(conn, query);
}

void hitung_etc(MYSQL *conn, int option, const char *dateStr)
{
    int amount, category_id;

    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("Enter category ID: ");
    scanf("%d", &category_id);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO transactions (date, amount, category_id) VALUES ('%s', %d, %d)", dateStr, amount, category_id);

    insert_data(conn, query);
}
