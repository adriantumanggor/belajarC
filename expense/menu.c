#include "menu.h"
#include "database.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void menu(MYSQL *conn)
{
    int menu_option;
    printf("HITUNG \n");
    printf("1). Makan\n");
    printf("2). Etc\n");
    printf("3). Exit\n");
    printf("Pilih menu: ");
    scanf("%d", &menu_option);

    switch (menu_option)
    {
    case 1:
        hitung_makan(conn);
        break;
    case 2:
        menu_etc(conn);
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan tidak ada\n");
        menu(conn);
        break;
    }
}

void hitung_makan(MYSQL *conn)
{
    Makan makan;

    printf("Makan Pagi: ");
    scanf("%d", &makan.pagi);

    printf("Makan Siang: ");
    scanf("%d", &makan.siang);

    printf("Makan Malem: ");
    scanf("%d", &makan.malem);

    int total = makan.pagi + makan.siang + makan.malem;
    printf("Total: %d\n", total);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO makan (pagi, siang, malem, total) VALUES (%d, %d, %d, %d)", makan.pagi, makan.siang, makan.malem, total);
    insert_data(conn, query);

    menu(conn);
}

void menu_etc(MYSQL *conn)
{
    Etc etc;
    int pilih;

    printf("1). Galon\n");
    printf("2). Kuota\n");
    printf("3). Warkop\n");
    printf("4). Bensin\n");
    printf("5). back\n");
    printf("Pilih menu: ");

    switch (pilih)
    {
    case 1:
        int jenis_galon, harga_galon;
        printf("jenis Galon: \n");
        printf("1). Aqua\n");
        printf("2). Isi ulang\n");
        scanf("%d", &jenis_galon);
        if (jenis_galon == 1)
        {
            etc.galon = 21;
        }
        else
        {
            etc.galon = 7;
        }
        break;
    case 2:
        printf("Kuota: ");
        scanf("%d", &etc.kuota);
        break;
    case 3:
        printf("Warkop: ");
        scanf("%d", &etc.warkop);
        break;
    case 4:
        printf("Bensin: ");
        scanf("%d", &etc.bensin);
        break;
    case 5:
        exit(0);
        menu(conn);

        break;
    default:
        printf("Pilihan tidak ada\n");
        menu_etc(conn);
        break;
    }

    int total = etc.galon + etc.kuota + etc.warkop + etc.bensin;
    printf("Total: %d\n", total);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO etc (galon, kuota, warkop, bensin, total) VALUES (%d, %d, %d, %d, %d)", etc.galon, etc.kuota, etc.warkop, etc.bensin, total);
    insert_data(conn, query);

    menu(conn);
}
