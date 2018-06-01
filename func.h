#include "myStruct.h"

int p = 0;

void printDB(char* filename) {
    FILE* fin;
    man a;
    int g;
    fin = fopen(filename, "rb");
    for (g = 0; g < p; g++) {
        fseek(fin, g * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
        fread(a.surname, sizeof(char), 20, fin);
        printf("%d. Жених: %-20s", g + 1, a.surname);
        fread(a.name, sizeof(char), 20, fin);
        printf("%-20s", a.name);
        fread(a.secondname, sizeof(char), 20, fin);
        printf("%-20s", a.secondname);
        fread(&a.birthyear, sizeof(int), 1, fin);
        printf("%-5d", a.birthyear);
        fread(a.adress, sizeof(char), 20, fin);
        printf("%-20s", a.adress);
        fread(a.telephone, sizeof(char), 20, fin);
        printf("%-20s\n", a.telephone);
        fread(a.surname, sizeof(char), 20, fin);
        printf("Невеста: %-20s", a.surname);
        fread(a.name, sizeof(char), 20, fin);
        printf("%-20s", a.name);
        fread(a.secondname, sizeof(char), 20, fin);
        printf("%-20s", a.secondname);
        fread(&a.birthyear, sizeof(int), 1, fin);
        printf("%-5d", a.birthyear);
        fread(a.adress, sizeof(char), 20, fin);
        printf("%-20s", a.adress);
        fread(a.telephone, sizeof(char), 20, fin);
        printf("%-20s\n", a.telephone);
    }
    fclose(fin);
}

void deleteDB(char* filename) {
    FILE* fout;
    char* s = (char*)malloc(2);
    printf("Предыдущая БД будет безвозратно удалена. Вы хотите продолжить? (+/-) ");
    gets(s);
    if (!strcmp(s, "+")) {
        fout = fopen(filename, "wb");
        fclose(fout);
        p = 0;
    }
    free(s);
}

void newNote(char* filename) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    FILE* fout;
    char c, m;
    man a;
    char* t = (char*)malloc(2);
    int n = 0, da, err;
    p++;
    fout = fopen(filename, "a+b");
    printf("Введите фамилию жениха: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных фамилий. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.surname, t);
                fwrite(a.surname, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите имя жениха: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных имен. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.name, t);
                fwrite(a.name, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите отчество жениха: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных отчеств. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.secondname, t);
                fwrite(a.secondname, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите год рождения жениха: ");
    while (1) {
        err = scanf("%d%c", &a.birthyear, &m);
        if (err != 2) {
            printf("Неправильный год рождения. Попробуйте еще раз\n");
        } else {
            fwrite(&a.birthyear, sizeof(int), 1, fout);
            break;
        }
    }
    printf("Введите адрес жениха: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных адресов. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.adress, t);
                fwrite(a.adress, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите телефон жениха: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных номеров телефона. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.telephone, t);
                fwrite(a.telephone, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите фамилию невесты: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных фамилий. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.surname, t);
                fwrite(a.surname, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите имя невесты: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных имен. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.name, t);
                fwrite(a.name, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите отчество невесты: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных отчеств. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.secondname, t);
                fwrite(a.secondname, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите год рождения невесты: ");
    while (1) {
        err = scanf("%d%c", &a.birthyear, &m);
        if (err != 2) {
            printf("Неправильный год рождения. Попробуйте еще раз\n");
        }
        else {
            fwrite(&a.birthyear, sizeof(int), 1, fout);
            break;
        }
    }
    printf("Введите адрес невесты: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных адресов. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.adress, t);
                fwrite(a.adress, sizeof(char), 20, fout);
                break;
            }
        }
    }
    printf("Введите телефон невесты: ");
    while (1) {
        scanf("%c", &c);
        if (c != '\n') {
            t[n] = c;
            n++;
            t[n] = '\0';
            t = realloc(t, n + 1);
        }
        else {
            t[n] = '\0';
            if (n > 20) {
                printf("Не существует таких длинных номеров телефона. Попробуйте еще раз\n");
                n = 0;
            }
            else {
                n = 0;
                strcpy(a.telephone, t);
                fwrite(a.telephone, sizeof(char), 20, fout);
                break;
            }
        }
    }
    fclose(fout);
    free(t);
}

void fillDB(char* filename) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k, err, i;
    char m;
    printf("Сколько записей вы хотите добавить?\n");
    err = scanf("%d%c", &k, &m);
    if (k < 0) {
        printf("Невозможно добавить отрицательное количество записей\n");
    }
    else if (err != 2) {
        printf("ERROR\n");
        exit(10);
    }
    else {
        for (i = 0; i < k; i++) {
            printf("\nЗапись №%d\n", i + 1);
            newNote(filename);
        }
    }
}

void deleteNote(char* filename) {
    FILE* fin;
    int n, q, g = 0, err, k;
    man wife, husband;
    char c, m;
    printf("Введите номер записи, которую хотите удалить: ");
    err = scanf("%d%c", &k, &m);
    if (k > p || k < 1) {
        printf("Такой записи не существует\n");
    }
    else if (err != 2) {
        printf("ERROR\n");
        exit(10);
    }
    else {
        fin = fopen(filename, "r+b");
        for (k; k < p; k++) {
            fseek(fin, k * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
            fread(husband.surname, sizeof(char), 20, fin);
            fread(husband.name, sizeof(char), 20, fin);
            fread(husband.secondname, sizeof(char), 20, fin);
            fread(husband.birthyear, sizeof(int), 1, fin);
            fread(husband.adress, sizeof(char), 20, fin);
            fread(husband.telephone, sizeof(char), 20, fin);
            fread(wife.surname, sizeof(char), 20, fin);
            fread(wife.name, sizeof(char), 20, fin);
            fread(wife.secondname, sizeof(char), 20, fin);
            fread(wife.birthyear, sizeof(int), 1, fin);
            fread(wife.adress, sizeof(char), 20, fin);
            fread(wife.telephone, sizeof(char), 20, fin);
            fseek(fin, (k - 1) * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
            fwrite(husband.surname, sizeof(char), 20, fin);
            fwrite(husband.name, sizeof(char), 20, fin);
            fwrite(husband.secondname, sizeof(char), 20, fin);
            fwrite(husband.birthyear, sizeof(int), 1, fin);
            fwrite(husband.adress, sizeof(char), 20, fin);
            fwrite(husband.telephone, sizeof(char), 20, fin);
            fwrite(wife.surname, sizeof(char), 20, fin);
            fwrite(wife.name, sizeof(char), 20, fin);
            fwrite(wife.secondname, sizeof(char), 20, fin);
            fwrite(wife.birthyear, sizeof(int), 1, fin);
            fwrite(wife.adress, sizeof(char), 20, fin);
            fwrite(wife.telephone, sizeof(char), 20, fin);
        }
        p--;
        fseek(fin, 0, SEEK_END);
        n = ftell(fin);
        fseek(fin, 0, SEEK_SET);
        _chsize(_fileno(fin), n - 2 * (100 * sizeof(char) + 1 * sizeof(int)));
        fclose(fin);
    }
}

void findNote(char* filename) {
    FILE* fin;
    char* s = (char*)malloc(16);
    char* q = (char*)malloc(16);
    int i, k = 0, da = 0, by;
    man wife, husband;
    fin = fopen(filename, "rb");
    printf("Введите поле, по которому будет идти поиск (Фамилия/Имя/Отчество/Год рождения/Адрес/Номер телефона): ");
    gets(s);
    if (!strcmp(s, "Фамилия")) {
        printf("Введите значение данного поля у искомой записи: ");
        gets(q);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
            fread(husband.surname, sizeof(char), 20, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
            fread(wife.surname, sizeof(char), 20, fin);
            if (!strcmp(husband.surname, q) || !strcmp(wife.surname, q)) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else if (!strcmp(s, "Имя")) {
        printf("Введите значение данного поля у искомой записи: ");
        gets(q);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)) + 20 * sizeof(char), SEEK_SET);
            fread(husband.name, sizeof(char), 20, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)) + 20 * sizeof(char), SEEK_SET);
            fread(wife.name, sizeof(char), 20, fin);
            if (!strcmp(husband.name, q) || !strcmp(wife.name, q)) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else if (!strcmp(s, "Отчество")) {
        printf("Введите значение данного поля у искомой записи: ");
        gets(q);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)) + 2 * 20 * sizeof(char), SEEK_SET);
            fread(husband.secondname, sizeof(char), 20, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)) + 2 * 20 * sizeof(char), SEEK_SET);
            fread(wife.secondname, sizeof(char), 20, fin);
            if (!strcmp(husband.secondname, q) || !strcmp(wife.secondname, q)) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else if (!strcmp(s, "Год рождения")) {
        scanf("%d", &by);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)) + 3 * 20 * sizeof(char), SEEK_SET);
            fread(&husband.birthyear, sizeof(int), 1, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)) + 3 * 20 * sizeof(char), SEEK_SET);
            fread(&wife.birthyear, sizeof(int), 1, fin);
            if (husband.birthyear == by || wife.birthyear == by) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else if (!strcmp(s, "Адрес")) {
        printf("Введите значение данного поля у искомой записи: ");
        gets(q);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)) + 3 * 20 * sizeof(char) + 1 * sizeof(int), SEEK_SET);
            fread(husband.adress, sizeof(char), 20, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)) + 3 * 20 * sizeof(char) + 1 * sizeof(int), SEEK_SET);
            fread(wife.adress, sizeof(char), 20, fin);
            if (!strcmp(husband.adress, q) || !strcmp(wife.adress, q)) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else if (!strcmp(s, "Номер телефона")) {
        printf("Введите значение данного поля у искомой записи: ");
        gets(q);
        for (i = 0; i < p; i++) {
            fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)) + 4 * 20 * sizeof(char) + 1 * sizeof(int), SEEK_SET);
            fread(husband.telephone, sizeof(char), 20, fin);
            fseek(fin, i * 3 * (100 * sizeof(char) + 1 * sizeof(int)) + 4 * 20 * sizeof(char) + 1 * sizeof(int), SEEK_SET);
            fread(wife.telephone, sizeof(char), 20, fin);
            if (!strcmp(husband.telephone, q) || !strcmp(wife.telephone, q)) {
                fseek(fin, i * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
                fread(husband.surname, sizeof(char), 20, fin);
                printf("%d. Жених: %-20s", i + 1, husband.surname);
                fread(husband.name, sizeof(char), 20, fin);
                printf("%-20s", husband.name);
                fread(husband.secondname, sizeof(char), 20, fin);
                printf("%-20s", husband.secondname);
                fread(husband.birthyear, sizeof(int), 1, fin);
                printf("%-4d", husband.birthyear);
                fread(husband.adress, sizeof(char), 20, fin);
                printf("%-20s", husband.adress);
                fread(husband.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", husband.telephone);
                printf("Невеста: %-20s", wife.surname);
                fread(wife.name, sizeof(char), 20, fin);
                printf("%-20s", wife.name);
                fread(wife.secondname, sizeof(char), 20, fin);
                printf("%-20s", wife.secondname);
                fread(wife.birthyear, sizeof(int), 1, fin);
                printf("%-4d", wife.birthyear);
                fread(wife.adress, sizeof(char), 20, fin);
                printf("%-20s", wife.adress);
                fread(wife.telephone, sizeof(char), 20, fin);
                printf("%-20s\n", wife.telephone);
                k++;
            }
        }
    }
    else {
        printf("Неверное значение поля\n");
        da = 1;
    }
    if (k == 0 && da != 1) {
        printf("Записи не существует\n");
    }
    fclose(fin);
}

