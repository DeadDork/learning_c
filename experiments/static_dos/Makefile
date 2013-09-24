CC = gcc
CFLAGS = -Wall -Wextra -g
CCFLAGS = 
LDFLAGS =

BIN = static_test
OBJ = main.o static.o not_static.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

main.o : main.c
static.o : static.c
not_static.o : not_static.c

.PHONY : clean
clean :
	rm *.o $(BIN)
