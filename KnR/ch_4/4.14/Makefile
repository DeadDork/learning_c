CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_swap
OBJ = 4-14.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
