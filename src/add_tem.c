#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_tem.h"

int set_theme(void)
{
    FILE *file;
    char nameFile[32], nameFileFull[64], nameTheme[32];
    //INIT SYMBOL
    char the_s[4], vop_s[4], otv_s[4], try_s[4];
    strcpy(the_s, "##\n"); strcpy(vop_s, "#?\n");
    strcpy(otv_s, "#!\n"); strcpy(try_s, "#^\n");
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
    /*THEME*/
    fputs("Enter Test Theme: ", stdout);
    __fpurge(stdin);
    fgets(nameTheme, 32, stdin);
    fwrite(the_s, 1, 2, file);
    fwrite(nameTheme, 1, strlen(nameTheme), file);
    fwrite(the_s, 1, 3, file);
    /*THEME*/
    char enter_v, enter_o, enter_t;
    char quest[128], answer[32];
    int try;
    int i=1, j=1, k=1;
    do {//ENTER QUESTION
	printf("Enter (%d) the Question:\n\t", i);
	__fpurge(stdin);
	fgets(quest, 128, stdin);
	fwrite(vop_s, 1, 2, file);
	fwrite(quest, 1, strlen(quest), file);
	fwrite(vop_s, 1, 3, file);
	i++;
	do {//ENTER ANSWER
	    printf("Enter (%d) the Answer:\n\t", j);
	    __fpurge(stdin);
	    fgets(answer, 128, stdin);
	    fwrite(vop_s, 1, 2, file);
	    fwrite(answer, 1, strlen(answer), file);
	    fwrite(vop_s, 1, 3, file);
	    j++;
	    printf("\nQuit the Answer?[y]: ");
	    __fpurge(stdin);
	    enter_o=getchar();
	} while (enter_o != 'y');
	
	do {//ENTER TRY ANSWER
	    printf("Enter (%d) the NUM Try Answer:\n\t", k);
	    __fpurge(stdin);
	    scanf("%d", &try);
	    fwrite(try_s, 1, 2, file);
	    fwrite(&try, 4, 1, file);
	    fwrite(try_s, 1, 3, file);
	    k++;
	    printf("\nQuit the Try Answer?[y]: ");
	    __fpurge(stdin);
	    enter_t=getchar();
	} while (enter_t != 'y');
	printf("\nQuit the Questuion?[y]: ");
	__fpurge(stdin);
	enter_v=getchar();
	fflush(file);
    } while (enter_v != 'y');
    fclose(file);
    /*FILE*/
    /*VIEW FILE*/
    file=fopen(nameFileFull, "rb");
    if (!file) {
	fputs("ERROR\n", stdout);
    }
    __fpurge(stdin);
    getchar();
    fclose(file);
    return 0;
}


