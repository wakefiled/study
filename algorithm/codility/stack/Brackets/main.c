// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <string.h>

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int N = strlen(S);
    
    char stack[200000] = {0,};
    int top = 0;
    int i = 0;
    
    for(i = 0; i < N; i++)
    {
        if( (S[i] == '{') || (S[i] == '[') || (S[i] == '('))
        {
             stack[top] = S[i];
             top++;
        }
        else
        {
            if( top == 0 ) return 0;
            if( (S[i] == ')') && (stack[top-1] == '(') )
            {
                stack[top] = '\0';
                top--;
            }
            else if( (S[i] == '}') && (stack[top-1] == '{') )
            {
                stack[top] = '\0';
                top--;   
            }
            else if( (S[i] == ']') && (stack[top-1] == '[') )
            {
                stack[top] = '\0';
                top--;
            }
        }
    }
    
    if ( top == 0 ) return 1;
    return 0;
}
