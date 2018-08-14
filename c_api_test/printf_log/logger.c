#include <stdio.h>
#include <stdarg.h>

#define ENABLE_ERROR_LOG  (1)
#define ENABLE_WARN_LOG   (1)
#define ENABLE_INFO_LOG   (1)
#define ENABLE_DEBUG_LOG  (1)

#define PRINT_BUFFER_SIZE (512)

#define LOG(a, x...)  LOG_API(a, __func__, __LINE__, x)

#define ERROR(x...)   LOG(LOG_ERROR, x)
#define WARN(x...)    LOG(LOG_WARN, x)
#define INFO(x...)    LOG(LOG_INFO, x)
#define DEBUG(x...)   LOG(LOG_DEBUG, x)

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
#if ENABLE_ERROR_LOG
		case LOG_ERROR:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
#endif
#if ENABLE_WARN_LOG
		case LOG_WARN:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
#endif
#if ENABLE_INFO_LOG
		case LOG_INFO:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
#endif
#if ENABLE_DEBUG_LOG
		case LOG_DEBUG:
			fprintf(stderr, "[%s:%d]%s\n", func, line ,buf);	
			break;
#endif
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

