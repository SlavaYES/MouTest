/*
Проблемы с вводом данных
После выполнения fputs или printf, fgets ведет себя не понятно,
Вместо того чтобы получить с клавиатуры данные, он их откуда-то получает, и заканчивает ввод данных.
(Догадываюсь, что из предыдущей строки видит символ конца строки)
getchar работает точно так же, не дает мне ввести данные
Писал отделную программу для ввода, как в основной -> всё работает нормально
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "add_tem.h"

#ifdef _WIN32
#include <conio.h>
#else
#include "conios.h"
#endif

typedef struct Record {
    char quest[50];
    char answer[150];
    int num[10];
} Record;

void set_theme(void)
{
    FILE *file;

    int flag, i, j, num[1];
    char name_file[11], full_name[30];
    char name_theme[100], suffix[5];
    char the_s[4], que_s[4], ans_s[4], try_s[4];
    /*Symboles*/
    strcpy(the_s, "##\n");
    strcpy(que_s, "#?\n");
    strcpy(ans_s, "#!\n");
    strcpy(try_s, "#^\n");
    strcpy(full_name, "txt/");
    strcpy(suffix, ".txt");
    /*Name file*/
    flag=0;
    do {
	clrscr();
	if (flag) perror("Ошибка ввода данных...\n");
	fputs("Введите Имя Файла[10]:\n", stdout);
	scanf("%s", name_file);
	flag=1;
    } while (strlen(name_file) > 10);
    strcat(full_name, name_file);
    strcat(full_name, suffix);
    file = fopen(full_name, "wb");
    if (!file) {
	perror("Ошибка открытия файла\n");
	return;
    }
    /*Theme*/
    flag=0;
    do {
	clrscr();
	if (flag) perror("Ошибка ввода данных...\n");
	fputs("Введите Тему Теста[20]:\n", stdout);
	fgets(name_theme, 100, stdin);
	flag=1;
    } while (strlen(name_theme) > 20);
    fwrite(the_s, 1, 2, file);
    fwrite(name_theme, 1, strlen(name_theme), file);
    fwrite(the_s, 1, 3, file);
    /*QUESTION*/
    Record record;
    char exit;
    exit='n';
    j=1;
    while (exit!='y') {
	/*Question*/
	flag=0;
	do {
	    //clrscr();
	    if (flag) perror("Ошибка ввода данных...\n");
	    printf("Введите (%d) Вопрос[100]:\n", j);
	    fgets(record.quest, 150, stdin);
	    flag=1;
	} while (strlen(record.quest) > 100);
	num[0]=j;
	fwrite(que_s, 1, 2, file);
	fwrite(num, 4, 1, file);
	fwrite(record.quest, 1, strlen(record.quest), file);
	fwrite(que_s, 1, 3, file);
	j++;
	/*QUESTION*/
	/*ANSWER*/
	i=1;
	fwrite(ans_s, 1, 2, file);
	exit='n';
	while (exit!='y') {
	    flag=0;
	    do {
		//clrscr();
		if (flag) perror("Ошибка ввода данных...\n");
		printf("Введите (%d) ответ[10]:\n", i);
		fgets(record.answer, 50, stdin);
		flag=1;
	    } while (strlen(record.answer) > 10);
	    num[0]=i;
	    fwrite(num, 4, 1, file);
	    fputs(")", file);
	    fwrite(record.answer, 1, strlen(record.answer), file);
	    fputs(". ", file);
	    i++;
	    fputs("Закончить ввод ответов?[y]...\n", stdout);
	    exit=getchar();
	}
	fwrite(ans_s, 1, 3, file);
	
	/*ANSWER*/
	/*TRY NUM*/
	fputs("Введите правильный(ые) номер(а) ответа(ов):\n", stdout);
	i=1;
	fwrite(try_s, 1, 2, file);
	exit='n';
	while (exit != 'y') {
	    fputs("Ответ: ", stdout);
	    scanf("%d", record.num+i);
	    i++;
	    fputs("Закончить ввод?[y]...\n", stdout);
	    exit=getchar();
	}
	fwrite(record.num, sizeof(int), i, file);
	fwrite(try_s, 1, 3, file);
	/*TRY NUM*/
	printf("Закончить ввод вопросов?[y]...\n");
	exit=getchar();
    }
    /*IN WORKING*/
    fclose(file);
    /*QUESTION*/
}



