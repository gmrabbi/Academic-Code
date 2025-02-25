#include <stdio.h>

int main()
{
    int temp = 0 ,n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i =0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("\n");
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(i==j)
            {
                temp = arr[i][j];
                arr[i][j] = arr[i][n-1-i];
                arr[i][n-1-i] = temp;
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0 ;
}
