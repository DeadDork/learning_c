CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = tail
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ) : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
