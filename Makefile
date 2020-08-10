all: main

main: main.o llist.o
	gcc main.o llist.o

main.o: main.c
	gcc -c main.c

llist.o: llist.c
	gcc -c llist.c
