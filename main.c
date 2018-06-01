#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <io.h>
#include "windows.h"
#include "myStruct.h"
#include "func.h"

int main() {
    FILE* fin;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char c, m;
    fin = fopen("database.bin", "a+b");
    fseek(fin, 0, SEEK_END);
    p = ftell(fin) / (2 * (100 * sizeof(char) + 1 * sizeof(int)));
    fseek(fin, 0, SEEK_SET);
    fclose(fin);
    while (1) {
        printf("\nВведите номер функции, которую вы бы хотели выполнить\n");
        printf("1. Заполнить БД\n");
        printf("2. Добавить новую запись в БД\n");
        printf("3. Удалить запись из БД\n");
        printf("4. Найти запись\n");
        printf("5. Редактировать запись\n");
        printf("6. Отсортировать БД\n");
        printf("7. Вывести БД\n");
        printf("8. Очистить БД\n");
        printf("0. Выйти\n");
        scanf("%c%c", &c, &m);
        if (c == '1') {
            fillDB("database.bin");
        }
        else if (c == '2') {
            newNote("database.bin");
        }
        else if (c == '3') {
            deleteNote("database.bin");
        }
        else if (c == '4') {
            findNote("database.bin");
        }
        else if (c == '5') {
            editNote("database.bin");
        }
        else if (c == '6') {
            /*sortDB("database.bin");*/
        }
        else if (c == '7') {
            printDB("database.bin");
        }
        else if (c == '8') {
            deleteDB("database.bin");
        }
        else if (c == '0') {
            break;
        }
        else {
            printf("Incorrect digit\n");
        }
    }
    system("pause");
    return 0;
}
