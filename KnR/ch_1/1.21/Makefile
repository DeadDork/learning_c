CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = 1-21
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o *[-][1-9][0-9]
