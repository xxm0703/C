CC=gcc

vector_tires: vector.o tires.o
	$(CC) -Wall --pedantic -std=c11 -o vector_tires vector.o tires.o

vector.o: vector.c 
	$(CC) -c -o vector.o vector.c

tires.o: 06.c 
	$(CC) -c -o tires.o 06.c

1zad: 01.c
	$(CC) -Wall --pedantic -std=c11 -o 1zad 01.c

2zad: 02.c
	$(CC) -Wall --pedantic -std=c11 -o 2zad 02.c

3zad: 03.c
	$(CC) -Wall --pedantic -std=c11 -o 3zad 03.c

4zad: 04.c
	$(CC) -Wall --pedantic -std=c11 -o 4zad 04.c

5zad: 05.c
	$(CC) -Wall --pedantic -std=c11 -o 5zad 05.c
clean:
	rm *.o
