// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
void quick_sort(long long A[], int left, int right)
{
    int L = left, R = right;
    long long temp = 0;
    long long pivot = A[(left+right)/2];


    while(L <= R)
    {
        while( A[L] < pivot ) L++;
        while( A[R] > pivot ) R--;

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

    if(left < R) quick_sort(A,left, R);
    if(L < right) quick_sort(A,L,right);

}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    long long left_array[100000];
    long long right_array[100000];

    int lindex = 0;
    int rindex = 0;
    int result = 0;
    int current = 0;
 
    long long i = 0;
 
    for( i=0; i < N; i++ )
    {
        left_array[i] = i - A[i];
        right_array[i] = i + A[i];
    }
    
    quick_sort(left_array,0,N-1);
    quick_sort(right_array,0,N-1);
    
    for(i=0; i<N; i++)
    {
        while( lindex < N && left_array[lindex] <= right_array[rindex] )
        {
            current++;
            lindex ++;
        }
        current--;
        result += current;
        rindex ++;

        if (result > 10000000) return -1;
    }
    
    return result;
}
