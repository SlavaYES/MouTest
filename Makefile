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
OBJECTS=$(addprefix $(build), main.o add_tem.o setAnswer.o setTryAnswer.o)
EXE=main

.PHONY: all clean

all: build txt Theme $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)add_tem.o: $(src)add_tem.c $(src)add_tem.h
	$(CC) $(CFLAGS) -c $(src)add_tem.c -o $@

$(build)setAnswer.o: $(src)setAnswer.c $(src)setAnswer.h
	$(CC) $(CFLAGS) -c $(src)setAnswer.c -o $@

$(build)setTryAnswer.o: $(src)setTryAnswer.c $(src)setTryAnswer.h
	$(CC) $(CFLAGS) -c $(src)setTryAnswer.c -o $@

build:
	mkdir build
src:
	mkdir src
txt:
	mkdir txt
Theme:
	mkdir Theme
	touch Theme/Themes.txt
clean:
	-rm -rf build txt Theme
