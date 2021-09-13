#include "stdio.h"

#include "src/forest.h"


int main(){
	int xs[256];
	rngSeed(1);
	for(int i = 0; i <        256; i++) xs[i] = 0;
	for(int i = 0; i < 1073741824; i++){
		int n = rng() % 256;
		xs[n]++;
	}
	for(int i = 0; i < 256; i++){
		printf("\n%i :", i);
		for(int j = 0; j < xs[i]; j += 32768) printf("#");
	}
	printf("\n");
	
	ForestNode node = initNode(8334);
}
