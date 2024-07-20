#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "menu.h"

int main() {
    MYSQL *conn;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "c_appuser", "c_app", "expense", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // Moved the code from menu function here
    char *dateStr = selectDate();
    printf("Selected date: %s\n", dateStr);

    menu(conn, dateStr);

    free(dateStr); // Free allocated memory before exiting
    mysql_close(conn);
    return EXIT_SUCCESS;
}
