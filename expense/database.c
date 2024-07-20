#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void insert_data(MYSQL *conn, const char *query)
{
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Data inserted successfully.\n");
    }
}
