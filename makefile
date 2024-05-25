# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Executables
MYNC = mync
TTT = ttt

# Source files for each executable
MYNC_SRC = mync.c
TTT_SRC = ttt.c main.c

# Object files for each executable
MYNC_OBJ = $(MYNC_SRC:.c=.o)
TTT_OBJ = $(TTT_SRC:.c=.o)

# Default target
all: mync ttt

# Rule to build mync
mync: $(MYNC_OBJ)
	$(CC) $(CFLAGS) -o $(MYNC) $(MYNC_OBJ)

# Rule to build ttt5
ttt: $(TTT_OBJ)
	$(CC) $(CFLAGS) -o $(TTT) $(TTT_OBJ)

# Rule to compile mync source files
$(MYNC_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile ttt source files
$(TTT_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(MYNC) $(TTT) $(MYNC_OBJ) $(TTT_OBJ)

.PHONY: all clean mync ttt
