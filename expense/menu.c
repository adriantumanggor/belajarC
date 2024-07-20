#include "menu.h"
#include "database.h"
#include "hitung.h"
#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void menu(MYSQL *conn)
{
    int menu_option;
    char *dateStr = selectDate();
    printf("Selected date: %s\n", dateStr);

    printf("HITUNG \n");
    printf("1). Makan\n");
    printf("2). Etc\n");
    printf("3). Exit\n");
    printf("Pilih menu: ");
    scanf("%d", &menu_option);

    switch (menu_option)
    {
    case 1:
        makan_menu(conn, dateStr);
        break;
    case 2:
        etc_menu(conn, dateStr);
        break;
    case 3:
        free(dateStr); // Free allocated memory before exiting
        exit(0);
        break;
    default:
        printf("Pilihan tidak ada\n");
        free(dateStr); // Free allocated memory in case of re-calling menu
        menu(conn);
        break;
    }

    free(dateStr); // Free allocated memory after using it
}

void makan_menu(MYSQL *conn, const char *dateStr)
{
    int makan_option;

    printf("\nPilih makanan:\n");
    printf("1). Sarapan\n");
    printf("2). Siang\n");
    printf("3). Malam\n");
    printf("4). Back\n");
    printf("Pilih menu: ");
    scanf("%d", &makan_option);

    switch (makan_option)
    {
    case 1:
    case 2:
    case 3:
        hitung_makan(conn, makan_option, dateStr);
        break;
    case 4:
        menu(conn);
        break;
    default:
        printf("Pilihan tidak ada\n");
        makan_menu(conn, dateStr);
        break;
    }
}

void etc_menu(MYSQL *conn, const char *dateStr)
{
    int etc_option;

    printf("Pilih etc:\n");
    printf("1). Galon\n");
    printf("2). Paketan\n");
    printf("3). Warkop\n");
    printf("4). Laundry\n");
    printf("5). Back\n");
    printf("Pilih menu: ");
    scanf("%d", &etc_option);

    switch (etc_option)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        hitung_etc(conn, etc_option, dateStr);
        break;
    case 5:
        menu(conn);
        break;
    default:
        printf("Pilihan tidak ada\n");
        etc_menu(conn, dateStr);
        break;
    }
}
