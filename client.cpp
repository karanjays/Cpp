#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>


int main(){
	char *ip="33.33.33.33";
	int port=8848;
	int client_sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char message[1024];
	int n;
	client_sock=socket(AF_INET,SOCK_STREAM,0);
	
	if(client_sock<0){
	perror("client error");
	exit(1);
	}
	
	printf("TCP client socket created \n");
	addr.sin_family=AF_INET;
	addr.sin_port=port;
	addr.sin_addr.s_addr=inet_addr(ip);
	n=connect(client_sock,(struct sockaddr*)&addr,sizeof(addr));
	
	if(n>=0){
		printf("connected to server \n");
	}
	
	else{
		printf("not connected to server \n");
	}
	scanf("%s",message);
	send(client_sock,message,sizeof(message),0);
	close(client_sock);
	return 0;
}

