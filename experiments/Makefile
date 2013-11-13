CC = gcc
CFLAGS = -Wall -Wextra #-g
CCFLAGS = -fnested-functions
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

BIN_8 = regex_3
OBJ_8 = $(BIN_8).o sstring.o rematch.o
$(BIN_8) : $(OBJ_8)
	$(CC) $(CFLAGS) -o $@ $^ $($LDFLAGS)
$(BIN_8).o : $(BIN_8).c

BIN_9 = regex_4
OBJ_9 = $(BIN_9).o sstring.o rematch.o
$(BIN_9) : $(OBJ_9)
	$(CC) $(CFLAGS) -o $@ $^ $($LDFLAGS)
$(BIN_9).o : $(BIN_9).c

BIN_10 = shell-sort_1
OBJ_10 = $(BIN_10).o
$(BIN_10) : $(OBJ_10)
	$(CC) $(CFLAGS) $(CCFLAGS) -o $@ $^

BIN_11 = cdcl_1
OBJ_11 = $(BIN_11).o getch_1.o
$(BIN_11) : $(OBJ_11)
	$(CC) $(CFLAGS) $(CCFLAGS) -o $@ $^

BIN_12 = uncdcl_1
OBJ_12 = $(BIN_12).o getch_1.o
$(BIN_12) : $(OBJ_12)
	$(CC) $(CFLAGS) $(CCFLAGS) -o $@ $^

getch_1.o : getch_1.c
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o *[_-][1-9]
