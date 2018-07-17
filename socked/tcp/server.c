#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "echo.h"

int main(){
	sockaddr_t client, server;
	socklen_t length = sizeof(sockaddr_t);
	int server_sockd, client_sockd;
	char msg[MSG_SIZE];
	if ((server_sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){//получаем дискриптор точки соединения
		perror("can not get TCP socket");
		exit(1);
	}
	memset(&server, 0, sizeof(sockaddr_t)); //зануляем структура адреса сервера и описываем 
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	server.sin_port = htons(PORT);
	if (bind(server_sockd, &server, sizeof(sockaddr_t)) < 0){ //присваивам сокета адрес
		perror("can not bind TCP socket");
		exit(2);
	}
	listen(server_sockd, 1);
	if ((client_sockd = accept(server_sockd, &client, &length)) < 0){ //ждем клиента и принимаем от него сообщение
		perror("can not accept TCP connection");
		exit(5);
	}
	while(1){
		switch (recv(client_sockd, msg, MSG_SIZE, 0)){ //получаем сообщение от клиента
			case -1:{ //сообщение об ошибке
				perror("can not recieve from TCP socket");
				exit(3);
				break;
			}			
			case 0: {// сообщение разорвано
				perror("client disconnected");
				exit(0);
                		break;
			}
			default:{ //сообщение принято
                		printf("TCP server received from client: %s\n", msg);
			}
		}
		char resp[MSG_SIZE] = "mod: "; //отвечаем клиенту сообщением с модифицированными данными
		strncat(resp, msg, MSG_SIZE - strlen(resp) - 1);
		printf("TCP server sended: %s\n", resp);
	}
	return 0;
}