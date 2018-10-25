objects = main.o client_functions.o
headers = client.h

tp_client: $(objects)
	gcc -o tp_cliente $(objects) -I . -lncurses

main.o: main.c $(headers)
client_functions.o: client_functions.c $(headers)

clean:
	rm *.o
