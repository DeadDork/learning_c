CC = gcc
CFLAGS = -Wall -Wextra #-g
LDFLAGS =

BIN = 1-24
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o *[0-9]
