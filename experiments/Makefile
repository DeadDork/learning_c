CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN_1 = regex-sub_1
OBJ_1 = $(BIN_1).o sstring.o rematch.o
$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_1).o : $(BIN_1).c

BIN_2 = regex-offsets_1
OBJ_2 = $(BIN_2).o sstring.o rematch.o
$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_2).o : $(BIN_2).c

BIN_3 = functional-dereference-changes_1
OBJ_3 = $(BIN_3).o
$(BIN_3) : $(OBJ_3)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_3).o : $(BIN_3).c

BIN_4 = functional-dereference-changes_2
OBJ_4 = $(BIN_4).o
$(BIN_4) : $(OBJ_4)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_4).o : $(BIN_4).c

BIN_5 = d_s_1
OBJ_5 = d_s-main_1.o d_s-fun_1.o
$(BIN_5) : $(OBJ_5)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
d_s-main_1.o : d_s-main_1.c d_s-fun_1.o d_s-head_1.h
d_s-fun_1.o : d_s-fun_1.c d_s-head_1.h

BIN_6 = strcpy_with_arrays_6
OBJ_6 = $(BIN_6).o
$(BIN_6) : $(OBJ_6)
	$(CC) $(CFLAGS) -o $@ $^ $($LDFLAGS)
$(BIN_6).o : $(BIN_6).c

BIN_7 = strcpy_with_pointers_1
OBJ_7 = $(BIN_7).o
$(BIN_7) : $(OBJ_7)
	$(CC) $(CFLAGS) -o $@ $^ $($LDFLAGS)
$(BIN_7).o : $(BIN_7).c

sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o *[_-][1-9]
