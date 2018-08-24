#include <stdio.h>

int solution(int A[], int N) {
    char cCheckTable[2000001] = {0,};
    int i = 0;
    int value = 0;
    int cnt = 0;
    
    for( i = 0; i < N; i++ )
    {
        value = A[i] + 1000000;
        cCheckTable[value] = 1;
    }
    
    for (i = 0; i < 2000001; i++ )
    {
        if( cCheckTable[i] == 1)
        {
            cnt++;
        }
    }
    
    return cnt;
}
