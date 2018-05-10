#define _OPEN_SYS_ITOA_EXT
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_tem.h"

int set_theme(void)
{
    FILE *file, *file_theme;
    char nameFile[32], nameFileFull[64], nameTheme[32];
    //INIT SYMBOL
    char vop_s='$', otv_s='!', try_s='^', end_s='#', end_len='\n';
    /*NAME FILE*/
    strcpy(nameFileFull, "txt/");
    system("clear");
    fputs("Enter the name file: ", stdout);
    scanf("%s", nameFile);
    strcat(nameFileFull, nameFile);
    strcat(nameFileFull, ".txt");
    /*NAME FILE*/
    /*FILE*/
    file=fopen(nameFileFull, "wb");
    if (!file) {
	fputs("ERROR\n", stdout);
    }
    file_theme=fopen("Theme/Themes.txt", "ab");
    fwrite(nameFile, 1, strlen(nameFile), file_theme);
    fwrite(&end_len, 1, 1, file_theme);
    fclose(file_theme);
    
    /*VIEW FILE*/
    char p;
    file_theme=fopen("Theme/Themes.txt", "rb");
    if (!file_theme) {
	fputs("ERROR\n", stdout);
    }
    while (fread(&p, 1, 1, file_theme)) {
	printf("%c", p);
    }
    fclose(file_theme);
    /*THEME*/
    fputs("Enter Test Theme: ", stdout);
    __fpurge(stdin);
    fgets(nameTheme, 32, stdin);
    fwrite(nameTheme, 1, strlen(nameTheme), file);
    /*THEME*/
    char enter_v, enter_o, enter_t;
    char quest[128], answer[32], try[16];
    int i, j, k;
    char buffer[10], sk=')', t[4]=". ";
    i=1;
    do {//ENTER QUESTION
	printf("Enter (%d) the Question:\n\t", i);
	__fpurge(stdin);
	fgets(quest, 128, stdin);
	fwrite(&vop_s, 1, 1, file);
	sprintf(buffer, "%d", i);
	fwrite(buffer, 1, 1, file);
	fwrite(t, 1, 2, file);
	fwrite(quest, 1, strlen(quest), file);
	
	i++;
	fwrite(&otv_s, 1, 1, file);
	j=1;
	do {//ENTER ANSWER
	    printf("Enter (%d) the Answer:\n\t", j);
	    __fpurge(stdin);
	    fgets(answer, 128, stdin);
	    sprintf(buffer, "%d", j);
	    fwrite(buffer, 1, 1, file);
	    fwrite(&sk, 1, 1, file);
	    fwrite(answer, 1, strlen(answer), file);
	    j++;
	    printf("\nQuit the Answer?[y]: ");
	    __fpurge(stdin);
	    enter_o=getchar();
	} while (enter_o != 'y');

	fwrite(&try_s, 1, 1, file);
	k=1;
	do {//ENTER TRY ANSWER
	    printf("Enter (%d) the NUM Try Answer:\n\t", k);
	    __fpurge(stdin);
	    fgets(try, 16, stdin);
	    fwrite(try, 1, 1, file);
	    k++;
	    printf("\nQuit the Try Answer?[y]: ");
	    __fpurge(stdin);
	    enter_t=getchar();
	} while (enter_t != 'y');
	fwrite(&end_s, 1, 1, file);
	fwrite(&end_len, 1, 1, file);
	printf("\nQuit the Questuion?[y]: ");
	__fpurge(stdin);
	enter_v=getchar();
	fflush(file);
    } while (enter_v != 'y');
    fclose(file);
    /*FILE*/
    
    /*VIEW FILE*/
    //char p;
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


