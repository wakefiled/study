#include <stdio.h>
#include <string.h>

#include <json-glib/json-glib.h>

#define FILE_NAME_LEN (64)

int main(int argc, char * argv[])
{
	char szFileName[FILE_NAME_LEN] = "./default.json";
	int ret = 0;

	if( argc == 2 )
	{
		printf("%s\n",argv[1]);
		strncpy(szFileName,argv[1],FILE_NAME_LEN);
	}

	return 0;
}


