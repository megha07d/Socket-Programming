
//CS20B1060
//MEGHANA MANVITHA

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
int client_sock;

client_sock=socket(AF_INET,SOCK_DGRAM,0);

if(client_sock < 0)
{
    printf("Error in socket creation!\n");
    return 1;
}

struct sockaddr_in client,other;

//initializ client- structure 
client.sin_family=AF_INET;//ipv4
client.sin_port=htons(9001);//port num
client.sin_addr.s_addr=INADDR_ANY;//accept any incomin msg



socklen_t ad;
ad=sizeof(other);

char msg[256]="9392985073";
char otp[10];

sendto(client_sock,msg,sizeof(msg),0,(struct sockaddr*)&client,sizeof(client));

printf("\nclient sent:%s\n",msg);

bind(client_sock,(struct sockaddr*)&client,sizeof(client));

recvfrom(client_sock,otp,sizeof(otp),0,(struct sockaddr*)&other,&ad);

printf("\nclient got:%s\n",otp);

close(client_sock);

return 0;
}

