#ifndef HITUNG_H
#define HITUNG_H

#include <mysql/mysql.h>

void hitung_makan(MYSQL *conn, int option, const char *dateStr);
void hitung_etc(MYSQL *conn, int option, const char *dateStr);

#endif 
