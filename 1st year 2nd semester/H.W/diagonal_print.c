#include <stdio.h>
#define row 4
#define col 4
int main()
{
    int arr[row][col];
    // input the value from user
    for(int i = 0 ; i<row; i++)
    {
        for(int j = 0 ; j<col; j++)
            scanf("%d",&arr[i][j]);
    }
    // now print the diagonal value only
    printf("The diagonal is : \n");
    for(int i = 0 ; i<row; i++)
    {
        for(int k= 1 ; k<=i; k++)
                printf(" ");
        
        for(int j = 0 ; j<col; j++)
        {

            if(i==j)
                printf("%d \n", arr[i][j]);
        }
    }


    return 0;
}
