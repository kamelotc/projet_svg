CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra

build:
	$(CC) $(FLAGS) main.c -o bin/main