#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>

void insert_data(MYSQL *conn, const char *query);

#endif // DATABASE_H
