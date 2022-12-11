CC=gcc

all:
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ../hashmap/map.c -lm

debug:
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ../hashmap/map.c -lm -ggdb
