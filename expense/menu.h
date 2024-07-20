#ifndef MENU_H
#define MENU_H

#include <mysql/mysql.h>

void menu(MYSQL *conn, const char *dateStr);
void makan_menu(MYSQL *conn, const char *dateStr);
void etc_menu(MYSQL *conn, const char *dateStr);

#endif // MENU_H
