CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_strn_functions
OBJ = 5-5.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ).o : $(OBJ).c

.PHONY : clean
clean :
	rm *.o $(BIN)
