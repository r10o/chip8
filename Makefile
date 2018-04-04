TARGET	:= chip8

# Compiler
CC		:= clang

# Files
SRCDIR	:= src
BLDDIR	:= build

SRC		:= $(shell find $(SRCDIR) -type f -name *.c)
OBJ		:= $(subst $(SRCDIR),$(BLDDIR),$(SRC:.c=.o))
CMD		:= $(OBJ:.o=.o.json)

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
	CFLAGS += -Wall 
	CFLAGS += -Wextra
	CFLAGS += -g
	CFLAGS += -pedantic
	CFLAGS += -DDEBUG

	COMP := yes
else
	CFLAGS += -O2
endif

all: setup options $(TARGET)

setup:
	@mkdir -p build

options:
	@echo "$(TARGET) build options:"
	@echo "CFLAGS	= $(CFLAGS)"
	@echo "LDFLAGS	= $(LIBS)"
	@echo "CC	= $(CC)"
	@echo "SRC	= $(SRC)"
	@echo "OBJ	= $(OBJ)"
	@echo "CMD	= $(CMD)"

$(BLDDIR)/%.o: $(SRCDIR)/%.c
ifeq ($(COMP), yes)
	$(CC) -MJ $@.json $(CFLAGS) -c $< -o $@
else
	$(CC) $(CFLAGS) -c $< -o $@
endif

$(TARGET): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(BLDDIR)/$(TARGET)
ifeq ($(COMP), yes)
	@sed -e '1s/^/[\n/' -e '$$s/,$$/\n/' $(CMD) > $(BLDDIR)/compile_commands.json
endif

clean:
	@rm -rvf $(OBJ) $(CMD) $(TARGET)

.PHONY: all setup options clean 
