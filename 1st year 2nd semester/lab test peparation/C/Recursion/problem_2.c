//natural number summation
#include <stdio.h>

int sum(int n)
{
    if(n ==0)
        return 0;
    return n+sum(n-1);
}

int main()
{
    int n = 100;
    printf("Summation is : %d", sum(n));
    return 0;
}
