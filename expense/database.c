#include "database.h"
#include <stdio.h>

void insert_data(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
    } else {
        printf("Data inserted successfully\n");
    }
}