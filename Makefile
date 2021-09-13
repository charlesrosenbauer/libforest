test:
	clang -O3    -lsodium src/*.c test.c -o bin/test
	
debug:
	clang -Og -g -lsodium src/*.c test.c -o bin/test
