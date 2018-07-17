#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "echo.h"

int main(){
	int serv_skd;
	char msg[SIZE];
	sockaddr_t server;
	socklen_t length = sizeof(sockaddr_t);
	if ((serv_skd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		perror("can not get TCP socket");
		exit(1);
	}
	memset(&server, 0, sizeof(sockaddr_t));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server.sin_port = htons(PORT);
	if (connect(serv_skd, &server, length) < 0) {
		perror("can not connect with TCP server");
		exit(5);
	}

	while (1) {
		if (!fgets(msg, SIZE, stdin)) {
			printf("can not read message!\n");
			exit(6);
		}
		char *endl = strchr(msg, '\n');
		if (endl){
			*endl = '\0';
		}
		if (send(serv_skd, msg, SIZE, 0) < 0){
			perror("can not send to TCP socket");
			exit(4);
		}
		printf("TCPClient sended: %s\n", msg);
		char resp[SIZE];
		if (recv(serv_skd, resp, SIZE, 0) < 0) {
			perror("can not recieve from TCP socket");
			exit(3);
		}
		printf("TCP client received from server: %s\n", resp);
	}
	return 0;
}
