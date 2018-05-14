#include "setAnswer.h"
#include <string.h>
#include <stdio_ext.h>
int setAnswer(FILE *file)
{
    int j=0;
    char enter_o='u', answer[128], buffer[10], sk[3]=") ";
    do {//ENTER ANSWER
	j++;
        printf("Enter (%d) the Answer:\n\t", j);
        __fpurge(stdin);
        fgets(answer, 128, stdin);
        sprintf(buffer, "%d", j);
        fwrite(buffer, 1, 1, file);
        fwrite(sk, 1, 2, file);
        fwrite(answer, 1, strlen(answer), file);
        printf("\nQuit the Answer?[y]: ");
	scanf("%c", &enter_o);
    } while (enter_o != 'y');
    return j;
}
