CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c tic-tac-toe.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = tic-tac-toe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
