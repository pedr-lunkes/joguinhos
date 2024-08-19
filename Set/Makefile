all: set.o jogo.o
	gcc set.o jogo.o -o jogo

set.o:
	gcc -c set.c

jogo.o:
	gcc -c jogo.c

clean:
	rm *.o jogo

run:
	./jogo
