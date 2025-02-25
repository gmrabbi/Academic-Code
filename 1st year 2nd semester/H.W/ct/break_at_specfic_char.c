#include <stdio.h>
#define num 32

int main()
{
    int n=0, i;
    char c , arr1[num], arr2[num];
    do
    {
        scanf("%c", &c);
        arr1[n++] = c;
    }
    while(c != 'r');
    for(int i = 0 ; i< n-1; i++)
        arr2[i] = arr1[i];
    arr2[i+1] = '\0';
    printf("%d \n%s\n%s",n-1, arr1,arr2);
    return 0;
}
