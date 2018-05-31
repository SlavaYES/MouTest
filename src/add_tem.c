#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_tem.h"

#define _OPEN_SYS_ITOA_EXT
#define KEY 10
#define NUM 9

int setFile(char *nameFile, FILE *file)
{
    if (!(file = fopen(nameFile, "wb"))) {
        return 1;
    }

    return 0;
}

int setTheme(char *nameTheme, char *nameFile)
{
    FILE *file;
    char pro_s = '&', end_len = '\n';

    if (!(file = fopen("../Tests/Tests.txt", "ab"))) {
        return 1;
    }

    fwrite(nameTheme, 1, strlen(nameTheme)-1, file);
    fwrite(&pro_s, 1, 1, file);
    fwrite(nameFile, 1, strlen(nameFile), file);
    fwrite(&end_len, 1, 1, file);

    fclose(file);

    return 0;
}

int setTest(char *nameFile, FILE *file)
{
    char vop_s = '$',  otv_s = '!';
    char enter_v = 'u', enter_o = 'u', t[4]=". ";
    char quest[128], buffer[10];
    int i = 1, j, n;

    if (!(file = fopen(nameFile, "ab"))) {
        return 1;
    }

    do {// Ввод вопросов ответов и правильных

        system("clear");
        printf("Введите %d-ый вопрос: ", i);
        __fpurge(stdin);
        fgets(quest, 128, stdin);

        fwrite(&vop_s, 1, 1, file);
        sprintf(buffer, "%d", i);
        fwrite(buffer, 1, 1, file);
        fwrite(t, 1, 2, file);
        fwrite(quest, 1, strlen(quest), file);

        j = 0;
        fwrite(&otv_s, 1, 1, file);
        do {// Ввод ответов

            j++;
            if (setAnswer(j, file)) {
                printf("Ошибка!\n");
            }
            printf("\nЗакончить ввод ответов?[y]: ");
            scanf("%c", &enter_o);

        } while (enter_o != 'y' && j < NUM);
        n = j;

        setTryAnswer(n, file);

        printf("\nЗакончить ввод вопросов?[y]: ");
        __fpurge(stdin);
        scanf("%c", &enter_v);

        fflush(file);
        i++;

    } while (enter_v != 'y');

    fclose(file);
    printf("Для продолжения нажмите Enter...");
    __fpurge(stdin);
    getchar();

    return 0;
}

int setAnswer(int j, FILE *file)
{
    char answer[128], buffer[10];
    char sk[3]=") ";

    printf("Введите %d-ый ответ: ", j);
    __fpurge(stdin);
    fgets(answer, 128, stdin);

    sprintf(buffer, "%d", j);

    fwrite(buffer, 1, 1, file);
    fwrite(sk, 1, 2, file);
    fwrite(answer, 1, strlen(answer), file);

    return 0;
}

int setTryAnswer(int n, FILE *file)
{
    char quit, try[12];
    char num = n + '0';
    char try_s = '^', end_s = '#', end_len = '\n';
    int k = 1, flag;

    try[0]='0'+KEY;
    fwrite(&try_s, 1, 1, file);
    do {//Ввод правильных ответов

        printf("Введите %d-ый правильный номер ответа: ", k);
        __fpurge(stdin);
        try[k]=getchar();

        if (try[k] >= '1' && try[k] <= '9' && try[k] <= num) {

            try[k]+=KEY;
            flag = 1;
            for (int i = 0; i < k; i++) {
                if (try[k] == try[i]) {
                    flag=0;
                }
            }

            if (flag) {

                fwrite(try+k, 1, 1, file);
                k++;
                printf("\nЗакончить ввод правильных номеров?[y]: ");
                __fpurge(stdin);
                scanf("%c", &quit);

            } else printf("\x1b[31mОшибка ввода\x1b[0m\n");
        } else printf("\x1b[31mОшибка ввода\x1b[0m\n");

    } while (quit != 'y' && k < 10 && k <= n);

    fwrite(&end_s, 1, 1, file);
    fwrite(&end_len, 1, 1, file);

    return 1;
}
