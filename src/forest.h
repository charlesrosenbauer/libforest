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

int  cmpKey32  (Key32, Key32);
int  cmpKey64  (Key64, Key64);
void printKey32(Key32);
void printKey64(Key64);

typedef enum{
	DT_PING			= 0,
	DT_PONG			= 1,
	DT_ASSM			= 2,
	DT_DATA			= 3
}PacketDataType;

typedef struct{
	uint8_t			magic;
	uint16_t		size, assm, ix;
	PacketDataType	type;
	uint8_t*		bytes;
}DataPacket;

typedef struct{
	uint8_t		magic;
	Key32		pubkey;
	Key32		msgkey;
	uint32_t	id;
}ConnectPacket;

typedef struct{
	uint8_t		magic;
	Key32		sign;
}DisconnectPacket;

typedef struct{
	uint8_t		magic;
	Key32		pubkey;
	Key32		msgkey;
}XchgPacket;


typedef enum{
	PT_DATA			= 0,
	PT_CONNECT		= 1,
	PT_DISCONNECT	= 2,
	PT_XCHG_KEYS	= 3
}PacketType;

typedef struct{
	uint32_t	ip;
	uint16_t	port, size;
	PacketType	type;
	union{
		DataPacket			data;
		ConnectPacket		conn;
		DisconnectPacket	dcon;
		XchgPacket			xchg;
	};
}Packet;


typedef struct{
	Key32		pubkey, msgkey;
	uint32_t	ip;
	uint16_t	port;
	float		reliability;
	int			lostPings;
}Peer;

typedef struct{
	uint16_t 	port;
	Key32   	pubkey;
	Key64		seckey;
	Key32		msgkey, rcvkey;
	
	uint32_t	socket;
	
	Peer*		peers;
	int			peerct, peercap;
}ForestNode;


ForestNode initNode(uint16_t, int);




#endif
