aula02:	aula02.o imprime.o
	gcc aula02.o imprime.o -o aula02

aula02.o:aula02.c imprime.h
	gcc -c aula02.c

imprime.o:imprime.c
	gcc -c imprime.c

clean:
	rm *.o
	rm *.i
	rm *.s
