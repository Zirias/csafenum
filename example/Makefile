example_OBJ := fruit.o example.o
example_INC := -I../include

CC := gcc

CFLAGS += -std=c89 -Wall -Werror -pedantic

example: $(example_OBJ)
	$(CC) $(CFLAGS) -oexample $(example_OBJ)

fruit.o: fruit.c fruit.h
	$(CC) $(CFLAGS) $(example_INC) -c fruit.c

example.o: example.c fruit.h
	$(CC) $(CFLAGS) $(example_INC) -c example.c

clean:
	rm -f *.o
	rm -f example

.PHONY: clean

