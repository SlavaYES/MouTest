#include <stdio.h>
#include <stdlib.h>
#include "conios.h"


int main()
{
    int i;
    char ch;
    int x=100, y=20;
    gotoxy(100, 21);
    printf("\x1b[1;36mПройти тест\x1b[0m");
    gotoxy(100, 22);
    printf("Создать");
    gotoxy(100, 23);
    printf("Помощь");
    gotoxy(100, 24);
    printf("Выйти");
    i=1;
    gotoxy(x+11, y+i);
    while (ch!='e') {
	clrscr();
	ch=getch();
	gotoxy(x, y+1);
	printf("\x1b[0mПройти тест");
	gotoxy(x, y+2);
	printf("Создать");
	gotoxy(x, y+3);
	printf("Помощь");
	gotoxy(x, y+4);
	printf("Выйти");
	if (ch==119) i--;
	if (ch==115) i++;
	if (i<1) i=4;
	if (i>4) i=1;
	gotoxy(x, y+i);
	switch (i) {
	case 1: printf("\x1b[1;36mПройти тест\x1b[0m"); break;
	case 2: printf("\x1b[1;36mСоздать\x1b[0m"); break;
	case 3: printf("\x1b[1;36mПомощь\x1b[0m"); break;
	case 4: printf("\x1b[1;36mВыйти\x1b[0m"); break;
	}
    }
    gotoxy(0, 25);
    return 0;
}