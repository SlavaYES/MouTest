#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "conios.h"
#include "add_tem.h"

#include <string.h>
#include "checkfile.h"
#include "displaylist.h"
#include "select.h"

#define x 100
#define y 20
#define xh 70
#define yh 20

int main()
{
    int i;
    char enter;

    FILE *file;
    file = fopen("", "");
    char nameFile[256], nameTheme[256];

    /*CREAT ADDTEST*/
while(1){
    /*HELP*/

    //Помощь

    gotoxy(xh, yh+1);
    printf("Вверх:   'W'");
    gotoxy(xh, yh+2);
    printf("Вниз:    'S'");
    gotoxy(xh, yh+3);
    printf("Выбрать: 'E'");

    //Меню
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
enter=' ';
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

    //Выбор пункта
    printf("\n");
    gotoxy(0, 0);
    switch (i) {
    case 1:

	system("clear");
	fputs("Введите Имя файла: ", stdout);
	scanf("%s", nameFile);
	setFile(nameFile, file);
	
	fputs("Введите Тему: ", stdout);
	__fpurge(stdin);
	fgets(nameTheme, 256, stdin);
        
        setTheme(nameTheme, nameFile);
        
        setTest(nameFile, file);
        break; //Создание
    case 2:

    system("clear");
    FILE *f4;
    char tema[256],a[256];
    int choice=0;
    strcpy(a,"../Tests/Tests.txt");
    if(Checkfile(a)==1) {
    printf("\nФайл не существует или изначально был пуст,");
    printf(" пройдите в пункт меню для создания теста.\n");
    printf("Для выхода в меню нажмите любую клавишу...\n");
    getch();
    break;}
    printf("Доступные для прохождения теста, темы:\n");
    if(Displaylist(a)==1){
    printf("\nФайл стал пуст в ходе отсеивания не существующих тем,");
    printf(" пройдите в пункт меню для создания теста.\n");
    printf("Для выхода в меню нажмите любую клавишу...\n");
    getch();
    break;
    }
    
    while(!choice){
	printf("Введите номер темы для выбора - ");
	scanf("%d",&choice);
	if(Select(a,tema,choice)==1) {printf("\nВы вышли за границу\n");choice=0;}
	else {break;}
    }
    
    puts(tema);
    f4=fopen(tema,"r");
        if(f4){
        printf("Существует\n");}else printf("Ошибочка с файлом\n");
        fclose(f4);
        getch();
        getch();
	break; //PASS

    case 3:
        break; //Помощь
    case 4:
        return 0; //Выход
    }
    }
}
































