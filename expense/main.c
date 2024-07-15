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

    if (mysql_real_connect(conn, "localhost", "c_appuser", "c_app", "expenses_db", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    menu(conn);
    mysql_close(conn);
    return EXIT_SUCCESS;
}