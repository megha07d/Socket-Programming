
// CS20B1060
// MEGHANA MANVITHA

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int server_sock;

    server_sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_sock < 0)
    {
        printf("Error in socket creation!\n");
        return 1;
    }

    struct sockaddr_in server, other;

    server.sin_family = AF_INET;
    server.sin_port = htons(9001);
    server.sin_addr.s_addr = INADDR_ANY;

    socklen_t add;
    add = sizeof(other);

    char msg[256];
    char otp[10] = "1234";

    bind(server_sock, (struct sockaddr *)&server, sizeof(server));

    recvfrom(server_sock, msg, sizeof(msg), 0, (struct sockaddr *)&other, &add);

    // other - ip of sender - stores details of sender

    // use the same when u want tosend msg to that sender back

    printf("\nserver got:%s\n", msg);

    sendto(server_sock, otp, sizeof(otp), 0, (struct sockaddr *)&other, sizeof(other));

    printf("\nserver sent:%s\n", otp);

    close(server_sock);

    return 0;
}
