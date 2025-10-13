CC := gcc
FLAGS := -std=c99

build:
	$(CC) $(FLAGS) main.c -o bin/main