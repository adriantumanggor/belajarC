#ifndef MENU_H
#define MENU_H

#include <mysql/mysql.h>

void menu(MYSQL *conn);
void hitung_makan(MYSQL *conn);
void menu_etc(MYSQL *conn);

#endif