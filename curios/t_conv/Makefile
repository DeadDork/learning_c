CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

OBJ = main.o tempcon.o sstring.o rematch.o

t_conv : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

main.o : main.c tempcon.h sstring.h
tempcon.o : tempcon.c tempcon.h sstring.h rematch.h
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o t_conv
