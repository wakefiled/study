#include <stdio.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/xmlreader.h>

#define FILE_NAME_LEN (64)

static void processNode(xmlTextReaderPtr pReader)
{
	xmlChar * name = NULL;
	xmlChar * value = NULL;

	name = xmlTextReaderName(pReader);
	if ( name == NULL )
	{
		name = xmlStrdup(BAD_CAST "--");
	}
	value = xmlTextReaderValue(pReader);

	printf("%d %d %s %d",
		xmlTextReaderDepth(pReader),
		xmlTextReaderNodeType(pReader),
		name,
		xmlTextReaderIsEmptyElement(pReader));

	xmlFree(name);

	if(value == NULL)
	{
		printf("\n");
	}
	else
	{
		printf(" %s\n",value);
		xmlFree(value);
	}
}

int main(int argc, char * argv[])
{
	char szFileName[FILE_NAME_LEN] = "./default.xml";
	xmlTextReaderPtr pReader = NULL;
	xmlChar * name = NULL;
	xmlChar * value = NULL;
	int ret = 0;

	if( argc == 2 )
	{
		printf("%s\n",argv[1]);
		strncpy(szFileName,argv[1],FILE_NAME_LEN);
	}

	pReader = xmlNewTextReaderFilename(szFileName);
	if(pReader == NULL)
	{
		printf("XML Open is failed\n");
		return -1;
	}

	ret = xmlTextReaderRead(pReader);
	while( ret == 1)
	{
		processNode(pReader);
		ret = xmlTextReaderRead(pReader);
	}

	xmlFreeTextReader(pReader);
	return 0;
}


