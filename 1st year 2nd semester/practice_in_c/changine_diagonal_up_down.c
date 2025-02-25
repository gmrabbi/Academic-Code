#include <stdio.h>

int main()
{
    int n , temp=0;
    printf("Enter row number : ");
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0 ; i<n ; i++)
    {
        for(int j=0 ; j<n; j++)
            scanf("%d", &arr[i][j]);
    }
    //printf("%d", n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n; j++)
            {
                //printf("%d %d\n",i , j);
                if(i==j)
                {
                    temp = arr[i][i];
                    arr[i][i] = arr[i][n-i-1];
                    arr[i][n-i-1] = temp;
                    //printf("%d-%d \n", i , n-i-1);
                }
                //else
                 //   printf("Don't working..\n");
            }
    }
    printf("\n\n");
    for(int i = 0 ; i<n ; i++)
    {
        for(int j=0 ; j<n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}
