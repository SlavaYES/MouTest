#Makefile
#watching Убери conios.h совсем без замены на conio.h
#Сборка проекта
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror

src=src/
build=build/

SOURCES=main.c add_tem.c
OBJECTS=$(addprefix $(build), main.o add_tem.o)
EXE=main

.PHONY: all clean

all: build txt $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)add_tem.o: $(src)add_tem.c $(src)add_tem.h
	$(CC) $(CFLAGS) -c $(src)add_tem.c -o $@

build:
	mkdir build
src:
	mkdir src
txt:
	mkdir txt

clean:
	-rm -rf build txt

