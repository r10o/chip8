TARGET	:= chip8

# Compiler
CC		:= clang

# Files
SRC		:= $(wildcard src/*.c)
OBJ		:= $(SRC:.c=.o)

# Libraries
LIBS	:= $(shell sdl-config --libs)
LIBS	+= -lSDL_mixer

# CFLAGS
CFLAGS	+= -pipe
CFLAGS	+= -std=c11
CFLAGS	+= $(shell sdl-config --cflags)

# CFLAG options
# Compiler debugging enabled
DEBUG	:= yes

ifeq ($(DEBUG), yes)
	CFLAGS	:= -Wall 
	CFLAGS += -Wextra
	CFLAGS += -g
	CFLAGS += -pedantic
else
	CFLAGS	+= -O2
endif

all: options $(TARGET)

options:
	@echo "$(TARGET) build options:"
	@echo "CFLAGS	= $(CFLAGS)"
	@echo "LDFLAGS	= $(LIBS)"
	@echo "CC	= $(CC)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(TARGET)

clean:
	@rm -rvf $(OBJ) $(TARGET)

.PHONY: all options clean 
