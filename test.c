#include "stdio.h"

#include "src/forest.h"


int main(){
	ForestNode node = initNode(8334, 4096);
	printKey32(node.pubkey);
	printKey64(node.seckey);
	printKey32(node.msgkey);
	printKey32(node.rcvkey);
}
