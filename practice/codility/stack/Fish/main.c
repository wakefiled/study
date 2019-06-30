// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

void print_array (int A[],int N)
{
    int i = 0;
    
    for(i=0; i < N;i++)
    {
        printf("%d ",A[i]);
    }
    
    return;
}

void eatDownstreamFish(int stack[], int *fish,  int upFish)
{
    int i = 0;
    
    if( *fish == 0 )
    {
        stack[*fish] = upFish;
        *fish = 1;
        return;
    }

    for( i = *fish-1; i >= 0 ; i-- )
    {
        if( stack[i] > 0 )
        {
            stack [++i] = upFish;
            break;
        }
        else
        {
            if( abs(stack[i]) > abs(upFish) )
            {
                break;
            }
            else
            {
                stack[i] = upFish;
                if( i == 0 )
                {
                    *fish = 1;
                    return;
                }
            }
        }
    }

    *fish = i+1;

    return;
}

int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int stack[100000] = {0,};

    int fish_cnt = 0;
    int i = 0;
    
    
    for( i = 0 ; i < N; i++ )
    {
        if ( B[i] == 1 )
        {
            A[i] = -1 * (A[i] + 1);
        }
        else
        {
            A[i] = (A[i] + 1);
        }
    }
    
    for( i = 0 ; i < N; i++ )
    {
        if(A[i] > 0)
        {
            eatDownstreamFish(stack, &fish_cnt,  A[i]);
        }
        else
        {
            stack[fish_cnt] = A[i];
            fish_cnt++;
        }
    }
    
   //print_array(stack,fish_cnt);
    
    return fish_cnt;
}
