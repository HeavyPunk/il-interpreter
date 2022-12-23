CC=gcc
BUNDLE=interpreter.bin

all: clean
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ./core/interpreter/parser/parser.c ./common/utils.c ./core/interpreter/invoker/invoker.c ./core/interpreter/operators/LDN/ldn.c ./core/interpreter/operators/ST/st.c ./core/interpreter/operators/STN/stn.c ./core/interpreter/operators/S/s.c	./core/interpreter/operators/R/r.c ./core/interpreter/operators/AND/and.c ./core/interpreter/operators/ANDN/andn.c ./core/interpreter/operators/OR/or.c ./core/interpreter/operators/ORN/orn.c ./core/interpreter/operators/XOR/xor.c ./core/interpreter/operators/XORN/xorn.c ./core/stream/stream.c ./core/stream/std/stdin.c ./core/interpreter/operators/ADD/add.c ./core/interpreter/operators/MUL/mul.c ./core/stream/std/stdout.c ../hashmap/map.c -o $(BUNDLE)

debug: clean
	$(CC) main.c ./core/interpreter/operators/LD/ld.c ./core/interpreter/reader/file_reader.c ./core/interpreter/reader/reader.c ./core/interpreter/parser/parser.c ./common/utils.c ./core/interpreter/invoker/invoker.c ./core/interpreter/operators/LDN/ldn.c ./core/interpreter/operators/ST/st.c ./core/interpreter/operators/STN/stn.c ./core/interpreter/operators/S/s.c	./core/interpreter/operators/R/r.c ./core/interpreter/operators/AND/and.c ./core/interpreter/operators/ANDN/andn.c ./core/interpreter/operators/OR/or.c ./core/interpreter/operators/ORN/orn.c ./core/interpreter/operators/XOR/xor.c ./core/interpreter/operators/XORN/xorn.c ./core/stream/stream.c ./core/stream/std/stdin.c ./core/interpreter/operators/ADD/add.c ./core/interpreter/operators/MUL/mul.c ./core/stream/std/stdout.c ../hashmap/map.c -o $(BUNDLE) -ggdb

clean: