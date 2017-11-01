PROGRAM_NAME=merge-sort
CC=gcc
SRC := naive
BIN := bin

CSRC := $(wildcard $(SRC)/*.c)
BINS := $(patsubst $(SRC)/%.c, $(BIN)/%, $(CSRC))

all: $(BINS)

$(BIN)/%: $(SRC)/%.c
	$(CC) $(CC_FLAGS) -o $@ $< 

run:
	./$(BIN)/${PROGRAM_NAME}

clean:
	-@ $(RM) $(BINS)

