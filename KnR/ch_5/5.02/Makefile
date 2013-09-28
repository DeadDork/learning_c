CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN = test_getfloat
OBJ = 5-2.o getch.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

5-2.o : 5-2.c
getch.o : getch.c

.PHONY : clean
clean :
	rm *.o $(BIN)
