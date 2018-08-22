#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>

#include <sys/types.h>
#include <sys/time.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>


#define ROM_DEV0 "./test_rom_log0.txt"
#define ROM_DEV1 "./test_rom_log1.txt"

#define RAM_DEV0 "/tmp/test_ram_log0.txt"
#define RAM_DEV1 "/tmp/test_ram_log1.txt"

long long fd_open_is_one (const char * szFileName)
{
	int fd_DEV = 0;
	char data[129] = {0,};
	struct timeval tv;
	long long start,end;
	int i = 0;

	memset(data,0xaa,128);

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	fd_DEV = open(szFileName, O_WRONLY | O_CREAT, 0644);
	while(i < 10000)
	{
		write(fd_DEV, data, strlen(data));
		i++;
	}
	close(fd_DEV);
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	return (end-start);
}

long long fd_open_are_n (const char * szFileName)
{
	int fd_DEV = 0;
	char data[129] = {0,};
	struct timeval tv;
	long long start,end;
	int i = 0;

	memset(data,0xaa,128);

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	while(i < 10000)
	{
		fd_DEV = open(szFileName, O_WRONLY | O_CREAT, 0644);
		write(fd_DEV, data, strlen(data));
		i++;
		close(fd_DEV);
	}
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	return (end-start);
}

int main(void)
{
	long long lldRunTime= 0;

	lldRunTime = fd_open_is_one(ROM_DEV0);	
	printf("test 01 [%lld ms]\n", lldRunTime);

	lldRunTime = fd_open_are_n(ROM_DEV1);
	printf("test 02 [%lld ms]\n", lldRunTime);

	lldRunTime = fd_open_is_one(RAM_DEV0);
	printf("test 03 [%lld ms]\n", lldRunTime);

	lldRunTime = fd_open_are_n(RAM_DEV1);
	printf("test 04 [%lld ms]\n", lldRunTime);

	return 0;
}
