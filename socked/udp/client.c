#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "echo.h"

int main(){
	int skd;
	char msg[SIZE];
	sockaddr_t server;
	socklen_t length = sizeof(sockaddr_t);
	if ((skd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
		printf("can not get UDP socket");
		exit(1);
	}
	memset(&server, 0, sizeof(sockaddr_t));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server.sin_port = htons(PORT);
	while (1){
		if (!fgets(msg, SIZE, stdin)){
			printf("can not read message!\n");
			exit(6);
		}
		char *endl = strchr(msg, '\n');
		if (endl){
			*endl = '\0';
		}
		if (sendto(skd, msg, SIZE, 0, &server, length) < 0){
			printf("can not send to UDP socket");
			exit(4);
		}
		printf("UDP client sended: %s\n", msg);
		char resp[SIZE];
		if (recvfrom(skd, resp, SIZE, 0, &server, &length) < 0){
			printf("Can not recieve from UDP socket");
			exit(3);
		}
		printf("UDP client received from server: %s\n", resp);
	}
	return 0;
}
