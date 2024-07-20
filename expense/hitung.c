#include "hitung.h"
#include "database.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>

void hitung_makan(MYSQL *conn, int option, const char *dateStr)
{
    int amount, category_id;

    // Ask for the amount and category_id
    printf("Hargaa: ");
    scanf("%d", &amount);

    category_id = option;
    
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO transactions (date, amount, category_id) VALUES ('%s', %d, %d)", dateStr, amount, category_id);

    insert_data(conn, query);
}

void hitung_etc(MYSQL *conn, int option, const char *dateStr)
{
    int amount, category_id;

    // Ask for the amount and category_id
    printf("Enter amount: ");
    scanf("%d", &amount);

    category_id = option;

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO transactions (date, amount, category_id) VALUES ('%s', %d, %d)", dateStr, amount, category_id);

    insert_data(conn, query);

    
}
