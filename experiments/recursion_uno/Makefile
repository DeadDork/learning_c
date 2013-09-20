CC = gcc
CFLAGS = -Wall -Wextra -g
CCFLAGS = 
LDFLAGS =

BIN = iter_calc
OBJ = main.o function.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

function.o : function.c
main.o : main.c

.PHONY : clean
clean :
	rm *.o $(BIN)
