TARGET	=	chip8
SOURCES	=	$(wildcard *.c)
HEADERS	=	$(wildcard *.h)

CFLAGS	=	-Wall -g -lSDL -std=c99

BINDIR	=	"../bin"
LOGDIR	=	"../logs"

all: setup $(TARGET)

setup:
	@mkdir -p $(BINDIR)
	@mkdir -p $(LOGDIR)

$(TARGET):
	@echo "Compiling..."
	@gcc $(CFLAGS) -o $(BINDIR)/$(TARGET) $(SOURCES) 2> $(LOGDIR)/$(TARGET).log

clean:
	@echo "Cleaning..."
	@rm -f "$(BINDIR)/$(TARGET)"
	@rm -f "$(LOGDIR)/$(TARGET).log"
