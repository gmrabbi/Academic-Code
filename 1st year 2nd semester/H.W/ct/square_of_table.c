#include <stdio.h>
#define num 5

int main()
{

    int  arr[num][num];
    //scanf("%d",&n);
    printf("MULTIPICATION TABLE\n\n");
    printf("    1 2 3 4 5\n--------------\n");
    for(int i =0 ; i<num; i++)
    {
        for(int j = 0 ; j<num ; j++)
            arr[i][j] = (i+1)*(j+1);
    }
    for(int i =0 ; i<num; i++)
    {
        printf("%d | ", i+1);
        for(int j = 0 ; j<num ; j++)
            printf("%d  ", arr[i][j]);
        printf("\n");
    }



    return 0;
}
