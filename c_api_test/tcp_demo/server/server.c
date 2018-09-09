#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_LEN 128

int main(int argc, char * argv[])
{
	char buffer[BUF_LEN] = {0,};
	struct sockaddr_in server_addr, client_addr;
	char temp[20] = {0,};
	int server_fd, client_fd;
	int len, msg_size;



	if( argc != 2 )
	{
		printf("usage: %s [port]\n", argv[0]);
		return -1;
	}

	// create socket !!
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == -1)
	{
		printf("Server: Can't open stream socket\n");
		return -1;
	}

	// Initialize server_addr structure
	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
	{
		printf("Server: Can't bind local address.\n");
		return -1;
	}

	if(listen(server_fd,5) < 0)
	{
		printf("Server: Can't listening connection.\n");
		return -1;
	}

	printf("Server: waiting connection request.\n");
	len = sizeof(client_addr);
	while(1)
	{
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
		if(client_fd < 0)
		{
			printf("Server: accept failed.\n");
			return -1;
		}

		inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
		printf("Server: %s client connected.\n",temp);

		msg_size = read(client_fd, buffer, 1024);
		write(client_fd,buffer,msg_size);
		close(client_fd);
		printf("Server: %s client closed.\n",temp);
	}
	close(server_fd);
	return 0;
}
