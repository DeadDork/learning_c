CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = expr
OBJ = main.o functions.o stacks.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

main.o : main.c
functions.o : functions.c
stacks.o : stacks.c

.PHONY : clean
clean :
	rm *.o $(BIN)
