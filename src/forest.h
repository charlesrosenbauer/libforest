#ifndef __FOREST_HEADER__
#define __FOREST_HEADER__


#include "stdint.h"



uint64_t rng    ();
uint64_t rngSeed(uint64_t);


typedef struct{
	uint8_t		bytes[32];
}Key32;

typedef struct{
	uint8_t		bytes[64];
}Key64;

int cmpKey32(Key32, Key32);
int cmpKey64(Key64, Key64);


typedef struct{
	Key32		pubkey, msgkey;
	uint32_t	ip;
	uint16_t	port;
}Peer;

typedef struct{
	uint16_t 	port;
	Key32   	pubkey, seckey;
	Key32		msgkey, rcvkey;
	
	Peer*		peers;
	int			peerct, peercap;
}ForestNode;


ForestNode initNode(uint16_t);




#endif
