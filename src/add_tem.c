#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>//watching не надо в винда
#include "add_tem.h"
#include "conios.h"//watching <conio.h>

typedef struct Record {
    char quest[50];
    char answer[150];
    int num[10];
} Record;

void set_theme(void)
{
    /*THEME*/
    FILE *file;
    int flag, i, num[1];
    char name_file[11], full_name[20];
    char name_theme[100], suffix[5];
    char the_s[4], que_s[4], ans_s[4], try_s[4];
    strcpy(the_s, "##\n");
    strcpy(que_s, "#?\n");
    strcpy(ans_s, "#!\n");
    strcpy(try_s, "#^\n");
    strcpy(full_name, "txt/");
    strcpy(suffix, ".txt");
    flag=0;
    do {
	clrscr();
	if (flag) printf("Ошибка ввода данных...\n");
	printf("Введите Имя Файла[10]:\n");
	scanf("%s", name_file);
	flag=1;
    } while (strlen(name_file) > 10);
    
    strcat(full_name, name_file);
    strcat(full_name, suffix);
    
    file = fopen(full_name, "wb");
    if (file == 0) {
	printf("Ошибка открытия файла\n");
	return;
    }
    flag=0;
    do {
	clrscr();
	if (flag) printf("Ошибка ввода данных...\n");
	printf("Введите Тему Теста[20]:\n");
	scanf("%s", name_theme);
	flag=1;
    } while (strlen(name_theme) > 20);
    fwrite(the_s, 1, 2, file);
    fwrite(name_theme, 1, strlen(name_theme), file);
    fwrite(the_s, 1, 3, file);
    /*THEME*/
    /*QUESTION*/
    
    /*IN WORKING*/
    Record record;
    char exit;
    exit='n';
    while (exit!='y') {
	/*QUESTION*/
	flag=0;
	do {
	    clrscr();
	    if (flag) printf("Ошибка ввода данных...\n");
	    printf("Введите Вопрос[100]:\n");
	    scanf("%s", record.quest);
	    flag=1;
	} while (strlen(record.quest) > 100);
	fwrite(que_s, 1, 2, file);
	fwrite(record.quest, 1, strlen(record.quest), file);
	fwrite(que_s, 1, 3, file);
	/*QUESTION*/
	/*ANSWER*/
	i=1;
	fwrite(ans_s, 1, 2, file);
	while (exit!='y') {
	    flag=0;
	    do {
		clrscr();
		if (flag) printf("Ошибка ввода данных...\n");
		printf("Введите (%d) ответ[10]:\n", i);
		scanf("%s", record.answer);
		flag=1;
	    } while (strlen(record.answer) > 10);
	    num[0]=i;
	    fwrite(num, 4, 1, file);
	    fputs(")", file);
	    fwrite(record.answer, 1, strlen(record.answer), file);
	    fputs(". ", file);
	    i++;
	    printf("Закончить ввод ответов?[y]...\n");
	    getch();
	    exit=getch();
	}
	fwrite(ans_s, 1, 3, file);
	/*ANSWER*/
	/*TRY NUM*/
	printf("Введите правильный(ые) номер(а) ответа(ов):\n");
	i=1;
	fwrite(try_s, 1, 2, file);
	exit='n';
	while (exit != 'y') {
	    printf("Ответ: ");
	    scanf("%d", record.num+i);
	    i++;
	    printf("Закончить ввод?[y]...\n");
	    getch();
	    exit=getch();
	}
	fwrite(record.num, sizeof(int), i, file);
	fwrite(try_s, 1, 3, file);
	/*TRY NUM*/
	printf("Закончить ввод вопросов?[y]...\n");
	exit=getch();
    }
    /*IN WORKING*/
    fclose(file);
    /*QUESTION*/
}



