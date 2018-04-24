#Makefile
#watching Убери conios.h совсем без замены на conio.h
#Сборка проекта
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror
bin=bin/
src=src/
build=build/

SOURCES=main.c conios.c add_tem.c
OBJECTS=$(addprefix $(build), main.o conios.o add_tem.o)
EXE=$(bin)main

.PHONY: all clean

all: bin build txt $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c $(src)conios.h
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)conios.o: $(src)conios.c $(src)conios.h
	$(CC) $(CFLAGS) -c $(src)conios.c -o $@

$(build)add_tem.o: $(src)add_tem.c $(src)add_tem.h
	$(CC) $(CFLAGS) -c $(src)add_tem.c -o $@

build:
	mkdir build
bin:
	mkdir bin
src:
	mkdir src
txt:
	mkdir txt

clean:
	-rm -rf build/* bin/* txt/*

