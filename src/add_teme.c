#include <iostream>//win
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>//win
#include "add_tem.h"

using namespace std;//win

int set_theme(void)
{

    FILE *file;
    char nameFile[32], nameFileFull[64], nameTheme[32];
    //INIT SYMBOL
    char vop_s='$', otv_s='!', try_s='^', end_s='#', ent_s=10;
    /*NAME FILE*/
    strcpy(nameFileFull, "txt/");
    system("CLS");
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
	cin.ignore();//win
    fgets(nameTheme, 32, stdin);
    fwrite(nameTheme, 1, strlen(nameTheme), file);
    /*THEME*/
    char enter_v, enter_o, enter_t;
    char quest[128], answer[32], trues[16];
    int i, j, k;
    char buffer[10], sk=')', t[4]=". ";
    i=1;
    do {//ENTER QUESTION
		printf("\nEnter (%d) the Question:\n\t", i);
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
		    printf("\nEnter (%d) the Answer:\n\t", j);
		    fgets(answer, 128, stdin);
		    sprintf(buffer, "%d", j);
		    fwrite(buffer, 1, 1, file);
		    fwrite(&sk, 1, 1, file);
		    fwrite(answer, 1, strlen(answer), file);
		    j++;
		    printf("\nQuit the Answer?[y]: ");
		    enter_o=getch();
		} while (enter_o != 'y');
		fwrite(&try_s, 1, 1, file);
		
		k=1;
		do {//ENTER trues ANSWER
		    printf("\nEnter (%d) the NUM trues Answer:\n\t", k);
		    fgets(trues, 16, stdin);
		    fwrite(trues, 1, 1, file);
		    k++;
		    printf("\nQuit the trues Answer?[y]: ");
		    enter_t=getch();
		} while (enter_t != 'y');
		fwrite(&try_s, 1, 1, file);
		fwrite(&end_s, 1, 1, file);
		fwrite(&ent_s, 1, 1, file);
		fwrite(&ent_s, 1, 1, file);
		
		printf("\nQuit the Questuion?[y]: ");
		enter_v=getch();
		fflush(file);
    } while (enter_v != 'y');
    fclose(file);
    /*FILE*/
    /*VIEW FILE*/
    char p;
    int try_mas[16];
    char str[128];
    file=fopen(nameFileFull, "rb");
    if (!file) {
		fputs("ERROR\n", stdout);
    }		
    while (fread(&p, 1, 1, file)) {
    	if (p == '!' || p == '$' || p == '#');
    		else {
    			if (p == '^') {
    				i=0;
    				fread(&p, 1, 1, file);
    				while (p != '^') {
						try_mas[i]=atoi(&p);
						fread(&p, 1, 1, file);
						i++;
					}
					fread(&p, 1, 1, file);
				}
				printf("%c", p);
			}
	}
	
    getchar();
    fclose(file);
    return 0;
}



































