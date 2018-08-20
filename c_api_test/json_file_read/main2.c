#include <stdio.h>
#include <string.h>

#include <json-c/json.h>

#define FILE_NAME_LEN (64)

int main(int argc, char * argv[])
{
	json_object * pJsonObject = NULL;
	json_object * pJsonCarsObject = NULL;
	array_list * pArrayList = NULL;
	char szFileName[FILE_NAME_LEN] = "./array.json";
	int ret = 0;
	int length = 0;

	if( argc == 2 )
	{
		printf("%s\n",argv[1]);
		strncpy(szFileName,argv[1],FILE_NAME_LEN);
	}

	pJsonObject = json_object_from_file(szFileName);
	if ( pJsonObject == NULL )
	{
		printf("Reading file object is failed.");
		return -1;
	}

	pJsonCarsObject = json_object_object_get(pJsonObject, "cars");
	pArrayList = json_object_get_array(pJsonCarsObject);

	for( length = 0; length < array_list_length(pArrayList); length ++ )
	{
		printf("[%d]%s\n",length,json_object_get_string(array_list_get_idx(pArrayList, length)));
		printf("[%d]%s\n",length,json_object_get_string(json_object_array_get_idx(pJsonCarsObject,length)));
	}

	printf("%s\n", json_object_get_string(pJsonCarsObject));

	json_object_put(pJsonObject);
	pJsonObject = NULL;

	return 0;
}


