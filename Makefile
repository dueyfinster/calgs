PROGRAM_NAME=insertion-sort
CC=gcc

all: selection-sort binary-search insertion-sort 

selection-sort: selection-sort.c
	$(CC) -o selection-sort selection-sort.c

binary-search: binary-search.c
	$(CC) -o binary-search binary-search.c

insertion-sort: insertion-sort.c
	$(CC) -o insertion-sort insertion-sort.c && chmod 755 insertion-sort

run:    ${PROGRAM_NAME}	
	./${PROGRAM_NAME}

clean:
	rm -f selection-sort binary-search insertion-sort 

