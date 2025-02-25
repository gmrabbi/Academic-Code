#include <stdio.h>

int sum_digit(int n)
{
    if(n == 0 )
        return 0;
    return (n%10)+sum_digit(n/10);
}

int main()
{
    int n = 232;
    printf("Summation of digit : %d", sum_digit(n));
    return 0;
}
