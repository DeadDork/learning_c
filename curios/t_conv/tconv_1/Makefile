CC = gcc
CFLAGS = -Wall -Wextra #-g # For debugging
LDFLAGS =

OBJ = main.o tempcon.o sstring.o rematch.o

tconv_1 : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

main.o : main.c tempcon.h sstring.h
tempcon.o : tempcon.c tempcon.h sstring.h rematch.h
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o tconv_1
