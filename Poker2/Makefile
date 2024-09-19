all: Deque.o 
	gcc item.o Deque.o teste.o -lm -std=c99 -o teste -Wall

Deque.o:
	gcc -c Deque/Deque.c

clean:
	rm *.o teste
	rm Deque.zip

run:
	./testeitem

zip:
	zip -R Deque.zip Deque.c