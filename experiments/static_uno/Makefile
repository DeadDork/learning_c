CC = gcc
CFLAGS = -Wall -Wextra -g
CCFLAGS = 
LDFLAGS =

BIN = static
OBJ = main.o external.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

function.o : external.c
main.o : main.c

.PHONY : clean
clean :
	rm *.o $(BIN)
