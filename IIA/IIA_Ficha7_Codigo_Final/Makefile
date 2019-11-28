objects = main.o funcao.o utils.o algoritmo.o
headers = funcao.h algoritmo.h utils.h
CFLAGS = -I . -g -ggdb

build: $(objects)
	gcc -o agent $(objects) $(CFLAGS) -lm

main.o: main.c $(headers)

funcao.o: funcao.c $(headers)

utils.o: utils.c $(headers)

algoritmo.o: algoritmo.c $(headers)

clean:
	rm *.o
