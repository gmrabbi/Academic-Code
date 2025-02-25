#include <stdio.h>
#define row 4
#define col 4

int main()
{
    int arr1[row][col], arr2[row][col];
    for(int k = 1; k<=2; k++)
    {
        printf("Enter the of %dst array: \n", k);
        for(int i=0; i<row; i++)
        {
            for(int j = 0 ; j<col; j++)
            {
                if(k==1)
                    scanf("%d", &arr1[i][j]);
                else
                    scanf("%d", &arr2[i][j]);
            }
        }
    }
    printf("\nThe Multiplication of two array is : \n");
    for(int i = 0 ; i<row; i++)
    {
        for(int j = 0 ; j<col; j++)
            printf("%d ",(arr2[i][j])*(arr2[i][j]));
        printf("\n");
    }


    return 0;
}
