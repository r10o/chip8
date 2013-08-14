CC	= gcc
BIN	= chip8
SRC	= $(wildcard *.c)
HDR	= $(wildcard *.h)
OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -g -pedantic -std=c99
LFLAGS	= -lSDL -lSDL_mixer

all: options $(BIN)

options:
	@echo $(BIN) build options:
	@echo "CC	= $(CC)"
	@echo "CFLAGS	= $(CFLAGS)"
	@echo "LFLAGS	= $(LFLAGS)"

.c.o:
	@echo CC -c $<
	@$(CC) $(CFLAGS) -c $<

$(BIN): $(OBJ)
	@echo CC -o $@
	@$(CC) $(OBJ) -o $(BIN) $(LFLAGS)

force: clean options $(BIN)

clean:
	@echo Cleaning.
	@rm -rf *.o $(BIN)
