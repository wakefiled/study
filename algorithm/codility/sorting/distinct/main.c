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

int main(void)
{
	int A[8] = {6,4,-1,3,500,-4,6,1};
	int N = 8;
	int result = 0;

	result = solution(A,N);
	printf("%d\n", result);
}
