#define _OPEN_SYS_ITOA_EXT
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_tem.h"
#include "setAnswer.h"
#include "setTryAnswer.h"

int set_theme(void)
{
    FILE *file, *file_theme;
    char p;//Obhod
    char nameFile[32], nameFileFull[64], nameTheme[32];
    //INIT SYMBOL
    char vop_s='$', otv_s='!', try_s='^', end_s='#', end_len='\n', pro_s=' ';
    /*NAME FILE read*/
    strcpy(nameFileFull, "txt/");
    system("clear");
    fputs("Enter the name file: ", stdout);
    scanf("%s", nameFile);
    strcat(nameFileFull, nameFile);
    strcat(nameFileFull, ".txt");
    /*NAME FILE open*/
    /*FILE*/
    file=fopen(nameFileFull, "wb");
    if (!file) {
	fputs("ERROR\n", stdout);
    }
    /*THEME read*/
    fputs("Enter Test Theme: ", stdout);
    __fpurge(stdin);
    fgets(nameTheme, 32, stdin);

    file_theme=fopen("Theme/Themes.txt", "ab");
    if (!file_theme) {
	fputs("ERROR\n", stdout);
    }
    fwrite(nameTheme, 1, strlen(nameTheme)-1, file_theme);
    fwrite(&pro_s, 1, 1, file_theme);
    fwrite(nameFileFull, 1, strlen(nameFileFull), file_theme);
    fwrite(&end_len, 1, 1, file_theme);
    fclose(file_theme);
    /*THEME read and write*/
    char enter_v='u';
    char quest[128];
    int i, n;
    char buffer[10], t[4]=". ";
    i=1;
    do {//ENTER QUESTION
	system("clear");
	printf("Enter (%d) the Question:\n\t", i);
	__fpurge(stdin);
	fgets(quest, 128, stdin);
	fwrite(&vop_s, 1, 1, file);
	sprintf(buffer, "%d", i);
	fwrite(buffer, 1, 1, file);
	fwrite(t, 1, 2, file);
	fwrite(quest, 1, strlen(quest), file);
	
	fwrite(&otv_s, 1, 1, file);
	n=setAnswer(file);
	
	fwrite(&try_s, 1, 1, file);
	setTryAnswer(file, n);
	fwrite(&end_s, 1, 1, file);
	fwrite(&end_len, 1, 1, file);
	
	printf("\nQuit the Questuion?[y]: ");
	__fpurge(stdin);
	scanf("%c", &enter_v);
	fflush(file);
	i++;
    } while (enter_v != 'y');
    fclose(file);
    /*FILE*/
    /*VIEW FILE read*/
    file=fopen(nameFileFull, "rb");
    if (!file) {
	fputs("ERROR\n", stdout);
    }
    while (fread(&p, 1, 1, file)) {
	printf("%c", p);
    }
    __fpurge(stdin);
    getchar();
    fclose(file);
    return 0;
}
