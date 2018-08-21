#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>

#include <sys/types.h>
#include <sys/time.h>
#include <dirent.h>


#define ROM_DEV0 "./test_rom_log0.txt"
#define ROM_DEV1 "./test_rom_log1.txt"

#define TMP_DEV0 "/tmp/test_ram_log0.txt"
#define TMP_DEV1 "/tmp/test_ram_log1.txt"

int main(void)
{
	FILE* fd_ROM_DEV = 0;
	FILE* fd_TMP_DEV = 0;
	char data[129] = {0,};
	struct timeval tv;
	long long start,end;
	int i = 0;
	
	memset(data,0xaa,128);

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	fd_ROM_DEV= fopen(ROM_DEV0, "w");
	while(i < 10000)
	{
		fwrite(data,sizeof(char),strlen(data),fd_ROM_DEV);
		i++;
	}
	fclose(fd_ROM_DEV);
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	printf("test 01 [%lld ms]\n", end - start);

	i=0;

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	while(i < 10000)
	{
		fd_ROM_DEV= fopen(ROM_DEV1, "w");
		fwrite(data,sizeof(char),strlen(data),fd_ROM_DEV);
		i++;
		fclose(fd_ROM_DEV);
	}
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	printf("test 02 [%lld ms]\n", end - start);

	i=0;

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	fd_TMP_DEV= fopen(TMP_DEV0, "w");
	while(i < 10000)
	{
		fwrite(data,sizeof(char),strlen(data),fd_ROM_DEV);
		i++;
	}
	fclose(fd_TMP_DEV);
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	printf("test 03 [%lld ms]\n", end - start);

	i=0;

	gettimeofday(&tv,NULL);
	start = tv.tv_sec*1000LL + tv.tv_usec/1000;
	while(i < 10000)
	{
		fd_TMP_DEV= fopen(TMP_DEV1, "w");
		fwrite(data,sizeof(char),strlen(data),fd_ROM_DEV);
		i++;
		fclose(fd_TMP_DEV);
	}
	gettimeofday(&tv,NULL);
	end = tv.tv_sec*1000LL + tv.tv_usec/1000;

	printf("test 04 [%lld ms]\n", end - start);

	return 0;
}
