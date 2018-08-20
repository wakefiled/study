#include <stdio.h>
#include <string.h>

#include <json-c/json.h>

#define FILE_NAME_LEN (64)

int main(int argc, char * argv[])
{
	json_object * pJsonObject = NULL;
	json_object * pJsonWidgetObject = NULL;
	json_object * pJsonDebugObject = NULL;
	json_object * pJsonWindowObject = NULL;
	json_object * pJsonTitleObject = NULL;
	char szFileName[FILE_NAME_LEN] = "./default.json";
	int ret = 0;

	struct json_object_iterator iter;
	struct json_object_iterator itEnd;

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
	printf("[0]%d\n",json_object_get_type(pJsonObject));
	printf("[0]%s\n",json_object_get_string(pJsonObject));

	pJsonWidgetObject = json_object_object_get(pJsonObject, "widget");
	printf("[1]%d\n",json_object_get_type(pJsonWidgetObject));
	printf("[1]%s\n",json_object_get_string(pJsonWidgetObject));

		
	pJsonDebugObject = json_object_object_get(pJsonWidgetObject, "debug");
	printf("[2]%d\n",json_object_get_type(pJsonDebugObject));
	printf("[2]%s\n",json_object_get_string(pJsonDebugObject));

	pJsonWindowObject = json_object_object_get(pJsonWidgetObject, "window");
	printf("[2]%d\n",json_object_get_type(pJsonWindowObject));
	printf("[2]%s\n",json_object_get_string(pJsonWindowObject));

	pJsonTitleObject = json_object_object_get(pJsonWindowObject, "title");
	printf("[3]%d\n",json_object_get_type(pJsonTitleObject));
	printf("[3]%s\n",json_object_get_string(pJsonTitleObject));

	json_object_object_foreach(pJsonWindowObject, test1, test2)
	{
		printf("[5] %s\n",test1);
		printf("[5] %s\n",json_object_get_string(test2));
	}

	iter  = json_object_iter_begin(pJsonWindowObject);
	itEnd = json_object_iter_end(pJsonWindowObject);
	while(!json_object_iter_equal(&iter, &itEnd))
	{
		json_object * temp = json_object_iter_peek_value(&iter);
		printf("[6] %s\n", json_object_iter_peek_name(&iter));
		printf("[6] %s\n", json_object_get_string(temp));
		printf("[6] %d\n", json_object_get_int(temp));
		printf("[6] %d\n", json_object_get_boolean(temp));
		printf("[6] %f\n", json_object_get_double(temp));
		json_object_iter_next(&iter);
	}

	json_object_put(pJsonObject);
	pJsonObject = NULL;

	return 0;
}


