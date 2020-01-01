#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>  	/* sockaddr, sa_family_t, socklen_t */
#include <netinet/in.h>		/* in_port_t, in_addr_t, sa_family_t, sockaddr_in */

#define PORT 8081

int main(int argc, char const *argv[])
{
	/* Define variable to manage socket */
	int server_fd  	= 0;
	int new_socket 	= 0;
	int read_num 	= 0;

	struct sockaddr_in address;
	int addrlen = sizeof(address);

	char buffer[1024] = {0};

#ifdef SO_REUSEPORT
	int opt = 1;
#endif
	/* Creating socket file descriptor  */
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		printf("Socket create failed\n");
		return -1;
	}

	/* Set address and port reusable when re-run program */
	/* Prevents error such as: "address already in use" */
#ifdef SO_REUSEPORT
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeopt(opt)))
	{
		printf("Set option for socket failed\n");
		return -1;
	}
#endif
	/* Set address to bind from server */
	address.sin_family		= AF_INET;
	address.sin_addr.s_addr	= INADDR_ANY;
	address.sin_port		= htons(PORT);

	/* Bind the socket to port 8080 */
	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		printf("Bind socket failed\n");
		return -1;
	}

	/* Listen for the connection from client */
	if(listen(server_fd, 3) < 0)
	{
		printf("Listen failed\n");
		return -1;
	}

	/* Accept the connection */
	if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
	{
		printf("Accept failed\n");
		return -1;
	}

	/* Read data from client */
	while(1)
	{
		/* Read data from client */
		memset(buffer, 0, sizeof(buffer));
		read_num = read(new_socket, buffer, 1024);
		if(read_num)
		{
			printf("Client: %s\n", buffer);
		}

		/* Send data back to client */
		printf("Sever: ");
		strcat(buffer, "-ACK");
		printf("%s\n", buffer);
		/* Send data back to client */
		send(new_socket, buffer, strlen(buffer), 0);
	}
	return 0;
}
