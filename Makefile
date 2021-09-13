test:
	clang -O3    src/*.c test.c -o bin/test
	
debug:
	clang -Og -g src/*.c test.c -o bin/test
