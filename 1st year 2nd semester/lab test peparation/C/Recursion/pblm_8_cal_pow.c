#include <stdio.h>

int power(int n , int p)
{
    if(p == 0)
        return 1;
    return n*power(n , p-1);
}

int main()
{
    int num = 2 , pow=5;
    printf("%d^%d = %d", num , pow , power(num , pow));
    return 0;
}
