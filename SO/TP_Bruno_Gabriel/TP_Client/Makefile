objects = main.o client_functions.o
headers = client.h ../medit_defaults.h
CFLAGS	= -I . -g -ggdb

tp_client: $(objects)
	gcc -o tp_cliente $(objects) $(CFLAGS) -lncurses -pthread

main.o: main.c $(headers)
client_functions.o: client_functions.c $(headers)

clean:
	rm *.o
