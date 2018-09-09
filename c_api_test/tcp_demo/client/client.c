#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_LEN 128

void main(int argc, char * argv[])
{
	int s, n;
	char * haddr;
	struct sockaddr_in server_addr;
	char buf[BUF_LEN+1] ={0,};
	int port_num = 0;

	if( argc!=3 )
	{
		printf("usage: %s ip_address\n",argv[0]);
		return -1;
	}
	haddr = argv[1];
	port_num = atoi(argv[2]);

	if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("can't create socket\n");
		return -1;
	}

	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(port_num);

	if(connect(s,(struct sockaddr *)&server_addr, sizeof(server_addr)))
	{
		printf("can't connect.\n");
		return -1;
	}

	while((n = read(s, buf, BUF_LEN)) > 0)
	{
		buf[n] = NULL;
		printf("%s",buf);
	}

	close(s);

	return 0;
}
