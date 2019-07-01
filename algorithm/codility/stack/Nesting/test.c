// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <string.h>

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int N = strlen(S);
    char buf[1000000] = {0,};
    int buf_index = 0;
    
    int i = 0;
    
    for(i = 0; i < N; i++)
    {
        if(S[i] == '(')
        {
            buf[buf_index] = S[i];
            buf_index++;
        }
        else if(S[i] == ')')
        {
            buf[buf_index] = '\0';
            buf_index--;
            if( buf_index < 0)
            {
                return 0;
            }
        }
    }
    
    if( buf_index != 0 ) return 0;
    
    return 1;
}
