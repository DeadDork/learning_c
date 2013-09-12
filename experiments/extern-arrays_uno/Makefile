CC = gcc
CFLAGS = -Wall -Wextra #-g # For debugging
LDFLAGS =

OBJ = main.o

extern-arrays_1 : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

main.o : main.c header.h

.PHONY : clean
clean :
	rm *.o *[0-9]
