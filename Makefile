CC := gcc
FLAGS := -std=c99

build:
	$(CC) $(FLAGS) main.c structures.h fonctions.h fonctions.c -o bin/main