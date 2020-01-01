#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>  	/* sockaddr, sa_family_t, socklen_t */
#include <netinet/in.h>		/* in_port_t, in_addr_t, sa_family_t, sockaddr_in */

#include <pthread.h>

#include <fcntl.h>			/* File open option */

#include "02.data_transfer.h"

#define PORT 8081

int  socket_init(int *client_fd);
void * client_control_task(void * arg);
void * client_receive_task(void * arg);

int main(int argc, char const *argv[])
{
	/* Define variable to manage socket */
	int client_fd = 0;
	int result = 0;

	pthread_t thread[2] = {0};

	/* Init socket and get a fd to read and write file */
	result = socket_init(&client_fd);
	if(result < 0)
	{
		return -1;
	}

	/* Create task to send request and receive file data */
	pthread_create(&thread[0], NULL, client_control_task, (void *)&client_fd);
	pthread_create(&thread[1], NULL, client_receive_task, (void *)&client_fd);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);

	return 0;
}

int socket_init(int *client_fd)
{
	struct sockaddr_in address;

	/* Create the socket */
	if ((*client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	/* Config socket address */
	address.sin_family = AF_INET;
	address.sin_port   = htons(PORT);

	/* Convert IPv4 and IPv6 addresses from text to binary form */
	if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	/* Connect the socket client to server */
	if (connect(*client_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	return 0;
}

/* Client proccessing center */
void * client_control_task(void * arg)
{
	int client_fd = * (int *)arg;
	char cmd[10]  = {0};
	TRANFER_MESSAGE_ST message = {0};

	while(1)
	{
		/* Receive request from user */
		printf("0: Request file list\n1: Request file data\n");
		gets(cmd);
		if(atoi(cmd) == 0)
		{
			message.request = CL_SRV_REQUEST_FILE_LIST;
			send(client_fd, &message, sizeof(message), 0);
			printf("File list: \n");
		}
		else
		{
			/* Request file name from user */
			printf("Insert file name: ");
			gets(message.data);
			/* Send request to server */
			message.request = CL_SRV_REQUEST_SEND_FILE;
			send(client_fd, &message, sizeof(message), 0);
		}
	}
}

/* Client recieve file data */
void * client_receive_task(void * arg)
{
	int  client_fd 		= *(int *)arg;
	// char fileName[100] 	= "02.client_result_file.txt";
	int  resultFileFd	= 0;

	TRANFER_MESSAGE_ST message = {0};

	while(1)
	{
		/* Receive data from server */
		memset(&message, 0, sizeof(message));
		read(client_fd, &message, sizeof(message));

		switch(message.request)
		{
			case SRV_CL_SEND_FILE_EXIST:
				printf("SRV_CL_SEND_FILE_EXIST\n");
				/* Create result file to write data */
				resultFileFd = open("02.client_result_file.txt", O_RDWR | O_CREAT, 0664);
				break;
			case SRV_CL_SEND_FILE_NOT_EXIST:
				printf("SRV_CL_SEND_FILE_NOT_EXIST\n");
				break;
			case SRV_CL_SEND_FILE_DATA:
				printf("%s", message.data);
				/* Write data buffer to a file */
				if(resultFileFd)
				{
					write(resultFileFd, message.data, strlen(message.data));
				}
				break;
			case SRV_CL_SEND_FILE_END:
				printf("SRV_CL_SEND_FILE_END\n");
				close(resultFileFd);
				break;
			case SRV_CL_SEND_FILE_LIST:
				printf("%s\n", message.data);
				break;
			default:
				break;
		}
	}
}





