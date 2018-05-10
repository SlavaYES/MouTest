#include "setTryAnswer.h"
#include <stdio.h>
#include <stdio_ext.h>

int setTryAnswer(FILE *file)
{
    char enter_t, try[16];
    int k=1;
    do {//ENTER TRY ANSWER
        printf("Enter (%d) the NUM Try Answer:\n\t", k);
        __fpurge(stdin);
        fgets(try, 16, stdin);
        fwrite(try, 1, 1, file);
        k++;
        printf("\nQuit the Try Answer?[y]: ");
        scanf("%c", &enter_t);
    } while (enter_t != 'y');
    return 1;
}