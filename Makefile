all: main

main: main.o llist.o dllist.o
	gcc main.o llist.o dllist.o

main.o: main.c
	gcc -c main.c

llist.o: llist.c
	gcc -c llist.c

dllist.o: dllist.c
	gcc -c dllist.c

clean:
	rm main.o llist.o a.out
