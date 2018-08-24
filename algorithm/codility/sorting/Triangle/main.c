#include <stdio.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

void quick_sort(int A[], int left, int right)
{
    int temp = 0;
    int pivot = A[(left+right)/2];
    int L = left, R = right;
    
    while(L <= R)
    {
        while(A[L] > pivot) L++;
        while(A[R] < pivot) R--;
        
        if(L<=R)
        {
            if(L!=R)
            {
                temp = A[L];
                A[L] = A[R];
                A[R] = temp;
            }
            L++; R--;
        }
    }
    
    if(left < R)
        quick_sort(A,left,R);
    if(L < right)
        quick_sort(A,L,right);
}

int isTriangle(long long a, long long b, long long c)
{
    if(( a + b > c ) && ( b + c > a) && ( a + c > b )) return 1;

    return 0;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i = 0;
    
    if( N < 3 ) return 0;
    
    quick_sort(A,0,N-1);
    
    while( (A[i] > 0) && (i < N-2) )
    {
        if( isTriangle((long long)A[i], (long long)A[i+1], (long long)A[i+2]) ) return 1;
        i++;
    }
    
    return 0;
}

int main(void)
{
	int A[] = {1,2,3,4,5,6,7,8,9};
	int N = 10;

	printf("Solution is: %d\n", solution(A,N));

	return 0;
}
