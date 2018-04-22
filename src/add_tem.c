#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "add_tem.h"
#include "conios.h"
#define new_memory (Otvet *)malloc(sizeof(Otvet));

typedef struct {
    char question[50];
    char answer[100];
    char num[10];
} Full_fild;

typedef struct Otvet {
    struct Otvet *next;
    char data[16];
} Otvet;
/*
typedef struct Quest{
    struct Quest *next;
    char quest[128];
} Quest;
*/
void setTem(void)
{
    /*TEM*/

    char full_name[30];
    char name_tem[100];
    char syfix[5];

    strcpy(full_name, "txt/");
    strcpy(syfix, ".txt");

    clrscr();
    printf("Введите Тему Теста:\n"); fgets(name_tem, 100, stdin);
    while (strlen(name_tem)>20) {
	clrscr();
	printf("\x1b[31mОшибка ввода данных,\n");
	printf("Вы превысили лимит символов [20]\n");
	printf("Попробуйте еще раз...\x1b[0m\n");
	printf("Введите Тему Теста:\n"); fgets(name_tem, 100, stdin);
    }
    clrscr();
    strcat(full_name, name_tem);
    memmove(full_name+strlen(full_name)-1, syfix, strlen(full_name)+strlen(syfix));
    /*TEM*/
    /*QUESTION*/
    //Quest *head_q, *tail_q, *point_q;
    //char exit, question[512];
    //int k;
    
    /*QUESTION*/
    /*IN WORKING*/
    Otvet *head_a, *tail_a, *point_a;
    char exit, answer[128];
    int i=1;
    head_a=new_memory;
    head_a->next=NULL;
    tail_a=(Otvet *)&head_a;

    while (exit!='y') {
	printf("Введите (%d) ответ\t", i);
	fgets(answer, 50, stdin);
	if (strlen(answer)<20) {
	    point_a=new_memory;
	    strcpy(point_a->data, answer);
	    tail_a->next=point_a;
	    tail_a=point_a;
	    i++;
	    printf("Закончить ввод ответов?(y/n):\n");
	    exit=getch();
	} else {
	    printf("\x1b[31mОшибка ввода данных,\n");
	    printf("Ответ не может содержать более 20 символов\n");
	    printf("Попробуйте еще раз...\x1b[0m\n");
	}
    }
    point_a=head_a;
    while (point_a) {
	printf("%s", point_a->data);
	point_a=point_a->next;
    }
    while (head_a) {
	point_a=head_a;
	head_a=point_a->next;
	free(point_a);
    }
    /*IN WORKING*/
}


