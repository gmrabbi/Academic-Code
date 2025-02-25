#include <stdio.h>
#include <math.h>

int main()
{
    int n ;
    float sum = 0.0;
    printf("How many number : ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter 10 number : \n");
    for(int i = 0 ; i< n; i++)
        scanf("%f", &arr[i]);

    for(int i = 0 ; i< n; i++)
        sum += (arr[i] * arr[i]);
    printf("%.2f", sum);
    return 0;
}
