#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
	
	char *ip="33.33.33.33";
	int port=8848;
	
	int server_sock,client_sock;
	
	struct sockaddr_in server_addr,client_addr;
	
	socklen_t addr_size;
	char message[1024];
	int n;
	server_sock=socket(AF_INET,SOCK_STREAM,0);
	
	if(server_sock<0){
		perror("Socket error");
		exit(1);
	}
	
	printf("TCP server socket created \n");
	memset(&server_addr,'\0',sizeof(server_addr));
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=port;
	server_addr.sin_addr.s_addr=inet_addr(ip);
	
	n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	
	if(n<0){
		perror("bind error\n");
		exit(1);
	}
	
	printf("bind the port number\n");
	n=listen(server_sock,3);
	
	if(n>=0){
		printf("Waiting for message...\n");
	}
	
	while(1){
		addr_size=sizeof(client_addr);
		client_sock=accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);
	
		if(client_sock>=0){
			printf("client connected..\n");
		}
		else{
			printf("client not connected..\n");
		}
		recv(client_sock,message,sizeof(message),0);
		printf(" %s\n",message);
		close(client_sock);
	}
	return 0;
}

