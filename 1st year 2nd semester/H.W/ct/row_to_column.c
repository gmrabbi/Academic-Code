#include <stdio.h>
#define row 5
#define col 4

int main()
{
    int n , arr[row][col], arr2[col][row];
    for(int i =0 ; i<row; i++)
    {
        for(int j = 0 ; j<col ; j++)
            scanf("%d", &arr[i][j]);
    }
    for(int i =0 ; i<col; i++)
    {
        for(int j = 0 ; j<row ; j++)
            arr2[i][j] = arr[j][i];
    }
    printf("\n");
    for(int i =0 ; i<col; i++)
    {
        for(int j = 0 ; j<row ; j++)
        {
            printf("%d  ", arr2[i][j]);
            //for(int k=1 ; k<= i+1; k++) printf(" ");
            //if(i==j) printf("%d", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}

