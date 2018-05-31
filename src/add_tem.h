#include <stdio.h>

int setFile(char *); //открытие теста для создания

int setTest(char *); //заполнение теста

int setQuest(char *, int, FILE *); //ввод вопроса

int setTheme(char *, char *, char *); //ввод темы

int setAnswer(char *, int, FILE *); //ввод ответа

int setTryAnswer(char *, int *, int, FILE *); //ввод номера правильного ответа