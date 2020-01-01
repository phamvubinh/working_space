#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>  	/* sockaddr, sa_family_t, socklen_t */
#include <netinet/in.h>		/* in_port_t, in_addr_t, sa_family_t, sockaddr_in */

#include <pthread.h>

#include "02.data_transfer.h"

#include <fcntl.h>			/* File open option */
#include <dirent.h>    		/* This file to use readdir function */

#define PORT 8081

int  socket_init(int *accept_fd);
void *server_control_task(void * arg);
void server_list_file_send(int accept_fd);
void server_data_file_send(int accept_fd, char* file_name);

static int private_sever_data_file_send(int accept_fd, char* file_name);

int main(int argc, char const *argv[])
{
	/* Define variable to manage socket */
	int accept_fd 	= 0;
	int result = 0;

	pthread_t thread = 0;

	printf("accept_fd: %d\n", accept_fd);
	/* Init socket and get a fd to read and write file */
	result = socket_init(&accept_fd);
	if(result < 0)
	{
		return -1;
	}

	printf("accept_fd before thread create: %d\n", accept_fd);

	/* Create task to receive request and send file data */
	pthread_create(&thread, NULL, server_control_task, (void *)&accept_fd);
	pthread_join(thread, NULL);

	return 0;
}

int socket_init(int *accept_fd)
{
	/* Define variable to manage socket */
	int socket_fd = 0;
	struct sockaddr_in address;
	int addrlen = sizeof(address);

	/* Creating socket file descriptor  */
	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		printf("Socket create failed\n");
		return -1;
	}

	/* Set address to bind from server */
	address.sin_family		= AF_INET;
	address.sin_addr.s_addr	= INADDR_ANY;
	address.sin_port		= htons(PORT);

	/* Bind the socket to port 8080 */
	if(bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		printf("Bind socket failed\n");
		return -1;
	}

	printf("Listen to client connect\n");
	/* Listen for the connection from client */
	if(listen(socket_fd, 3) < 0)
	{
		printf("Listen failed\n");
		return -1;
	}

	/* Accept the connection */
	if((*accept_fd = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
	{
		printf("Accept failed\n");
		return -1;
	}

	printf("accept_fd value: %d\n", *accept_fd);
	return 0;
}

/* Server proccessing center */
void * server_control_task(void * arg)
{
	int accept_fd = * (int *)arg;
	TRANFER_MESSAGE_ST message = {0};

	printf("accept_fd: %d\n", accept_fd);

	while(1)
	{
		/* Receive request from client */
		memset(&message, 0, sizeof(message));
		read(accept_fd, &message, sizeof(message));

		switch(message.request)
		{
			case CL_SRV_REQUEST_SEND_FILE:
				printf("Client request send file: %s\n", message.data);
				server_data_file_send(accept_fd, message.data);
				break;
			case CL_SRV_REQUEST_FILE_LIST:
				printf("Client request file list\n");
				server_list_file_send(accept_fd);
				break;
			default:
				break;
		}
	}
}

void server_list_file_send(int accept_fd)
{
	TRANFER_MESSAGE_ST message = {0};

	/*Get file list to send to client */
	DIR *dir = NULL;
	/* Pointer to directiry entry */
	struct dirent *de;

	/* Open current dir */
	dir = opendir(".");

	/* Read current dir to get all file name */
	while((de = readdir(dir)) != NULL)
	{
		/* Ignore hidden file */
		if(de->d_name[0] != '.')
		{
			/*printf("%s\n", de->d_name);*/
			memset(&message, 0, sizeof(message));

			/* Copy file name to message data */
			snprintf(message.data, strlen(de->d_name) + 1, "%s", de->d_name);

			/* Send message to client */
			message.request = SRV_CL_SEND_FILE_LIST;
			send(accept_fd, &message, sizeof(message), 0);
		}
	}
	closedir(dir);
}

void server_data_file_send(int accept_fd, char *file_name)
{
	TRANFER_MESSAGE_ST message = {0};

	/*Get file list to send to client */
	DIR *dir = NULL;
	/* Pointer to directiry entry */
	struct dirent *de;

	/* Open current dir */
	dir = opendir(".");

	/* Read current dir to get all file name */
	while((de = readdir(dir)) != NULL)
	{
		/* Ignore hidden file */
		if(de->d_name[0] != '.')
		{
			/* If file exist */
			if(strncmp(de->d_name, file_name, strlen(file_name)) == 0)
			{
				/* Send file exist to client */
				message.request = SRV_CL_SEND_FILE_EXIST;
				send(accept_fd, &message, sizeof(message), 0);
				/* Send file data to client */
				private_sever_data_file_send(accept_fd, file_name);
				closedir(dir);
				return;
			}
		}
	}
	/* Send message to client */
	message.request = SRV_CL_SEND_FILE_NOT_EXIST;
	send(accept_fd, &message, sizeof(message), 0);
	return;
}


static int private_sever_data_file_send(int accept_fd, char* file_name)
{
	int fd = 0;

	/* Character variable to read file */
	char c = 0;
	/* Buffer to store data to save sending time */
	char buff[128] = {0};

	/* Index to manage the buffer status */
	unsigned int index = 0;


	TRANFER_MESSAGE_ST message = {0};

	fd = open(file_name, O_RDONLY);
	if(fd < 0)
	{
		printf("Open file failed\n");
		return -1;
	}

	/* Loop to read all data file */
	while(read(fd, &c, 1) != 0)
	{
		/* Read data byte one by one, if not EOF push data to buffer */
		buff[index] = c;
		index++;

		if(index == sizeof(buff))
		{
			memset(message.data, 0, sizeof(message.data));
			memcpy(message.data, buff, sizeof(buff));

			message.request = SRV_CL_SEND_FILE_DATA;
			send(accept_fd, &message, sizeof(message), 0);
			index = 0;
		}
	}
	/* Finish the loop and data not full the buff */
	if((0 < index) && (index < sizeof(buff)))
	{
		memset(message.data, 0, sizeof(message.data));
		memcpy(message.data, buff, index);

		message.request = SRV_CL_SEND_FILE_DATA;
		send(accept_fd, &message, sizeof(message), 0);
		index = 0;
	}
	message.request = SRV_CL_SEND_FILE_END;
	send(accept_fd, &message, sizeof(message), 0);

	close(fd);
	return 0;
}
