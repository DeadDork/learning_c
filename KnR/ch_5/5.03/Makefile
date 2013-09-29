CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_strcat
OBJ = 5-3.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ).o : $(OBJ).c

.PHONY : clean
clean :
	rm *.o $(BIN)
