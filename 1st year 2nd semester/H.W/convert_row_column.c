#include <stdio.h>
#define row 4
#define col 4
int main()
{
    int arr[row][col], temp;
    // this use only for input the value from user
    for(int i = 0; i<row; i++)
    {
        for(int j = 0 ; j< col; j++)
           scanf("%d", &arr[i][j]);
    }
    // swap the row to column
    for(int i = 0; i<row; i++)
    {
        for(int j = i ; j< col; j++)
        {  temp = arr[i][j];
           arr[i][j] = arr[j][i];
           arr[j][i] = temp;
        }
    }
    // print the output..
    for(int i = 0; i<row; i++)
    {
        for(int j = 0 ; j< col; j++)
           printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
