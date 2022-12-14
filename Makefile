CC=gcc
BUNDLE=interpreter

all: clean
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ./core/interpreter/parser/parser.c ./common/utils.c ./core/interpreter/invoker/invoker.c ../hashmap/map.c -o $(BUNDLE) -lm

debug: clean
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ./core/interpreter/parser/parser.c ./common/utils.c ./core/interpreter/invoker/invoker.c ../hashmap/map.c -o $(BUNDLE) -lm -ggdb

clean: