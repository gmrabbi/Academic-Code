#include <stdio.h>

int GCD(int a , int b)
{
    if(b==0)
        return a;
    else
        return GCD(b , a%b);
}

int main()
{
    int a = 5 , b=35;
    printf("GCD of %d & %d = %d", a, b , GCD(a, b));
    return 0;
}
