# Instructions
#
# If you create a new test, follow these conventions:
#
# 1. Name the new test source file after whatever function you are testing + an underscore + the autoincremented number of that naming scheme (e.g. if you are interested in testing *substring*, and there are four *substring* tests--namely *substring_1.c*, *substring_2.c*, *substring_3.c*, *substring_4.c*--then set the new test file name to *substring_5.c*.
#
# 2. Set a new BIN_n variable under the *Binaries* section that is autoincremented by 1 (e.g. if the last variable was BIN_3, then set the new variable to BIN_4).
#
# 3. Enter target, dependencies, and recipes in the *Targets & Recipes* section per the following form:
#
# 	$(BIN_n) : $(OBJ_n)
# 		$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
# 	$(BIN_n).o : $(BIN_n).c [NECESSARY HEADER FILES]

# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

# Object code
BIN_1 = rematch_1
OBJ_1 = $(BIN_1).o sstring.o rematch.o

BIN_2 = rematch_2
OBJ_2 = $(BIN_2).o sstring.o

BIN_3 = rematch_3
OBJ_3 = $(BIN_3).o sstring.o rematch.o

# Targets & Recipes
$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_1).o : $(BIN_1).c sstring.h rematch.h

$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_2).o : $(BIN_2).c sstring.h

$(BIN_3) : $(OBJ_3)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_3).o : $(BIN_3).c sstring.h rematch.h

# Common dependencies
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

# rm object files & executables
# N.B. This will only delete the first nine tests in a series, e.g. *sstring_9* will be removed, but not *sstring_10*.
.PHONY : clean
clean :
	rm *.o *_[1-9]
