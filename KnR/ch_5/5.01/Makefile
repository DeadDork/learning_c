CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_getint
OBJ = 5-1.o getch.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

5-1.o : 5-1.c
getch.o : getch.c

.PHONY : clean
clean :
	rm *.o $(BIN)
