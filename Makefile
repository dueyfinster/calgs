PROGRAM_NAME=ss
CC=gcc

all: selection-sort binary-search 

selection-sort: selection-sort.c
	$(CC) -o selection-sort selection-sort.c

binary-search: binary-search.c
	$(CC) -o binary-search binary-search.c
clean:
	rm -f selection-sort binary-search 

