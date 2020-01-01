#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#include <time.h>

#define PORT 8081

int main(int argc, char const *argv[])
{
    int client_fd = 0;
    int read_num  = 0;
    struct sockaddr_in address;

    char buffer[1024] = {0};

    /* Create the socket failed */
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    /* Address to set port */
    address.sin_family = AF_INET;
    address.sin_port   = htons(PORT);

    /* Convert IPv4 and IPv6 addresses from text to binary form */
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0)
    {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
    }

    /* Connect the socket client to server */
    if (connect(client_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1)
    {
        /* Client send data to server */
        printf("Client: ");
        gets(buffer);
        send(client_fd, buffer, strlen(buffer), 0);
        /* Get data from server */
        memset(buffer, 0, sizeof(buffer));
        read_num = read(client_fd, buffer, 1024);
        if(read_num)
        {
            printf("Server: %s\n", buffer);
        }
    }
    return 0;
}
