#include "forest.h"

/*
	NOT a cryptographically secure RNG. Just meant for simple, fast, decent RNG.
*/

static uint64_t rngStateA = 1375981178917;
static uint64_t rngStateB = 6490920000179;

uint64_t rng    (){
	uint64_t x = rngStateA;
	uint64_t y = rngStateB;
	
	// Good-old-fashioned multiply-and-add-with-big-constants
	x = (x * 3751888886129) + 3915789007777;
	y = (y * 8748720097883) - 9984109184239;
	
	// 
	int rotX   = y % 64;
	int rotY   = x % 64;
	x = (x << rotX) | (x >> (64-rotX));
	y = (y >> rotY) | (y << (64-rotY));
	
	x = (y & 0xfff)? x : x ^ 5389173081973;		// Occasionally kick the thing
	rngStateA = y;
	rngStateB = x;
	return x ^ y;
}

uint64_t rngSeed(uint64_t x){
	rngStateA += x;
	rngStateB ^= x;
	return rng();
}






