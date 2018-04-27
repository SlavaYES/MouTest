#include <stdio.h>
#include <stdlib.h>
#include "add_tem.h"

int main()
{
    char enter;
    while (enter != '4') {
	system("clear");
	printf("\n\t  Menu\n\n");
	printf("\t1. Creat\n");
	printf("\t2. Pass\n");
	printf("\t3. Help\n");
	printf("\t4. Quit\n");
	printf("\nEnter number:\n\t\t"); 
	enter=getchar();
	switch (enter)
	{
	case '1':
	    set_theme();
	    break;
	case '2':
	    break;
	case '3':
	    break;
	case '4':
	    return 0;
	    break;
	}
    }
    return 0;
}

































