#include <stdio.h>
#define row 4
#define col 3

int main()
{
    int arr1[row][col], arr2[col][row];
    //input the value from the user
    for(int i = 0; i<row; i++)
    {
        for(int j = 0 ; j<col; j++)
            scanf("%d", &arr1[i][j]);
    }
    // transfer the value
    for(int i = 0; i<col; i++)
    {
        for(int j = 0 ; j<row; j++)
            arr2[i][j] = arr1[j][i];
    }
    //print the new array
    for(int i = 0; i<col; i++)
    {
        for(int j = 0 ; j<row; j++)
            printf("%d ", arr2[i][j]);
        printf("\n");
    }



    return 0;
}
