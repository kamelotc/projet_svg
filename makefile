CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra


build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c 01_Circle/circle.c
	$(CC) $(FLAGS) -c 02_Ellipse/ellipse.c
	$(CC) $(FLAGS) -c 03_Square/square.c
	$(CC) $(FLAGS) -c 04_Rectangle/rectangle.c
	$(CC) $(FLAGS) -c 05_Line/line.c
	$(CC) $(FLAGS) -c 06_Sequence/sequence.c
	$(CC) $(FLAGS) -c 07_Polygon/polygon.c
	$(CC) $(FLAGS) -c 08_Paths/paths.c
	$(CC) $(FLAGS) -c 09_Group/group.c
	$(CC) $(FLAGS) main.o circle.o ellipse.o square.o rectangle.o line.o sequence.o polygon.o paths.o group.o -o main
	

