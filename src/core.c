#include "stdint.h"
#include "stdio.h"
#include <arpa/inet.h>
#include <sys/socket.h>

#include "sodium.h"

#include "forest.h"




/*
	Node initialization
*/
ForestNode initNode(uint16_t port, int peercap){
	ForestNode ret;
	
	printf("%i\n", crypto_sign_PUBLICKEYBYTES);
	printf("%i\n", crypto_sign_SECRETKEYBYTES);
	printf("%i\n", crypto_box_PUBLICKEYBYTES);
	printf("%i\n", crypto_box_SECRETKEYBYTES);
	
	crypto_box_keypair (ret.msgkey.bytes, ret.rcvkey.bytes);
	crypto_sign_keypair(ret.pubkey.bytes, ret.seckey.bytes);
	
	ret.port	= port;
	ret.peercap = peercap;
	
	ret.peers   = malloc(sizeof(Peer) * peercap);
	ret.peerct  = 0;
	
	return ret;
}


