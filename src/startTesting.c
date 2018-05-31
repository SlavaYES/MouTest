#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

extern int ANSWER_QUANTITY;

int checkCorrect(char *testName)
{
    FILE *file;
    char cPtr;
    int symbol1=0, symbol2=0, symbol3=0, symbol4=0;
    file=fopen(testName, "rb");
    
    while(fread(&cPtr, 1, 1, file))
    {
	if(cPtr == '!') {
	    symbol1++;
	}
	if(cPtr == '#') {
	    symbol2++;
	}
	if(cPtr == '^') {
	    symbol3++;
	}
	if(cPtr == '$'){
	    symbol4++;
	}
    }
    if(symbol1>=1 && symbol2>=1 && symbol3>=1 && symbol4>=1) {
	return 0;
    }
    else {
	 return 1;
    }
    fclose(file);
}

void askName(char *nameAndFamily)
{
    system("clear");
    printf("Введите Имя и Фамилию: ");
    __fpurge(stdin);
    fgets(nameAndFamily, 128, stdin);
    system("clear");
}

int recordResult(int *answerMass, int *result)
{
    static int resultNumber = 0, quantityPoints = 0;
    int userAnswer[ANSWER_QUANTITY];
    int i;
 
    for (i = 0; i < ANSWER_QUANTITY; i++) {
        userAnswer[i]=0;
    }

    int quantityRightAnswer = 0;

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (answerMass[i] != 0) {
            quantityRightAnswer += 1;
        } else break;
    }

    i = 0;
    do {
        printf("\nВведите номер %d-ого ответа:", i + 1);
        //cin >> userAnswer[i++];
        scanf("%d", userAnswer + i++);
        quantityRightAnswer--;
    } while (quantityRightAnswer != 0);

    int j = 0;
    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (answerMass[i] == 0) {
            break;
        }
        quantityPoints++;
        for (j = 0; j < ANSWER_QUANTITY; j++) {
            if(answerMass[i] == userAnswer[j]) {
                result[resultNumber++] = 1;
                break;
            }
        }
    }

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        answerMass[i] = 0;
    }

    return quantityPoints;
}

int  startTesting(char *testName)
{
    FILE *file;
    char cPtr; //str[128];
    char nameAndFamily[128];
    int answerMass[ANSWER_QUANTITY], result[ANSWER_QUANTITY];
    int quantityPoints = 0;
    int i, errorStatus=0;

    for (i = 0; i < ANSWER_QUANTITY; i++) {
        result[i] = 0;
        answerMass[i] = 0;
    }

    if (!(file = fopen(testName, "rb"))) {
        fputs("ERROR\n", stdout);
    }
    errorStatus=checkCorrect(testName);
    if (errorStatus == 1) {
	printf("ошибка"); 
	return 1;
    }

    askName(nameAndFamily);

    fputs("Прохождение теста\n", stdout);

    while (fread(&cPtr, 1, 1, file)) {

        if (cPtr == '!' || cPtr == '$' || cPtr == '#') {
            printf("\n");
        } else {
            if (cPtr == '^') {
                i = -1;
                fread(&cPtr, 1, 1, file);
                while(cPtr != '#') {
                    i++;
                    cPtr -=10;
                    answerMass[i] = atoi(&cPtr);
                    fread(&cPtr, 1, 1, file);
                }
            }
            //fread(&fPtr, 1, 1, file);
            if (cPtr != '#') {
                printf("%c", cPtr);
            } else {
                 quantityPoints=recordResult(answerMass, result);
            }
        }
    }
    int summ = 0;
    for (i = 0; i < ANSWER_QUANTITY; i++) {
        if (result[i] != 0) {
            summ += result[i];
        }
    }
    float pers = ((float)summ/quantityPoints)*100;
    printf("Ваш результат: ");
    printf("%sБаллы: %3d из %-3d -> %-.2f%%\n", nameAndFamily, summ, quantityPoints, pers);
    getchar();

    fclose(file);
    char p = ' ', ps = 0x0a, ch[10], name[256];
    
    for (i = 0; i <= (strlen(testName)-5); i++) {
        name[i] = testName[i];
    }
    name[strlen(testName)-4]='\0';
    strcat(name, "_result.txt");
    
    sprintf(ch, "%5.2f", pers);
    if (!(file=fopen(name, "rb"))) {
        file=fopen(name, "wb");
    }
    
    fwrite(nameAndFamily, 1, strlen(nameAndFamily)-1, file);
    fwrite(&p, 1, 1, file);
    fwrite(ch, 1, strlen(ch), file);
    fwrite(&ps, 1, 1, file);
    
    fclose(file);
    return 0;
}
