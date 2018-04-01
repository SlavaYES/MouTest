#Makefile
#Сборка проекта
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
FLAGS=-Wall -o
#SOURCES Исходники
SOURCES=main.c conios.c

all: main.c conios.c
	$(CC) $(FLAGS) main $(SOURCES)