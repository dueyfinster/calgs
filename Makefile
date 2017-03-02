PROGRAM_NAME=ss
CC=gcc

all: selection-sort binary-search insertion-sort 

selection-sort: selection-sort.c
	$(CC) -o selection-sort selection-sort.c

binary-search: binary-search.c
	$(CC) -o binary-search binary-search.c

insertion-sort: insertion-sort.c
	$(CC) -o insertion-sort insertion-sort.c
clean:
	rm -f selection-sort binary-search insertion-sort 

