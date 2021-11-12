#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include <arpa/inet.h>
#include <sys/socket.h>

#include "sodium.h"

#include "forest.h"



int nodeServer(ForestNode* n){
	// Open socket
	struct sockaddr_in si_me, si_other;
	unsigned int s, i, slen = sizeof(si_other) , recv_len;
	char buf[65536];
	if((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) return 0;
	memset((char *) &si_me, 0, sizeof(si_me));

	if(bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) == -1) return 0;

	while(1){
		// Wait on incoming packets, send any outgoing packets
		if((recv_len = recvfrom(s, buf, 65536, 0, (struct sockaddr *) &si_other, &slen)) == -1) return 0;
		
		// Parse packets, make decision, send any waiting outgoing packets
		
		
		//if(sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1) return 0;
	}
	return 1;
}



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
	
	// TODO: add a thread that runs a send/recv loop
	
	return ret;
}





