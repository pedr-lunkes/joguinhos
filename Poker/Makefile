all: baralho.o fila.o main.o
	gcc -o main main.o baralho.o fila.o

baralho.o:
	gcc -c baralho.c

fila.o:
	gcc -c fila.c

main.o:
	gcc -c main.c

clean:
	rm *.o main

run:
	./main
