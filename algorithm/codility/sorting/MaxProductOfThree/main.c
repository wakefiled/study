#include <stdio.h>

void quick_sort(int A[], int left, int right);

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int i = 0;
    int j = 0;
    int result = 0; 

    quick_sort (A,0,N-1);

    if(A[0] > 0)
    {
        i = A[0] * A[1] * A[2];
        j = A[0] * A[N-1] * A[N-2];
        result = (i > j)? i: j;
    }
    else
    {
        result = A[0] * A[1] * A[2];
    }

    return result;
}

void quick_sort(int A[], int left, int right)
{
    int L = left, R = right;
    int temp;
    int pivot = A[(left+right)/2];


    while(L <= R)
    {
        while( A[L] > pivot ) L++;
        while( A[R] < pivot ) R--;

        if( L<= R )
        {
            if (L!=R)
            {
                temp = A[L];
                A[L] = A[R];
                A[R] = temp;
            }
            L++; R--;
        }
    }

    if(left < R)
        quick_sort(A,left, R);
    if(L < right)
        quick_sort(A,L,right);

}

int main(void)
{
//	int A[8] = {1,2,3,4,5,-100,-200,4};
	int A[8] = {6,4,-1,3,500,-4,6,1};
	int result = 0;

	result = solution(A,8);
	printf("%d\n", result);
}

