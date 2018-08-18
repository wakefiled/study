#include <stdio.h>
#include <stdarg.h>

#define ENABLE_ERROR_LOG  (1)
#define ENABLE_WARN_LOG   (1)
#define ENABLE_INFO_LOG   (1)
#define ENABLE_DEBUG_LOG  (1)

#define PRINT_BUFFER_SIZE (512)

#define LOG(a, x...)  LOG_API(a, __func__, __LINE__, x)

#define ERROR(x...) \
if(ENABLE_ERROR_LOG) { LOG(LOG_ERROR, x);}\
else{}
#define WARN(x...)  \
if(ENABLE_WARN_LOG){  LOG(LOG_WARN, x);}\
else{}
#define INFO(x...)  \
if(ENABLE_INFO_LOG){ LOG(LOG_INFO, x);}\
else{}
#define DEBUG(x...) \
if(ENABLE_DEBUG_LOG){ LOG(LOG_DEBUG, x);}\
else{}

typedef enum
{
	LOG_ERROR,
	LOG_WARN,
	LOG_INFO,
	LOG_DEBUG
}LOG_TYPE_e;

void LOG_API (LOG_TYPE_e eType, const char * func, int line, const char * fmt, ...)
{
	va_list ap;
	char buf[PRINT_BUFFER_SIZE] = {0,};

	va_start(ap, fmt);
	vsnprintf(buf,PRINT_BUFFER_SIZE, fmt, ap);
	va_end(ap);

	switch( eType )
	{
		case LOG_ERROR:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
		case LOG_WARN:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
		case LOG_INFO:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
		case LOG_DEBUG:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
		default:
			break;
	}

	fflush(stderr);

	return;
}

int main(int argc, char * argv[])
{	
	ERROR("jskim8 error log %d\n", 0);
	WARN("jskim8 warn log %d\n", 0);
	DEBUG("jskim8 debug log %d\n", 0);
	INFO("jskim8 info log %d\n", 0);

	return 0;
}

