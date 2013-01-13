CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

OBJ = 1-1.o

1-1 : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

1-1.o : 1-1.c

.PHONY : clean
clean :
	rm *.o 1-1
