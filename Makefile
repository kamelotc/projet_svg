CC := gcc
FLAGS := -std=c99

build:
	$(CC) $(FLAGS) main.c structures.h -o bin/main