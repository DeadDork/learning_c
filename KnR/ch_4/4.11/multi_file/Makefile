CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = srpc
OBJ = compile.o getch.o stack.o getop.o main.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

compile.o : compile.c
getch.o : getch.c
stack.o : stack.c
getop.o : getop.c
main.o : main.c

.PHONY : clean
clean :
	rm *.o $(BIN)
