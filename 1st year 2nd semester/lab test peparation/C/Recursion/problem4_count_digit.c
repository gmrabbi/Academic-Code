#include <stdio.h>

int counter(int n)
{
    if(n==0)
        return 0;
    return 1+counter(n/10);
}

int main()
{
    int n = 32412;
    printf("Total digit : %d\n", counter(n));
    return 0;
}
