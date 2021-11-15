#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include <arpa/inet.h>
#include <sys/socket.h>

#include "sodium.h"

#include "forest.h"



int parsePacket(Packet* p, uint8_t* bytes, int size){
	if(size < 32) return 0;
	
	switch(bytes[0]){
		case PT_DATA : {
			/*
				Data packets are, by default, encrypted.
				Parts of the header may be plaintext, 
			*/
		}break;
		
		case PT_CONNECT : {
			if(size != sizeof(ConnectPacket   )) return 0;
			p->conn = *(ConnectPacket   *)bytes;
		}break;
		
		case PT_DISCONNECT : {
			if(size != sizeof(DisconnectPacket)) return 0;
			p->dcon = *(DisconnectPacket*)bytes;
		}break;
		
		case PT_XCHG_KEYS : {
			if(size != sizeof(XchgPacket      )) return 0;
			p->xchg = *(XchgPacket      *)bytes;
		}break;
	}
	
	return 1;
}


int writePacket(Packet* p, uint8_t* bytes){

	return 1;
}



int sendPacket(ForestNode* n, struct sockaddr_in to, Packet p){
	
	char buf[65536];
	int plen = 0;
	// Serialize packet
	
	uint64_t slen = sizeof(to);
	
	if(sendto(n->socket, buf, plen, 0, (struct sockaddr*) &to, slen) == -1) return 0;
	
	return 1;
}


int nodeServer(ForestNode* n){
	// Open socket
	struct sockaddr_in si_me, si_other;
	unsigned int s, i, slen = sizeof(si_other) , recv_len;
	char buf[65536];
	if((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) return 0;
	memset((char *) &si_me, 0, sizeof(si_me));

	if(bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) == -1) return 0;
	n->socket = s;

	while(1){
		// Wait on incoming packets, send any outgoing packets
		if((recv_len = recvfrom(s, buf, 65536, 0, (struct sockaddr *) &si_other, &slen)) == -1) return 0;
		
		// Parse packets, add to packet queue
		
	}
	return 1;
}



/*
	Node initialization
*/
ForestNode initNode(uint16_t port, int peercap){
	ForestNode ret;
	
	//printf("%i\n", crypto_sign_PUBLICKEYBYTES);
	//printf("%i\n", crypto_sign_SECRETKEYBYTES);
	//printf("%i\n", crypto_box_PUBLICKEYBYTES);
	//printf("%i\n", crypto_box_SECRETKEYBYTES);
	
	crypto_box_keypair (ret.msgkey.bytes, ret.rcvkey.bytes);
	crypto_sign_keypair(ret.pubkey.bytes, ret.seckey.bytes);
	
	ret.port	= port;
	ret.peercap = peercap;
	
	ret.peers   = malloc(sizeof(Peer) * peercap);
	ret.peerct  = 0;
	
	// TODO: add a thread that runs a send/recv loop
	
	return ret;
}





