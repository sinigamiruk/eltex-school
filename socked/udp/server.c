#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "echo.h"

int main()
{
	int skd;
	char msg[MSG_SIZE];
	sockaddr_t client, server;
	socklen_t length = sizeof(sockaddr_t);
	if ((skd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		printf("Can not get UDP socket");
		exit(1);
	}
	memset(&server, 0, sizeof(sockaddr_t));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server.sin_port = htons(PORT);
	if (bind(skd, &server, sizeof(sockaddr_t)) < 0)
	{
		printf("Can not bind UDP socket");
		exit(2);
	}
	while (1) 
	{
		if (recvfrom(skd, msg, MSG_SIZE, 0, &client, &length) < 0)
		{
			printf("Can not recieve from UDP socket");
			exit(3);
		}
		printf("UDP server received from client: %s\n", msg);
		char resp[MSG_SIZE] = "mod:";
		strncat(resp, msg, MSG_SIZE - strlen(resp) - 1);
		if (sendto(skd, resp, MSG_SIZE, 0, &client, length) < 0)
		{
			printf("can not send to UDP socket");
			exit(4);
		}
		printf("UDP server sended: %s\n", resp);
	}
	return 0;
}
