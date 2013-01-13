CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

BIN_1 = d_s_1
OBJ_1 = $(BIN_1).o sstring.o rematch.o

BIN_2 = slength_1
OBJ_2 = $(BIN_2).o sstring.o rematch.o

BIN_3 = str2num_1
OBJ_3 = $(BIN_3).o sstring.o rematch.o

$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_1)
$(BIN_1).o : $(BIN_1).c sstring.h

$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_2)
$(BIN_2).o : $(BIN_2).c sstring.h

$(BIN_3) : $(OBJ_3)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_3)
$(BIN_3).o : $(BIN_3).c sstring.h

sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o *_1
