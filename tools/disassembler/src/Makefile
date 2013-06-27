CC	= gcc
BIN	= disassembler
SRC	= $(wildcard *.c)
HDR	= $(wildcard *.h)
OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -g -pedantic -std=c99 
LFLAGS	= `sdl-config --libs` -lSDL

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

clean:
	@echo Cleaning.
	@rm -rf *.o $(BIN)
