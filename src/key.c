#include "stdint.h"
#include "stdio.h"

#include "forest.h"


int cmpKey32(Key32 a, Key32 b){
	uint64_t* as = (uint64_t*)&a.bytes;
	uint64_t* bs = (uint64_t*)&b.bytes;
	for(int i = 0; i < 4; i++){
		if(as[i] == bs[i]) continue;
		if(as[i]  < bs[i]) return 1;
		return -1;
	}
	return 0;
}


int cmpKey64(Key64 a, Key64 b){
	uint64_t* as = (uint64_t*)&a.bytes;
	uint64_t* bs = (uint64_t*)&b.bytes;
	for(int i = 0; i < 8; i++){
		if(as[i] == bs[i]) continue;
		if(as[i]  < bs[i]) return 1;
		return -1;
	}
	return 0;
}


void printKey32(Key32 k){
	for(int i = 0; i < 32; i++)
		printf("%02X ", k.bytes[i]);
	printf("\n");
}


void printKey64(Key64 k){
	for(int i = 0; i < 64; i++)
		printf("%02X ", k.bytes[i]);
	printf("\n");
}
