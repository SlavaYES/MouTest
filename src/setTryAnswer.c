#include "setTryAnswer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int setTryAnswer(FILE *file, int n)
{
    char enter_t, try[10], num;
    int k=1, i, flag;
    num=n+'0';
    do {//ENTER TRY ANSWER
        printf("Enter (%d) the NUM Try Answer:\n\t", k);
        __fpurge(stdin);
        try[k]=getchar();
        if (try[k] >= '1' && try[k] <= '9' && try[k] <= num) {
    	    flag=1;
    	    for (i=k-1; i>0; i--) {
    		if (try[k] == try[i]) {
    		    flag=0;
    		}
    	    }
    	    if (flag) {
    		fwrite(try+k, 1, 1, file);
    		k++;
    		printf("\nQuit the Try Answer?[y]: ");
    		__fpurge(stdin);
    		scanf("%c", &enter_t);
    	    } else {
    		printf("\x1b[31mError input\x1b[0m\n");
    	    }
    	} else {
    	    printf("\x1b[31mError input\x1b[0m\n");
    	}
    } while (enter_t != 'y');
    return 1;
}