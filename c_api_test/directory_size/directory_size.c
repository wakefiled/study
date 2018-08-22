
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int sizePathFun(char *path){
             struct stat stbuf;
 
             if(stat(path, &stbuf) == -1)
                           return -1;
             return stbuf.st_size;
 
}
void pathNnameJoin(char *path, char *fileName, char * output){
	if( NULL == output )
	{
		return;
	}

	snprintf(output,1000,"%s/%s",path,fileName);
	output[1000-1] = '\0';
	return;
}

int isDir(char *path){
             struct stat statbuf;
             int len = strlen(path);
 
             if(path[len-3] == '/' && path[len-2] == '.' && path[len-1] == '.')
                           return 0;
             if(path[len-2] == '/' && path[len-1] == '.')
                           return 0;
            
             if (stat(path, &statbuf) == -1)
                           return 0;
             else
                           return S_ISDIR(statbuf.st_mode);
}

int isRegularFile(char *path){
             struct stat statbuf;
 
             if (stat(path, &statbuf) == -1)
                           return 0;
             else
                           return S_ISREG(statbuf.st_mode);
             return 0;
}

int depthApply( char * pPath )
{
	struct dirent *pNode;
	DIR *pDir;
	char fullName[1000] = {0,};
	long long size = 0, total = 0;
	
	if( NULL == (pDir = opendir(pPath)) )
	{
		perror("Failed to open directory");
		return -1;
	}

	while( NULL != (pNode = readdir(pDir))	)
	{
		pathNnameJoin(pPath,pNode->d_name,fullName); 
		if(isDir(fullName))
		{
			depthApply(fullName);
		}
		else if(isRegularFile(fullName))
		{
			if (  -1 == (size = sizePathFun(fullName)) )
			{
				printf("Error Can't get file size: %s\n", fullName);
			}
			else
			{
				total += size;
			}
		}
	}
	
	while( (-1 == closedir(pDir)) && (errno == EINTR)  );
	printf("%lld    :%s\n", total, pPath);
}

int main(int argc, char *argv[])
{
	char * pPath = 0;
	pPath = argv[1];
	depthApply(pPath);

	return 0;
}

