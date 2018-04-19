#include "add_tem.h"
#include "conios.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char question[50];
    char answer[100];
    char num[10];
} Quest;


void setTem(FILE *file)
{
    /*TEM*/
    Quest quest;

    char full_name[30];
    char name_tem[100];
    char syfix[5];

    strcpy(full_name, "txt/");
    strcpy(syfix, ".txt");

    clrscr();
    printf("Введите Тему Теста:\n"); fgets(name_tem, 100, stdin);
    while (strlen(name_tem)>20) {
	clrscr();
	printf("\x1b[31mОшибка ввода данных,\nВы превысили лимит символов [20]\nПопробуйте еще раз...\x1b[0m\n");
	printf("Введите Тему Теста:\n"); fgets(name_tem, 100, stdin);
    }
    clrscr();
    strcat(full_name, name_tem);
    memmove(full_name+strlen(full_name)-1, syfix, strlen(full_name)+strlen(syfix));
    printf("%s\n", full_name);
    printf("%s\n", name_tem);
    printf("%s\n", syfix);
    //Вывод для проверки корректности 
    /*TEM*/
    /*NO WORKING*/
    file=fopen(full_name, "wt");
    printf("\nВведите вопросы\n");
    printf("\nВопрос:\n\t"); scanf("%s", quest.question);
    printf("\nОтвет 1: "); scanf("%s", quest.answer);
    printf("\nНомер правильного\nОтвета: "); scanf("%c", quest.num);
    fwrite(&quest, sizeof(quest), 1, file);
    /*NO WORKING*/
    fclose(file);
    getch();
}


