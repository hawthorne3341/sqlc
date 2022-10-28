NAME=sqlc
CC=gcc
CFLAGS=-g -I$(IDIR)
SRC=src
OBJ=obj
IDIR=$(SRC)/include
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN=$(BINDIR)/$(NAME)

all: $(BIN)

$(BIN): $(BINDIR) $(OBJ) $(OBJS) $(IDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/* $(TEST_BIN) *.txt
