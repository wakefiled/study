#include <stdlib.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int get_golden_leader(int A[], int N, int * err)
{
    int leader = 0;
    int candidate;
    int * candidateStack = NULL;
    int candidateIndex;
    int i;
    
    candidateStack = (void*)malloc(sizeof(int)*N);
    candidateIndex = 0;
    
    for(i = 0; i < N; i++)
    {
        if(candidateIndex == 0)
        {
            candidateStack[candidateIndex] = A[i];
            candidateIndex++;
        }
        else
        {
            candidate = A[i];
            if (candidateStack[(candidateIndex-1)] != candidate)
            {
                candidateStack[(candidateIndex-1)] = 0;
                candidateIndex--;
            }
            else
            {
                candidateStack[candidateIndex] = candidate;
                candidateIndex++;
            }
        }
    }
    
    if(candidateIndex == 0)
    {
        * err = 1;
    }
    else
    {
        leader = candidateStack[0];
        * err = 0;
    }

    free(candidateStack);

    return leader;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int left_err = 0;
    int right_err = 0;
    int left_leader = 0;
    int right_leader = 0;
    int i = 0;
    int cnt = 0;
    
    for(i = 0; i < N-1; i++)
    {
        left_leader = get_golden_leader(A,i,&left_err);
        if(left_err == 1) continue;
        
        right_leader = get_golden_leader(A,i+1,&right_err);
        if(right_err == 1) continue;
        
        if(left_leader == right_leader)
        {
            cnt ++;
        }
    }

    return cnt;
}
