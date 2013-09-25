CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = getop
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
