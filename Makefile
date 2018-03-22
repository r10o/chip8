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
CFLAGS	+= -std=c99
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
	@echo "CC		= $(CC)"

%.o: %.c
	@echo -e "\n>> compiling object files <<\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p bin
	@echo -e "\n>> linking object files <<\n"
	$(CC) $(LIBS) $(OBJ) -o $(TARGET)
	@echo -e "\n>> done compiling <<"

clean:
	@echo -e ">> cleaning <<\n"
	@rm -rvf $(OBJ) $(TARGET)
	@echo -e "\n>> done cleaning <<"

.PHONY: all options clean 
