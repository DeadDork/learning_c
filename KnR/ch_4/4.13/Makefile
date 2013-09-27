CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = string_reverse
OBJ = 4-13.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
