#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{
	//Creating socket
	int s_sock;
	s_sock=socket(AF_INET,SOCK_STREAM,0);
	
	//Assigning socket details	
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_port=htons(9008);
	server.sin_addr.s_addr=INADDR_ANY;
	
	//Waiting for the client to bind
	if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
	{
	printf("connection error");
	exit(-1);
	}
	
	//Listening to client
	listen(s_sock,5);
	
	//Accepting the client	
	int c_sock;
	c_sock=accept(s_sock,NULL,NULL);
	
	//Receiving message
	char s_data[256];
	recv(c_sock,&s_data,sizeof(s_data),0);
	printf("Client message: %s",s_data);
	
	//Closing socket	
	close(s_sock);
	return 0;
}