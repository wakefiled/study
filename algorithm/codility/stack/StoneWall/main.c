// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int H[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int stack[100000] = {0,};
    int i = 0;
    int top = 0;
    int blockCnt = 0;
    
    for( i = 0; i < N; i++ )
    {
        while( (top > 0) && ( stack[top-1] > H[i] ))
        {
            stack[top] = 0;
            top--;
        }
        
        if (top == 0)
        {
            stack[top] = H[i];
            top++;
            blockCnt++;
        }
        else if(stack[top-1] < H[i])
        {
            stack[top] = H[i];
            top++;    
            blockCnt++;
        }
    }
    
    return  blockCnt;
}