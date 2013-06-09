TARGET	=	disassembler
SOURCES	=	$(TARGET).c

CFLAGS	=	-Wall -Werror -g

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
