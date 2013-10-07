CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = original_string_sort
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ).o : $(OBJ).c

.PHONY : clean
clean :
	rm *.o $(BIN)
