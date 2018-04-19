#include <stdio.h>
#include <stdlib.h>
#include "conios.h"
#include "add_tem.h"
#define x 100
#define y 20
#define xh 70
#define yh 20

int main()
{
    int i;
    char enter;
    
    /*CREAT ADDTEST*/
    FILE *file=fopen("txt/Init_file.txt", "w");
    fclose(file);
    setTem(file);
    return 0;
    /*CREAT ADDTEST*/
    
    /*HELP*/
    gotoxy(xh, yh+1);
    printf("Вверх:   'W'");
    gotoxy(xh, yh+2);
    printf("Вниз:    'S'");
    gotoxy(xh, yh+3);
    printf("Выбрать: 'E'");
    /*MENU*/
    gotoxy(x, y+1);
    printf("\x1b[1;36m");
    printf("Создать тест");
    printf("\x1b[0m");
    gotoxy(x, y+2);
    printf("Пройти  тест");
    gotoxy(x, y+3);
    printf("Помощь");
    gotoxy(x, y+4);
    printf("Выйти");

    i=1;
    gotoxy(x+11, y+i);
    while (enter!='e') {
	clrscr();
	enter=getch();
	/*HELP*/
	gotoxy(xh, yh+1);
	printf("Вверх:   'W'");
	gotoxy(xh, yh+2);
	printf("Вниз:    'S'");
	gotoxy(xh, yh+3);
	printf("Выбрать: 'E'");
	/*MENU*/
	gotoxy(x, y+1);
	printf("Создать тест");
	gotoxy(x, y+2);
	printf("Пройти  тест");
	gotoxy(x, y+3);
	printf("Помощь");
	gotoxy(x, y+4);
	printf("Выйти");
	/*CHECK*/
	if (enter==119) i--;
	if (enter==115) i++;
	if (i<1) i=4;
	if (i>4) i=1;
	/*SWITCH POINTER*/
	gotoxy(x, y+i);
	printf("\x1b[1;36m");
	switch (i) {
	case 1: printf("Создать тест"); break;
	case 2: printf("Пройти  тест"); break;
	case 3: printf("Помощь"); break;
	case 4: printf("Выйти"); break;
	}
	printf("\x1b[0m");
    }
    /*SWITCH ITEM*/
    gotoxy(0, 25);
    switch (i) {
    case 1:
	break; //CREAT
    case 2:
	break; //PASS
    case 3:
	break; //HELP
    case 4:
	return 0; //EXIT
    }
}










































