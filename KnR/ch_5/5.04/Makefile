CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_strend
OBJ = 5-4.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ).o : $(OBJ).c

.PHONY : clean
clean :
	rm *.o $(BIN)