void editNote(char* filename) {
    man a;
    FILE* fin;
    int da = 0, n = 0, err, k;
    char c, m;
    char* t = (char*)malloc(16);
    fin = fopen(filename, "r+b");
    printf("Введите номер записи, которую хотите отредактировать: ");
    err = scanf("%d%c", &k, &m);
    if (k > p || k < 1) {
        printf("Такой записи не существует\n");
    }
    else if (err != 2) {
        printf("ERROR\n");
        exit(10);
    }
    else {
        fseek(fin, (k - 1) * 2 * (100 * sizeof(char) + 1 * sizeof(int)), SEEK_SET);
        printf("Введите фамилию жениха: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных фамилий. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.surname, t);
                    fwrite(a.surname, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите имя жениха: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных имен. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.name, t);
                    fwrite(a.name, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите отчество жениха: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных отчеств. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.secondname, t);
                    fwrite(a.secondname, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите год рождения жениха: ");
        while (1) {
            err = scanf("%d", &a.birthyear);
            if (err != 1) {
                printf("Неправильный год рождения. Попробуйте еще раз\n");
            }
            else {
                fwrite(a.birthyear, sizeof(int), 1, fin);
                break;
            }
        }
        printf("Введите адрес жениха: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных адресов. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.adress, t);
                    fwrite(a.adress, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите телефон жениха: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных номеров телефона. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.telephone, t);
                    fwrite(a.telephone, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите фамилию невесты: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных фамилий. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.surname, t);
                    fwrite(a.surname, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите имя невесты: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных имен. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.name, t);
                    fwrite(a.name, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите отчество невесты: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных отчеств. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.secondname, t);
                    fwrite(a.secondname, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите год рождения невесты: ");
        while (1) {
            err = scanf("%d", &a.birthyear);
            if (err != 1) {
                printf("Неправильный год рождения. Попробуйте еще раз\n");
            }
            else {
                fwrite(a.birthyear, sizeof(int), 1, fin);
                break;
            }
        }
        printf("Введите адрес невесты: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных адресов. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.adress, t);
                    fwrite(a.adress, sizeof(char), 20, fin);
                    break;
                }
            }
        }
        printf("Введите телефон невесты: ");
        while (1) {
            scanf("%c", &c);
            if (c != '\n') {
                t[n] = c;
                n++;
                t[n] = '\0';
                t = realloc(t, n + 1);
            }
            else {
                t[n] = '\0';
                if (n > 20) {
                    printf("Не существует таких длинных номеров телефона. Попробуйте еще раз\n");
                    n = 0;
                }
                else {
                    n = 0;
                    strcpy(a.telephone, t);
                    fwrite(a.telephone, sizeof(char), 20, fin);
                    break;
                }
            }
        }
    }
    fclose(fin);
    free(t);
}
