PROGRAM_NAME=merge-sort
SRC_DIR=naive
BIN_DIR=bin
CC=gcc

all: selection-sort binary-search insertion-sort merge-sort quick-sort

selection-sort: $(SRC_DIR)/selection-sort.c
	$(CC) -o $(BIN_DIR)/selection-sort $(SRC_DIR)/selection-sort.c

binary-search: b$(SRC_DIR)/binary-search.c
	$(CC) -o $(BIN_DIR)/binary-search $(SRC_DIR)/binary-search.c

insertion-sort: $(SRC_DIR)/insertion-sort.c
	$(CC) -o $(BIN_DIR)/insertion-sort $(SRC_DIR)/insertion-sort.c && chmod 755 $(BIN_DIR)/insertion-sort

merge-sort: $(SRC_DIR)/merge-sort.c
	$(CC) -o $(BIN_DIR)/merge-sort $(SRC_DIR)/merge-sort.c && chmod 755 $(BIN_DIR)/merge-sort

quick-sort: $(SRC_DIR)/quick-sort.c
	$(CC) -o $(BIN_DIR)/quick-sort $(SRC_DIR)/quick-sort.c && chmod 755 $(BIN_DIR)/quick-sort

run:    ${PROGRAM_NAME}	
	./$(BIN_DIR)/${PROGRAM_NAME}

clean:
	rm -f $(BIN_DIR)/*

