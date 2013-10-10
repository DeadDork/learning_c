CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = demo
OBJ = 5-9
$(BIN) : $(OBJ).o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ).o : $(OBJ).c

.PHONY : clean
clean :
	rm *.o $(BIN)
