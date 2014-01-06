# Target
TARGET		:= chip8
TYPE		:= bin

# Version
VERSION_MAJOR	:= 0
VERSION_MINOR	:= 1
VERSION_REV	:= 2
VERSION		:= $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_REV)

# Files
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)

# Libraries
LIBS		:= -lSDL
LIBS		+= -lSDL_mixer

# Name of output file
OUTPUT		:= $(TARGET)
LIB_LN		:=
LIB_LN_V	:=

# CFLAGS
CFLAGS		:= -Wall 
CFLAGS		+= -pipe
CLFAGS		+= -std=c99

# Defines
CFLAGS		+= -DVERSION=\"$(VERSION)\"

# LDFLAGS
LDFLAGS		:= $(LIBS)

# You can change the following depending on your system

# Options
DEBUG		:= no
PEDANTIC	:= no
OPTIMIZE 	:= yes

# Compiler and linker
CC		:= clang

# Paths
PREFIX		:= /usr/local
BIN_DIR		:= bin
DOC_DIR		:= share/$(TARGET)
INC_DIR		:= include
LIB_DIR		:= lib
MAN_DIR		:= share/man
SRC_DIR		:= src
